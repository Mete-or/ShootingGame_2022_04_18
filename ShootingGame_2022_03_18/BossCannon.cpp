#include "ShootingGame.h"


BossCannon::BossCannon(float px, float py) : Sprite("", "", true, px, py)
{

}
BossCannon::~BossCannon()
{

}

void BossCannon::Start()
{
	SetSprite("Asset/����.bmp", 357, 262, 21, 22);
}
void BossCannon::Update()
{

}
