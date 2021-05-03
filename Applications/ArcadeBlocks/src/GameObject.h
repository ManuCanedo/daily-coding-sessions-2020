#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string_view>

#include "olcPixelGameEngine.h"
#include "olcPGEX_TransformedView.h"

#include "AudioManager.h"

// Abstract Game Object
class GameObject {
public:
	GameObject() = default;

	virtual void Update(float fElapsedTime, AudioManager& audio) = 0;
	virtual void Draw(olc::TileTransformedView& tv) const = 0;

	static std::string& GetMap()
	{
		return s_sMap;
	}
	static const olc::vi2d& GetMapSize()
	{
		return s_vMapSize;
	}
	static void SetLevel(std::string_view map)
	{
		s_sMap = map;
	}

	olc::vf2d vPos;
	olc::vf2d vVel;

protected:
	GameObject(const olc::vf2d& pos, const olc::vf2d& vel = { 0.0f, 0.0f })
		: vPos(pos), vVel(vel)
	{
	}

private:
	static std::string s_sMap;
	const static olc::vi2d s_vMapSize;
};

// Ball Game Object
class Ball : public GameObject {
public:
	Ball(const olc::vf2d& pos = { 3.0f, 3.0f }, float fRadius = 1.0f)
		: GameObject(pos, { 3.0f - rand() % 6, 15.0f }), fRadius(fRadius)
	{
	}

	void Update(float fElapsedTime, AudioManager& audio) override;
	void Draw(olc::TileTransformedView& tv) const override;

	bool IsOutOfBounds() const
	{
		return bOutOfBounds;
	}
	void SetOutOfBounds()
	{
		bOutOfBounds = true;
	}

	float fRadius;
	static Ball* s_Ball;

private:
	bool bOutOfBounds{ false };
};

// Platform Game Object
class Platform : public GameObject {
public:
	Platform(const olc::vf2d& pos, const olc::vf2d& size) : GameObject(pos), vSize(size)
	{
	}

	void Update(float fElapsedTime, AudioManager& audio) override;
	void Draw(olc::TileTransformedView& tv) const override;

	olc::vf2d vSize;
};

#endif // GAME_OBJECT_H