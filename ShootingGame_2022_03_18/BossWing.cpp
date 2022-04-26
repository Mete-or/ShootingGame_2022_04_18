#include "ShootingGame.h"

BossWing::BossWing(float px, float py , int idx) : BossChildSprite("보스자식","보스날개",true,px,py)
{
	this->idx = idx;
	//this->hp = 100;
}
BossWing::~BossWing()
{

}

void BossWing::Start()
{
	SetSprite("Asset/보스.bmp",rect[idx][0],rect[idx][1],rect[idx][2],rect[idx][3]);

	AddBoxCollider2D(0,0, rect[idx][2], rect[idx][3]);


}/**************************************************
void BossWing::Update()
{

}
void BossWing::Explosion()
{
	float px = GetPx();
	float py = GetPy();

	Instantiate(new BossChildExp(px - 17, py - 30));

	Destroy(this);
}
void BossWing::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();

	if (tag == "레이저")
	{
		//체력 줄이기
		hp = hp - 100;

		if (hp <= 0)
		{
			//날개 폭발
			Explosion();
		}

	}
	else if (tag == "폭탄폭발")
	{
		Explosion();
	}
}
*****************************************************/



