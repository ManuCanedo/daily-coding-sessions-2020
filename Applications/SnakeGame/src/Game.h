#pragma one

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#define OLC_PGEX_TRANSFORMEDVIEW
#include "olcPGEX_TransformedView.h"

#include "GameObject.h"

#include <memory>

// Game Class
class Game : public olc::PixelGameEngine
{
public:
	Game();

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

private:
	void GameOver();
	void HandleInput();
	void UpdateWorld(float fElapsedTime);
	void RenderFrame();

private:
	std::vector<std::unique_ptr<GameObject>> vGameObjects;
	olc::TileTransformedView tv;

public:
	bool bGameOver{ false };
};




