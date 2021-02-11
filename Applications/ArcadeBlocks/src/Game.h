#pragma one

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#define OLC_PGEX_TRANSFORMEDVIEW
#include "olcPGEX_TransformedView.h"

#include "AudioManager.h"
#include "GameObject.h"

#include <memory>
#include <Windows.h>

// Game Class
class Game : public olc::PixelGameEngine
{
	enum class Level { MENU, LEVEL1, GAMEOVER }; 
	static const std::string s_sMenu, s_sLevel1, s_sGameOver;

public:
	Game();

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

	bool bGameOver{ false };

private:
	void LoadAudio(const olc::vf2d listenerPos);
	void LoadLevel(const Level level);

	void HandleInput();
	void UpdateWorld(float fElapsedTime);
	void RenderFrame();

private:
	std::vector<std::unique_ptr<GameObject>> vGameObjects;
	olc::TileTransformedView tv;
	AudioManager audio;
};




