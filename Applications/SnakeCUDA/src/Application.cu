#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include <memory>

class Game : public olc::PixelGameEngine
{
public:
	Game()
	{
		sAppName = "Snake";
	}

	bool OnUserCreate() override
	{
		CreateBoard(m_Board.get(), ScreenWidth(), ScreenHeight());

		return true;
	}

	bool OnUserUpdate(float elapsed) override
	{
		for (int x = 0; x < ScreenWidth(); ++x)
			for (int y = 0; y < ScreenHeight(); ++y)
			{
				Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
			}

		return true;
	}

private:
	void CreateBoard(uint32_t* board, size_t width, size_t height)
	{

	}

private:
	std::unique_ptr<uint32_t[]> m_Board{ std::make_unique<uint32_t[]>(3840) };
};

int main()
{
	Game* game = new Game();

	if (game->Construct(256, 240, 4, 4))
		game->Start();

	return 0;
}