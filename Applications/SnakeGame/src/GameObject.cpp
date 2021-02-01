#include "GameObject.h"

std::string GameObject::s_sMap =
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

const olc::vi2d GameObject::s_vMapSize = { 32, 24 };

void Ball::Update(float fElapsedTime)
{
	//olc::vf2d vTempPos{ vPos.x + vVel.x * fElapsedTime,  vPos.y + vVel.y * fElapsedTime };

	//olc::vi2d vCurrentCell = vPos.floor();
	//olc::vi2d vTargetCell = vTempPos;
	//olc::vi2d vAreaTL = (vCurrentCell.min(vTargetCell) - olc::vi2d(1, 1)).max({ 0,0 });
	//olc::vi2d vAreaBR = (vCurrentCell.max(vTargetCell) + olc::vi2d(1, 1)).min(GameObject::GetMapSize());

	//olc::vf2d vRayToNearest;

	//// Iterate through each cell in test area
	//olc::vi2d vCell;
	//for (vCell.y = vAreaTL.y; vCell.y <= vAreaBR.y; vCell.y++)
	//	for (vCell.x = vAreaTL.x; vCell.x <= vAreaBR.x; vCell.x++)
	//	{
	//		// Check if the cell is actually solid...
	//		if (GameObject::GetMap()[vCell.y * GameObject::GetMapSize().x + vCell.x] == '#')
	//		{
	//			olc::vf2d vNearestPoint;
	//			vNearestPoint.x = std::max(float(vCell.x), std::min(vTempPos.x, float(vCell.x + 1)));
	//			vNearestPoint.y = std::max(float(vCell.y), std::min(vTempPos.y, float(vCell.y + 1)));

	//			olc::vf2d vRayToNearest = vNearestPoint - vTempPos;
	//			float fOverlap = fRadius - vRayToNearest.mag();

	//			if (std::isnan(fOverlap)) fOverlap = 0;
	//			if (fOverlap > 0)
	//				// Statically resolve the collision
	//				vTempPos = vTempPos - vRayToNearest.norm() * fOverlap;
	//		}
	//	}
	//vPos = vTempPos;
}

void Ball::Draw(olc::TileTransformedView& tv)
{
	tv.FillCircle(vPos, fRadius, olc::WHITE);
}


void Platform::Update(float fElapsedTime)
{
	float potentialPos{ vPos.x + vVel.x * fElapsedTime };
	std::string& map = GameObject::GetMap();
	int mapWidth = GameObject::GetMapSize().x;

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
}

void Platform::Draw(olc::TileTransformedView& tv)
{
	tv.FillRect(vPos, vSize, olc::BLACK);
}

void Platform::Resize(float width, float height)
{
	vSize.x = width;
	vSize.y = height;
}