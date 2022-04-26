#include "ShootingGame.h"


BossRadar::BossRadar(float px, float py) : BossChildSprite("보스자식", "보스레이더", true, px, py)
{

}
BossRadar::~BossRadar()
{

}

void BossRadar::Start()
{
	SetSprite("Asset/보스.bmp", 360, 245, 11, 9);
	AddBoxCollider2D(0, 0, 11, 9);
}
void BossRadar::Update()
{

}
