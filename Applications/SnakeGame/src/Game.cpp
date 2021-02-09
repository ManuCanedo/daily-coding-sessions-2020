#include "Game.h"

Game::Game()
{
	vGameObjects.reserve(10);
	tv = olc::TileTransformedView({ ScreenWidth(), ScreenHeight() }, { 32, 32 });
	sAppName = "Snake";
}

bool Game::OnUserCreate()
{
	vGameObjects.push_back(std::make_unique<Platform>(Platform({ 14.0f, 20.0f }, { 5.0f, 1.0f })));
	vGameObjects.push_back(std::make_unique<Ball>(Ball({ 15.0f, 12.0f }, 0.5f)));
	Ball::p_Ball = (Ball*)vGameObjects.back().get();

	tv.ZoomAtScreenPos(0.25f, olc::vf2d(-1.0f, -1.0f));

	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	// Handle Input
	if (Ball::p_Ball != nullptr && Ball::p_Ball->bOutOfBounds)
		GameOver();
	
	HandleInput();
	
	// Update GameObjects
	UpdateWorld(fElapsedTime);

	// Draw GameObjects
	RenderFrame();

	return true;
}

void Game::GameOver()
{
	GameObject::SetLevel({
		"################################"
		"#..............................#"
		"#...####.####.##.##.####.......#"
		"#...#....#..#.#.#.#.#..........#"
		"#...#.##.####.#...#.###........#"
		"#...#..#.#..#.#...#.#..........#"
		"#...####.#..#.#...#.####.......#"
		"#..............................#"
		"#..............................#"
		"#.....####.#....#.####.###.....#"
		"#.....#..#..#..#..#....#..#....#"
		"#.....#..#..#..#..###..###.....#"
		"#.....#..#...##...#....#.#.....#"
		"#.....####........####.#..#....#"
		"#..............................#"
		"#..............................#"
		"#..............................#"
		"#..............................#"
		"#..............................#"
		"#..............................#"
		"#..............................#"
		"#..............................#"
		"#..............................#"
		"################################" });

	vGameObjects.resize(1);
	Ball::p_Ball = nullptr;
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

	if (Ball::p_Ball == nullptr && GetKey(olc::Key::SPACE).bPressed)
	{
		vGameObjects.push_back(std::make_unique<Ball>(Ball({ 15.0f, 12.0f }, 0.5f)));	
		Ball::p_Ball = (Ball*)vGameObjects.back().get();
		
		GameObject::SetLevel({
			"################################"
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
			"#..............................#"
			"#..............................#"
			"#..............................#"
			"#..............................#"
			"#..............................#"
			"#..............................#"
			"#..............................#"
			"#..............................#"
			"#..............................#"
			"################################" });
	}
}

inline void Game::UpdateWorld(float fElapsedTime)
{
	for (auto rIt = vGameObjects.rbegin(); rIt != vGameObjects.rend(); ++rIt)
		(*rIt)->Update(fElapsedTime);
}

inline void Game::RenderFrame()
{
	Clear(olc::GREY);

	olc::vi2d vTL = tv.GetTopLeftTile().max({ 0,0 });
	olc::vi2d vBR = tv.GetBottomRightTile().min(GameObject::GetMapSize());
	olc::vi2d vTile;

	for (vTile.y = vTL.y; vTile.y < vBR.y; vTile.y++)
		for (vTile.x = vTL.x; vTile.x < vBR.x; vTile.x++)
		{
			switch (GameObject::GetMap()[vTile.y * GameObject::GetMapSize().x + vTile.x])
			{
			case '#':
				tv.FillRect(vTile, { 1.0f, 1.0f }, olc::VERY_DARK_GREY);
				break;
			case '3':
				tv.FillRect(vTile, { 1.0f, 1.0f }, olc::VERY_DARK_BLUE);
				break;
			case '2':
				tv.FillRect(vTile, { 1.0f, 1.0f }, olc::DARK_BLUE);
				break;
			case '1':
				tv.FillRect(vTile, { 1.0f, 1.0f }, olc::BLUE);
				break;
			default:
				break;
			}
		}

	for (auto& obj : vGameObjects)
		obj->Draw(tv);
}

// Entry point
int main()
{
	std::unique_ptr<Game> game = std::make_unique<Game>();

	if (game->Construct(288, 224, 4, 4))
		game->Start();

	return 0;
}
