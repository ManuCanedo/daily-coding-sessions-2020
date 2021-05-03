#include "Game.h"

Game::Game() : audio()
{
	vGameObjects.reserve(10);
	tv = olc::TileTransformedView({ ScreenWidth(), ScreenHeight() }, { 32, 32 });
	sAppName = "Arcade Blocks";
}

bool Game::OnUserCreate()
{
	const olc::vf2d platformInitPos{ 14.0f, 20.0f };
	const olc::vf2d platformInitSize{ 7.0f, 1.0f };

	vGameObjects.push_back(
		std::make_unique<Platform>(Platform(platformInitPos, platformInitSize)));
	tv.ZoomAtScreenPos(0.25f, { 0, 0 });

	LoadAudio(platformInitPos);
	LoadLevel(Level::MENU);
	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	// Check Game Over
	if (Ball::s_Ball != nullptr && Ball::s_Ball->IsOutOfBounds())
		LoadLevel(Level::GAMEOVER);

	// Handle Input
	HandleInput();

	// Update GameObjects
	UpdateWorld(fElapsedTime);

	// Draw GameObjects
	RenderFrame();

	return true;
}

void Game::LoadAudio(const olc::vf2d& listenerPos)
{
	// Audio Initialization
	audio.SetMasterVol(1.0f);
	audio.SetSongsVol(0.6f);
	audio.SetSFXsVol(1.0f);

	// Set Reverb
	FMOD_VECTOR posReverb = { listenerPos.x, listenerPos.y, 0.0f };
	FMOD_REVERB_PROPERTIES props = FMOD_PRESET_CONCERTHALL;
	audio.SetReverb(props, posReverb);

	// Load Music and SFX
	audio.LoadSong("media/song/song_dylan.ogg");
	audio.LoadSFX("media/sfx/block_destroyed.ogg");
	audio.LoadSFX("media/sfx/block_bounce.ogg");
}

void Game::LoadLevel(const Level& level)
{
	constexpr float gameMusicVolume = 0.3f;
	constexpr float gameOverMusicVolume = 0.6f;

	switch (level) {
	case Level::MENU:
		audio.PlaySong("media/song/song_dylan.ogg");
		GameObject::SetLevel(s_sMenu);
		break;
	case Level::LEVEL1:
		audio.SetSongsVol(gameMusicVolume);
		if (Ball::s_Ball == nullptr) {
			vGameObjects.push_back(
				std::make_unique<Ball>(Ball({ 16.0f, 10.0f }, 0.5f)));
			Ball::s_Ball = static_cast<Ball*>(vGameObjects.back().get());
			GameObject::SetLevel(s_sLevel1);
		}
		break;
	case Level::GAMEOVER:
		audio.SetSongsVol(gameOverMusicVolume);
		GameObject::SetLevel(s_sGameOver);
		vGameObjects.resize(1);
		Ball::s_Ball = nullptr;
		break;
	default:
		break;
	}
}

inline void Game::HandleInput()
{
	constexpr float platformVel = 15.0f;

	// Handle Platform controls
	if (GetKey(olc::Key::LEFT).bHeld || GetKey(olc::Key::A).bHeld)
		vGameObjects[0]->vVel = { -platformVel, 0.0f };
	if (GetKey(olc::Key::RIGHT).bHeld || GetKey(olc::Key::D).bHeld)
		vGameObjects[0]->vVel = { +platformVel, 0.0f };
	if (GetKey(olc::Key::LEFT).bReleased || GetKey(olc::Key::A).bReleased)
		vGameObjects[0]->vVel = { 0.0f, 0.0f };
	if (GetKey(olc::Key::RIGHT).bReleased || GetKey(olc::Key::D).bReleased)
		vGameObjects[0]->vVel = { 0.0f, 0.0f };

	// Handle Space to Play
	if (Ball::s_Ball == nullptr && GetKey(olc::Key::SPACE).bPressed)
		LoadLevel(Level::LEVEL1);
}

inline void Game::UpdateWorld(float fElapsedTime)
{
	for (auto rIt = vGameObjects.rbegin(); rIt != vGameObjects.rend(); ++rIt)
		(*rIt)->Update(fElapsedTime, audio);
	audio.Update(fElapsedTime);
}

inline void Game::RenderFrame()
{
	// Clear Screen
	Clear(olc::WHITE);

	if (Ball::s_Ball == nullptr)
		DrawString({ 16, 128 }, "Press START to play", olc::BLACK);

	// Draw Map
	const olc::Pixel wallColour(181, 167, 235);
	const olc::Pixel hardBlockColour(128, 128, 128);
	const olc::Pixel mediumBlockColour(187, 187, 187);
	const olc::Pixel softBlockColour(227, 227, 227);

	const olc::vi2d vTL = tv.GetTopLeftTile().max({ 0, 0 });
	const olc::vi2d vBR = tv.GetBottomRightTile().min(GameObject::GetMapSize());
	olc::vi2d vTile;

	for (vTile.y = vTL.y; vTile.y < vBR.y; vTile.y++)
		for (vTile.x = vTL.x; vTile.x < vBR.x; vTile.x++) {
			switch (GameObject::GetMap()[vTile.y * GameObject::GetMapSize().x +
						     vTile.x]) {
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
	for (const auto& obj : vGameObjects)
		obj->Draw(tv);
}

const std::string Game::s_sMenu{ "################################"
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

const std::string Game::s_sLevel1{ "################################"
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

const std::string Game::s_sGameOver{ "################################"
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
