#include "GameObject.h"

#include <algorithm>

std::string GameObject::s_sMap;
const olc::vi2d GameObject::s_vMapSize = { 32, 24 };

Ball* Ball::s_Ball = nullptr;

void Ball::Update(float fElapsedTime, AudioManager& audio)
{
	const olc::vf2d mapSize = GameObject::GetMapSize();
	std::string& map = GameObject::GetMap();

	olc::vf2d vTempPos{ vPos.x + vVel.x * fElapsedTime,  vPos.y + vVel.y * fElapsedTime };
	const olc::vi2d vCurrentCell = vPos.floor();
	const olc::vi2d vTargetCell = vTempPos;
	const olc::vi2d vAreaTL = (vCurrentCell.min(vTargetCell) - olc::vi2d(1, 1)).max({ 0,0 });
	const olc::vi2d vAreaBR = (vCurrentCell.max(vTargetCell) + olc::vi2d(1, 1)).min(mapSize);

	// Iterate through each cell in test area
	olc::vi2d vCell;
	for (vCell.y = vAreaTL.y; vCell.y <= vAreaBR.y; vCell.y++)
		for (vCell.x = vAreaTL.x; vCell.x <= vAreaBR.x; vCell.x++)
			// Resolve Map Collision
			if (map[vCell.y * mapSize.x + vCell.x] != '.')
			{
				olc::vf2d vNearestPoint;
				vNearestPoint.x = std::max(float(vCell.x), std::min(vTempPos.x, float(vCell.x + 1)));
				vNearestPoint.y = std::max(float(vCell.y), std::min(vTempPos.y, float(vCell.y + 1)));

				const olc::vf2d vRayToNearest = vNearestPoint - vTempPos;
				const float fOverlap = (std::isnan(fRadius - vRayToNearest.mag()) ? 0 : fRadius - vRayToNearest.mag());

				if (fOverlap > 0)
				{
					// Statically resolve the collision
					vTempPos = vTempPos - vRayToNearest.norm() * fOverlap;

					if (vRayToNearest.x == 0 || vRayToNearest.y == 0)
					{
						switch (map[vCell.y * mapSize.x + vCell.x])
						{
						case '3':
							map[vCell.y * mapSize.x + vCell.x] = '2';
							break;
						case '2':
							map[vCell.y * mapSize.x + vCell.x] = '1';
							break;
						case '1':
							map[vCell.y * mapSize.x + vCell.x] = '.';
							FMOD_VECTOR posSFX = { vTempPos.x, vTempPos.y, 0.0f };
							FMOD_VECTOR velSFX = { vVel.x, vVel.y , 0.0f };
							audio.PlaySFX("media/sfx/block_destroyed.ogg", 0.8f, 1.0f, 0.8f, 1.2f, posSFX, velSFX);
							if (map.find_first_not_of("#.") == std::string::npos)
								bOutOfBounds = true;
							break;
						}

						if (vRayToNearest.x == 0)
							vVel.y = -vVel.y;
						else if (vRayToNearest.y == 0)
							vVel.x = -vVel.x;
						break;
					}
				}
			}

	vPos = vTempPos;
}

void Ball::Draw(olc::TileTransformedView& tv) const
{
	tv.FillCircle(vPos, fRadius, olc::Pixel(181, 167, 235));
}

void Platform::Update(float fElapsedTime, AudioManager& audio)
{
	const std::string& map = GameObject::GetMap();
	const int mapWidth = GameObject::GetMapSize().x;
	const float potentialPos{ vPos.x + vVel.x * fElapsedTime };

	if (Ball::s_Ball != nullptr && Ball::s_Ball->vPos.y > vPos.y)
		Ball::s_Ball->SetOutOfBounds();

	// Resolve Wall Collision
	if (vVel.x > 0)
	{
		const olc::vi2d vTargetCell(potentialPos + vSize.x, vPos.y);
		if (map[vTargetCell.y * mapWidth + vTargetCell.x] == '#')
			vPos.x = vTargetCell.x - vSize.x;
		else
			vPos.x = potentialPos;
	}
	else
	{
		const olc::vi2d vTargetCell(potentialPos, vPos.y);
		if (map[vTargetCell.y * mapWidth + vTargetCell.x] == '#')
			vPos.x = vTargetCell.x + 1.0f;
		else
			vPos.x = potentialPos;
	}

	// Resolve Ball Collision
	const bool bCollision = 
		Ball::s_Ball != nullptr &&
		Ball::s_Ball->vPos.x + Ball::s_Ball->fRadius / 2 > vPos.x &&
		Ball::s_Ball->vPos.x - Ball::s_Ball->fRadius / 2 < vPos.x + vSize.x &&
		Ball::s_Ball->vPos.y + Ball::s_Ball->fRadius >= vPos.y;

	if (bCollision)
	{
		Ball::s_Ball->vPos.y = vPos.y - Ball::s_Ball->fRadius;
		Ball::s_Ball->vVel.y = -Ball::s_Ball->vVel.y;
		Ball::s_Ball->vVel.x = Ball::s_Ball->vVel.x + vVel.x / 8;
		FMOD_VECTOR posSFX = { vPos.x, vPos.y, 0.0f };
		FMOD_VECTOR velSFX = { vVel.x, vVel.y , 0.0f };
		audio.PlaySFX("media/sfx/block_bounce.ogg", 0.05f, 0.1f, 0.6f, 1.2f, posSFX, velSFX);
	}
}

void Platform::Draw(olc::TileTransformedView& tv) const
{
	tv.FillRect(vPos, vSize, olc::Pixel(181, 167, 235));
}