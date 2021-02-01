#include "Application.h"

bool Game::OnUserCreate()
{
	tv = olc::TileTransformedView({ ScreenWidth(), ScreenHeight() }, { 32, 32 });
	vGameObjects.push_back(std::make_unique<World>(World({ 2.0f, 2.0f })));
	vGameObjects.push_back(std::make_unique<Platform>(Platform({ 12.0f, 20.0f }, { 5.0f, 1.0f })));
	vGameObjects.push_back(std::make_unique<Ball>(Ball({ 12.0f, 12.0f })));

	tv.ZoomAtScreenPos(0.25f, olc::vf2d(-1.0f, -1.0f));
	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	// Handle Pan & Zoom
	if (GetMouse(2).bPressed) tv.StartPan(GetMousePos());
	if (GetMouse(2).bHeld) tv.UpdatePan(GetMousePos());
	if (GetMouse(2).bReleased) tv.EndPan(GetMousePos());
	if (GetMouseWheel() > 0) tv.ZoomAtScreenPos(1.2f, GetMousePos());
	if (GetMouseWheel() < 0) tv.ZoomAtScreenPos(0.8f, GetMousePos());

	// Update GameObjects
	for (auto& go : vGameObjects)
	{
		UpdateObject(go.get(), fElapsedTime);
	}

	// Clear World
	Clear(olc::GREY);

	// Draw GameObjects
	for (auto& go : vGameObjects)
	{
		RenderObject(go.get());
	}

	return true;
}

void Game::UpdateObject(GameObject* obj, float fElapsedTime)
{
	obj->Update(fElapsedTime);
}

void Game::RenderObject(GameObject* obj)
{
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
