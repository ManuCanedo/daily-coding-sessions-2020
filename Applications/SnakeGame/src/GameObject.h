#pragma one

#include "olcPixelGameEngine.h"
#include "olcPGEX_TransformedView.h"

#include <string_view>

// Game Object abstract class
class GameObject
{
public:
	GameObject() = default;

	virtual void Update(float fElapsedTime) = 0;
	virtual void Draw(olc::TileTransformedView& tv) = 0;

	static std::string& GetMap() { return s_sMap; }
	static const olc::vi2d& GetMapSize() { return s_vMapSize; }

	olc::vf2d vPos;
	olc::vf2d vVel;

protected:
	GameObject(const olc::vf2d& pos, const olc::vf2d& vel = { 0.0f, 0.0f })
		: vPos(pos), vVel(vel) {}

private:
	static std::string s_sMap;
	const static olc::vi2d s_vMapSize;
};


// Ball Game Object
class Ball : public GameObject
{
public:
	Ball(const olc::vf2d&& pos = { 3.0f, 3.0f }, float fRadius = 1.0f)
		: GameObject(pos), fRadius(fRadius) {}

	void Update(float fElapsedTime) override;
	void Draw(olc::TileTransformedView& tv) override;

private:
	float fRadius;
};


// Platform Game Object
class Platform : public GameObject
{
public:
	Platform(const olc::vf2d&& pos, const olc::vf2d&& size)
		: GameObject(pos), vSize(size) {}

	void Update(float fElapsedTime) override;
	void Draw(olc::TileTransformedView& tv) override;

private:
	inline void Resize(float width, float height);

	olc::vf2d vSize;
};