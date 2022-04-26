#include "ShootingGame.h"


BossCannon::BossCannon(float px, float py,string name) : BossChildSprite("보스자식", name , true, px, py)
{
	this->hp = 100;

	this->fireTimer = 0;
	this->fireDelay = 2;


}
BossCannon::~BossCannon()
{

}

void BossCannon::Start()
{
	SetSprite("Asset/보스.bmp", 357, 262, 21, 22);
	AddBoxCollider2D(0, 0, 21, 22);

	SetDamage(20); //피해량 저장
}

void BossCannon::Update()
{
	fireTimer += Time::deltaTime;

	if (fireTimer >= fireDelay)
	{
		float px = GetPx();
		float py = GetPy();

		BossBullet* bullet;

		for (int i = 0; i < 30; i++)
		{
			bullet = (BossBullet*)Instantiate(new BossBullet(px + 2, py + 15));
			bullet->SetAngle(i*12);


		}


		fireTimer = 0;
	}
}
/***********************************************************
void BossCannon::Explosion()
{
	float px = GetPx();
	float py = GetPy();

	Instantiate(new BossChildExp(px - 17, py - 30));

	Destroy(this);
}
void BossCannon::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();
		

	if (tag == "레이저")
	{
		hp -= 100;

		if (hp <= 0)
		{
			Explosion();
		}
	}
	else if (tag == "폭탄폭발")
	{
		hp -= 100;

		if (hp <= 0)
		{
			Explosion();
		}
	}
}
******************************************************************/
