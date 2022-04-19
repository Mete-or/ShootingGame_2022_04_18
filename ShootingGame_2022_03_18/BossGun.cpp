#include "ShootingGame.h"

BossGun::BossGun(float px, float py) : Sprite("", "", true, px, py)
{

}
BossGun::~BossGun()
{

}

void BossGun::Start()
{
	SetSprite("Asset/º¸½º.bmp", 426, 315, 20, 25);
}

void BossGun::Update()
{

}
