#include "ShootingGame.h"


BossRadar::BossRadar(float px, float py) : Sprite("", "", true, px, py)
{

}
BossRadar::~BossRadar()
{

}

void BossRadar::Start()
{
	SetSprite("Asset/����.bmp", 360, 245, 11, 9);
}
void BossRadar::Update()
{

}
