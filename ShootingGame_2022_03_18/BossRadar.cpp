#include "ShootingGame.h"


BossRadar::BossRadar(float px, float py) : BossChildSprite("�����ڽ�", "�������̴�", true, px, py)
{

}
BossRadar::~BossRadar()
{

}

void BossRadar::Start()
{
	SetSprite("Asset/����.bmp", 360, 245, 11, 9);
	AddBoxCollider2D(0, 0, 11, 9);
}
void BossRadar::Update()
{

}
