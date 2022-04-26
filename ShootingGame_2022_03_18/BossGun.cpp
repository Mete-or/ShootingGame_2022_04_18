#include "ShootingGame.h"

BossGun::BossGun(float px, float py) : BossChildSprite("보스자식", "보스총", true, px, py)
{

}
BossGun::~BossGun()
{

}

void BossGun::Start()
{
	SetSprite("Asset/보스.bmp", 426, 315, 20, 25);
	AddBoxCollider2D(0, 0, 20, 25);
}


