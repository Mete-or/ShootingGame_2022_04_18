#include "ShootingGame.h"

BossGun::BossGun(float px, float py) : BossChildSprite("�����ڽ�", "������", true, px, py)
{

}
BossGun::~BossGun()
{

}

void BossGun::Start()
{
	SetSprite("Asset/����.bmp", 426, 315, 20, 25);
	AddBoxCollider2D(0, 0, 20, 25);
}


