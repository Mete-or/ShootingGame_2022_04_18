#include "ShootingGame.h"

BossGun::BossGun(float px, float py,string name) : BossChildSprite("�����ڽ�", name, true, px, py)
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
void BossGun::Update()
{




}
void BossGun::OnFire()
{
	float px = GetPx();
	float py = GetPy();


			BossBullet* bullet = (BossBullet*)Instantiate(new BossBullet(px, py));
			bullet->SetAngle(90);
			

}


