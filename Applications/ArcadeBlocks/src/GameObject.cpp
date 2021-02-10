#include "GameObject.h"

std::string GameObject::s_sMap = "";
const olc::vi2d GameObject::s_vMapSize = { 32, 24 };

Ball* Ball::p_Ball = nullptr;

void Ball::Update(float fElapsedTime)
{
	static std::string& map = GameObject::GetMap();
	static olc::vf2d mapWidth = GameObject::GetMapSize();

	olc::vf2d vTempPos{ vPos.x + vVel.x * fElapsedTime,  vPos.y + vVel.y * fElapsedTime };

	olc::vi2d vCurrentCell = vPos.floor();
	olc::vi2d vTargetCell = vTempPos;
	olc::vi2d vAreaTL = (vCurrentCell.min(vTargetCell) - olc::vi2d(1, 1)).max({ 0,0 });
	olc::vi2d vAreaBR = (vCurrentCell.max(vTargetCell) + olc::vi2d(1, 1)).min(GameObject::GetMapSize());

	olc::vf2d vRayToNearest;

	// Iterate through each cell in test area
	olc::vi2d vCell;
	for (vCell.y = vAreaTL.y; vCell.y <= vAreaBR.y; vCell.y++)
		for (vCell.x = vAreaTL.x; vCell.x <= vAreaBR.x; vCell.x++)
			// Resolve Map Collision
			if (GameObject::GetMap()[vCell.y * GameObject::GetMapSize().x + vCell.x] != '.')
			{
				olc::vf2d vNearestPoint;
				vNearestPoint.x = std::max(float(vCell.x), std::min(vTempPos.x, float(vCell.x + 1)));
				vNearestPoint.y = std::max(float(vCell.y), std::min(vTempPos.y, float(vCell.y + 1)));

				olc::vf2d vRayToNearest = vNearestPoint - vTempPos;
				float fOverlap = fRadius - vRayToNearest.mag();

				if (std::isnan(fOverlap)) fOverlap = 0;
				if (fOverlap >= 0)
				{
					// Statically resolve the collision
					vTempPos = vTempPos - vRayToNearest.norm() * fOverlap;
					
					switch (GameObject::GetMap()[vCell.y * GameObject::GetMapSize().x + vCell.x])
					{
					case '3':
						GameObject::GetMap()[vCell.y * GameObject::GetMapSize().x + vCell.x] = '2';
						break;
					case '2':
						GameObject::GetMap()[vCell.y * GameObject::GetMapSize().x + vCell.x] = '1';
						break;
					case '1':
						GameObject::GetMap()[vCell.y * GameObject::GetMapSize().x + vCell.x] = '.';
						break;
					default:
						break;
					}

					if (vRayToNearest.x == 0)
						vVel.y = -vVel.y;
					else if(vRayToNearest.y == 0)
						vVel.x = -vVel.x;
					else if (vRayToNearest.y > vRayToNearest.x)
						vVel.y = -vVel.y;
					else
						vVel.x = -vVel.x;
				}
			}

	vPos = vTempPos;
}

void Ball::Draw(olc::TileTransformedView& tv)
{
	tv.FillCircle(vPos, fRadius, olc::Pixel(181, 167, 235));
}

void Platform::Update(float fElapsedTime)
{
	static std::string& map = GameObject::GetMap();
	static const int mapWidth = GameObject::GetMapSize().x;
	float potentialPos{ vPos.x + vVel.x * fElapsedTime };

	if (Ball::p_Ball != nullptr && Ball::p_Ball->vPos.y > vPos.y)
		Ball::p_Ball->bOutOfBounds = true;

	// Resolve Wall Collision
	if (vVel.x > 0)
	{
		olc::vi2d vTargetCell(potentialPos + vSize.x, vPos.y);
		if (map[vTargetCell.y * mapWidth + vTargetCell.x] == '#')
			vPos.x = vTargetCell.x - vSize.x;
		else
			vPos.x = potentialPos;
	}
	else
	{
		olc::vi2d vTargetCell(potentialPos, vPos.y);
		if (map[vTargetCell.y * mapWidth + vTargetCell.x] == '#')
			vPos.x = vTargetCell.x + 1.0f;
		else
			vPos.x = potentialPos;
	}

	// Resolve Ball Collision
	bool bCollision = 
		Ball::p_Ball != nullptr &&
		Ball::p_Ball->vPos.x > vPos.x &&
		Ball::p_Ball->vPos.x < vPos.x + vSize.x &&
		Ball::p_Ball->vPos.y + Ball::p_Ball->fRadius >= vPos.y;

	if (bCollision)
	{
		Ball::p_Ball->vVel.y = -Ball::p_Ball->vVel.y;
		Ball::p_Ball->vVel.x = Ball::p_Ball->vVel.x + vVel.x / 8;
		Resize(vSize.x - 0.05f, vSize.y);
	}
}

void Platform::Draw(olc::TileTransformedView& tv)
{
	tv.FillRect(vPos, vSize, olc::Pixel(181, 167, 235));
}

void Platform::Resize(float width, float height)
{
	vPos.x += (vSize.x - width) / 2;
	if (width > 0.2f) vSize.x = width;
}