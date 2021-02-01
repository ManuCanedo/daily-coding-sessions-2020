#pragma once

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#define OLC_PGEX_TRANSFORMEDVIEW
#include "olcPGEX_TransformedView.h"

class GameObject
{
public:

	virtual void Update(float fElapsedTime) = 0;
	virtual void Draw(olc::TileTransformedView& tv) = 0;

	olc::vf2d vPos{ 0, 0 };
	olc::vf2d vVel{ 0, 0 };

protected:
	GameObject() = default;

	GameObject(const olc::vf2d& pos)
		: vPos(pos)
	{
	}
};

// Static GameObjects
class World : public GameObject
{
public:
	World() = default;

	World(const olc::vf2d& pos)
		: GameObject(pos)
	{
	}

	void Update(float fElapsedTime) override
	{
		// Complete Update Behaviour
	}

	void Draw(olc::TileTransformedView& tv) override
	{
		olc::vi2d vTL = tv.GetTopLeftTile().max({ 0,0 });
		olc::vi2d vBR = tv.GetBottomRightTile().min(vSize);
		olc::vi2d vTile;

		for (vTile.y = vTL.y; vTile.y < vBR.y; vTile.y++)
			for (vTile.x = vTL.x; vTile.x < vBR.x; vTile.x++)
			{
				if (sMap[vTile.y * vSize.x + vTile.x] == '#')
				{
					tv.DrawRect(vTile, { 1.0f, 1.0f }, olc::VERY_DARK_GREY);
					tv.FillRect(vTile, { 1.0f, 1.0f }, olc::VERY_DARK_GREY);
				}
			}
	}

	std::string sMap =
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
		"################################";

	olc::vi2d vSize = { 32, 24 };
};


// Dinamic GameObjects
class Ball : public GameObject
{
public:
	Ball(const olc::vf2d& pos, float fRadius = 0.5f)
		:  GameObject(pos), fRadius(fRadius)
	{
	}

	void Update(float fElapsedTime) override
	{
		vPos.y += fElapsedTime;
	}

	void Draw(olc::TileTransformedView& tv) override
	{
		tv.FillCircle(vPos, fRadius, olc::WHITE);
	}

private:
	bool DetectCollision(World& wordl)
	{
		// Complete Collision Detection
	}

private:
	float fRadius;
};

class Platform : public GameObject
{
public:
	Platform(const olc::vf2d& pos, const olc::vf2d& size)
		: GameObject(pos), vSize(size)
	{
	}

	void Update(float fElapsedTime) override
	{
		// Complete Update Behaviour
	}

	void Draw(olc::TileTransformedView& tv) override
	{
		tv.FillRect(vPos, vSize, olc::BLACK);
	}

private:
	void Resize(float width, float height)
	{
		vSize.x = width;
		vSize.y = height;
	}

private:
	olc::vf2d vSize;
};