#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#define OLC_PGEX_TRANSFORMEDVIEW
#include "olcPGEX_TransformedView.h"

#ifndef GAME_H_
#define GAME_H_

#include <Windows.h>
#include <string>
#include <memory>


#include "GameObject.h"
#include "AudioManager.h"


// Game Class
class Game : public olc::PixelGameEngine
{
public:
	Game();

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

private:
	enum class Level { MENU, LEVEL1, GAMEOVER };

	void LoadAudio(const olc::vf2d& listenerPos);
	void LoadLevel(const Level& level);
	void HandleInput();
	void UpdateWorld(float fElapsedTime);
	void RenderFrame();

private:
	std::vector<std::unique_ptr<GameObject>> vGameObjects;
	olc::TileTransformedView tv;
	AudioManager audio;
	bool bGameOver{ false };

	static const std::string s_sMenu, s_sLevel1, s_sGameOver;
};

#endif // GAME_H_



