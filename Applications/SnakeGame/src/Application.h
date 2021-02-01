#include <memory>

#include "GameObject.h"

class Game : public olc::PixelGameEngine
{
public:
	Game()
	{
		sAppName = "Snake";

	}

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

private:
	void UpdateObject(GameObject* obj, float fElapsedTime);
	void RenderObject(GameObject* obj);

private:
	olc::TileTransformedView tv;
	std::vector<std::unique_ptr<GameObject>> vGameObjects;
};

