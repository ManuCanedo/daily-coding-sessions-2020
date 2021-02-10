#include "Game.h"

Game::Game()
{
	vGameObjects.reserve(10);
	vGameObjects.push_back(std::make_unique<Platform>(Platform({ 14.0f, 20.0f }, { 10.0f, 1.0f })));
	tv = olc::TileTransformedView({ ScreenWidth(), ScreenHeight() }, { 32, 32 });
	sAppName = "Arcade Blocks";
}

bool Game::OnUserCreate()
{
	LoadLevel(Level::MENU);
	tv.ZoomAtScreenPos(0.25f, { 0, 0 });
	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	// Check if player lost
	if (Ball::p_Ball != nullptr && Ball::p_Ball->bOutOfBounds)
		LoadLevel(Level::GAMEOVER);

	// Handle Input
	HandleInput();

	// Update GameObjects
	UpdateWorld(fElapsedTime);

	// Draw GameObjects
	RenderFrame();

	return true;
}

void Game::LoadLevel(Level level)
{
	switch (level)
	{
	case Level::MENU:
		GameObject::SetLevel(s_sMenu);
		break;
	case Level::LEVEL1:
		if (Ball::p_Ball == nullptr)
		{
			GameObject::SetLevel(s_sLevel1);
			vGameObjects.push_back(std::make_unique<Ball>(Ball({ 16.0f, 10.0f }, 0.5f)));
			Ball::p_Ball = (Ball*)vGameObjects.back().get();
		}
		break;
	case Level::GAMEOVER:
		GameObject::SetLevel(s_sGameOver);
		vGameObjects.resize(1);
		Ball::p_Ball = nullptr;
		break;
	default:
		break;
	}
}

inline void Game::HandleInput()
{
	// Handle Pan
	if (GetMouse(2).bPressed) tv.StartPan(GetMousePos());
	if (GetMouse(2).bHeld) tv.UpdatePan(GetMousePos());
	if (GetMouse(2).bReleased) tv.EndPan(GetMousePos());
	if (GetMouseWheel() > 0) tv.ZoomAtScreenPos(1.2f, GetMousePos());
	if (GetMouseWheel() < 0) tv.ZoomAtScreenPos(0.8f, GetMousePos());

	// Handle Platform controls
	if (GetKey(olc::Key::LEFT).bHeld || GetKey(olc::Key::A).bHeld) 
		vGameObjects[0]->vVel = { -15.0f, 0.0f };
	if (GetKey(olc::Key::RIGHT).bHeld || GetKey(olc::Key::D).bHeld) 
		vGameObjects[0]->vVel = { +15.0f, 0.0f };
	if (GetKey(olc::Key::LEFT).bReleased || GetKey(olc::Key::A).bReleased)
		vGameObjects[0]->vVel = { 0.0f, 0.0f };
	if (GetKey(olc::Key::RIGHT).bReleased || GetKey(olc::Key::D).bReleased)
		vGameObjects[0]->vVel = { 0.0f, 0.0f };

	// Handle Space to Play
	if (Ball::p_Ball == nullptr && GetKey(olc::Key::SPACE).bPressed)
		LoadLevel(Level::LEVEL1);
}

inline void Game::UpdateWorld(float fElapsedTime)
{
	for (auto rIt = vGameObjects.rbegin(); rIt != vGameObjects.rend(); ++rIt)
		(*rIt)->Update(fElapsedTime);
}

inline void Game::RenderFrame()
{
	// Block Colouring
	static const olc::Pixel wallColour(181, 167, 235);
	static const olc::Pixel hardBlockColour(128, 128, 128);
	static const olc::Pixel mediumBlockColour(187, 187, 187);
	static const olc::Pixel softBlockColour(227, 227, 227);

	// Clear Screen
	Clear(olc::WHITE);

	if (Ball::p_Ball == nullptr)
		DrawString({ 16, 128 }, "Press START to play", olc::BLACK);

	// Draw Map
	olc::vi2d vTL = tv.GetTopLeftTile().max({ 0,0 });
	olc::vi2d vBR = tv.GetBottomRightTile().min(GameObject::GetMapSize());
	olc::vi2d vTile;

	for (vTile.y = vTL.y; vTile.y < vBR.y; vTile.y++)
		for (vTile.x = vTL.x; vTile.x < vBR.x; vTile.x++)
		{
			switch (GameObject::GetMap()[vTile.y * GameObject::GetMapSize().x + vTile.x])
			{
			case '#':
				tv.FillRect(vTile, { 1.0f, 1.0f }, wallColour);
				break;
			case '3':
				tv.FillRect(vTile, { 1.0f, 1.0f }, hardBlockColour);
				break;
			case '2':
				tv.FillRect(vTile, { 1.0f, 1.0f }, mediumBlockColour);
				break;
			case '1':
				tv.FillRect(vTile, { 1.0f, 1.0f }, softBlockColour);
				break;
			default:
				break;
			}
		}

	// Draw Game Objects
	for (auto& obj : vGameObjects)
		obj->Draw(tv);
}

const std::string Game::s_sMenu{
	"################################"
	"#..............................#"
	"#.####.###..###.####.###..####.#"
	"#.#..#.#..#.#...#..#.#..#.#....#"
	"#.####.###..#...####.#..#.###..#"
	"#.#..#.#.#..#...#..#.#..#.#....#"
	"#.#..#.#..#.###.#..#.###..####.#"
	"#..............................#"
	"#..............................#"
	"#.###..#...####.####.#..#.####.#"
	"#.#..#.#...#..#.#....#.#..#....#"
	"#.#.#..#...#..#.#....##...####.#"
	"#.#..#.#...#..#.#....#.#.....#.#"
	"#.###..###.####.####.#..#.####.#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"################################" };

const std::string Game::s_sLevel1{
	"################################"
	"#..............................#"
	"#..............................#"
	"#......3333322132333333........#"
	"#......3333233332333333........#"
	"#..1111111111111...............#"
	"#..1111111111111...............#"
	"#..............................#"
	"#..............................#"
	"#..............3333333333333...#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"################################" };

const std::string Game::s_sGameOver{
	"################################"
	"#..............................#"
	"#....####.####.##.##.####......#"
	"#....#....#..#.#.#.#.#.........#"
	"#....#.##.####.#...#.###.......#"
	"#....#..#.#..#.#...#.#.........#"
	"#....####.#..#.#...#.####......#"
	"#..............................#"
	"#..............................#"
	"#....####.#....#.####.###......#"
	"#....#..#..#..#..#....#..#.....#"
	"#....#..#..#..#..###..###......#"
	"#....#..#...##...#....#.#......#"
	"#....####........####.#..#.....#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"#..............................#"
	"################################" };


// Entry point
int main()
{
	#if defined(_WIN32)
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	#endif

	std::unique_ptr<Game> game = std::make_unique<Game>();

	if (game->Construct(256, 192, 6, 6))
		game->Start();

	return 0;
}
