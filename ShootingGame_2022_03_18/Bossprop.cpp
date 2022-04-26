#include "ShootingGame.h"


Bossprop::Bossprop(float px, float py) : Animation("보스자식", "프로펠러", true, px, py)
{
	this->hp = 100;
}
Bossprop::~Bossprop()
{

}

void Bossprop::Start()
{
	//피해없는 프로펠러 애니메이션 - 0번//
	AddSprite("Asset/프로펠러1.bmp",   5, 5, 32, 12 , 0, 16, 6);
	AddSprite("Asset/프로펠러1.bmp",  39, 5, 32, 12 , 0, 16, 6);
	AddSprite("Asset/프로펠러1.bmp",  72, 5, 30, 12 , 0, 15, 6);
	AddSprite("Asset/프로펠러1.bmp", 104, 5, 24, 12 , 0, 12, 6);

	AddSprite("Asset/프로펠러1.bmp", 131, 5, 20, 12 , 0, 10, 6);
	AddSprite("Asset/프로펠러1.bmp", 153, 5, 26, 12 , 0, 13, 6);
	AddSprite("Asset/프로펠러1.bmp", 182, 5, 28, 12 , 0, 14, 6);
	AddSprite("Asset/프로펠러1.bmp", 213, 5, 30, 12 , 0, 15, 6);



	//피해입은 프로펠러 애니메이션 - 1번//
	
	AddSprite("Asset/프로펠러2.bmp",   7, 4, 32, 48, 1, 16, 6);
	AddSprite("Asset/프로펠러2.bmp",  42, 4, 31, 48, 1, 15, 6);
	AddSprite("Asset/프로펠러2.bmp",  76, 4, 29, 48, 1, 15, 6);
	AddSprite("Asset/프로펠러2.bmp", 108, 4, 31, 48, 1, 18, 6);
	AddSprite("Asset/프로펠러2.bmp", 142, 4, 31, 48, 1, 17, 6);
	AddSprite("Asset/프로펠러2.bmp", 176, 4, 32, 48, 1, 16, 6);
	AddSprite("Asset/프로펠러2.bmp", 210, 4, 31, 48, 1, 16, 6);
	AddSprite("Asset/프로펠러2.bmp", 244, 4, 32, 48, 1, 16, 6);
	
	

	Play(0); //0번 애니메이션부터 시작
	Speed(3);

	//충돌체 추가

	AddBoxCollider2D(-16, -5, 32, 12);
}
void Bossprop::Update()
{
	//부모 포인터 확인하기
	string tag = parent->GetTag();
}
void Bossprop::Explosion()
{
	float px = GetPx();
	float py = GetPy();

	//폭발효과 이동 오프셋 구하기//

	float offx = (32 - 64) / 2;
	float offy = (12 - 64) / 2;


	Instantiate(new BossChildExp(px + offx, py + offy));

	Destroy(this);

	//프로펠러의 부모객체인 보스에 프로펠러가 제거되었음을 알려주기

	//parent->On 형변환을 해줘야함

	((Boss*)parent)->OnChildDestroy(this->GetName());

	//부모 객체인 보스에게 자식이 제거되었음을 알림//
	((Boss*)parent)->OnChildDestroy(this->GetName());
	
}

void Bossprop::OnTriggerStay2D(GameObject* other)
{
	string tag = other->GetTag();

	if (tag == "레이저")
	{
		//체력에 피해 적용하기
		hp -= 10;

		if (0 < hp && hp <= 50)
		{
			Play(1); // 연기나는 애니메이션
		}
		else if (hp <= 0)
		{
			Explosion();
		}

	}
	else if (tag == "폭탄폭발")
	{
		Explosion();
	}

}