#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("보스", "", true, px, py)
{
	this->deadChildCount = 0;
	this->speed			 = 30;
	this->state			 = State::moveDown;
	this->attackpos		 = 50;
	this->fallsp = 15;

	this->fallTimeOut = 5;

	this->gunFireTimer = 0;
	this->gunFireDelay = 1;

	this->gunPatternIdx = 0;
}
Boss::~Boss()
{

}
//상속에 의해서
//보스클래스에서 
//void GameObject::AddChildObject(GameObject* child, int layer)
//{
//	child->parent = this; //this는 child 객체 의 부모객체 포인터
//
//	childObjects.push_back(child);
//
	//자식객체를 부모 좌표 기준으로..이동시키기
//	child->Translate(px, py);
//
//	ObjectManager::Instantiate(child, layer);
//}


void Boss::Start()
{
	//폭발하지 않은 보스 
	SetSprite("Asset/보스.bmp", 0 , 0 , 493 , 206 );

	//폭발한 보스 이미지
	//SetSprite("Asset/보스.bmp", 0, 613, 385, 182);

	//프로펠러 자식객체 추가하기
	AddChildObject(new Bossprop( 63+16, 41+6));
	AddChildObject(new Bossprop(111+16, 41+6));
	AddChildObject(new Bossprop(159+16, 41+6));

	AddChildObject(new Bossprop(302+16, 41+6));
	AddChildObject(new Bossprop(350+16, 41+6));
	AddChildObject(new Bossprop(398+16, 41+6));


	//보스 날개 자식객체 추가하기
	AddChildObject(new BossWing(256, 97,	 0)); //오른쪽 첫번째
	AddChildObject(new BossWing(302, 94,	 1)); //오른쪽 두번째
	AddChildObject(new BossWing(350, 90,	 2));
	AddChildObject(new BossWing(405, 84,	 3));

	AddChildObject(new BossWing(206, 98,	 4));
	AddChildObject(new BossWing(158, 94,	 5));
	AddChildObject(new BossWing(110, 90,	 6));
	AddChildObject(new BossWing( 62, 85,	 7));

	//보스 건 자식 객체 추가하기

	AddChildObject(new BossGun( 94, 71,"왼쪽첫번째"));
	AddChildObject(new BossGun(142, 71,"왼쪽두번째"));
	AddChildObject(new BossGun(190, 71,"왼쪽세번째"));

	AddChildObject(new BossGun(238, 71,"가운데"));

	AddChildObject(new BossGun(286, 71,"오른쪽첫번째"));
	AddChildObject(new BossGun(334, 71,"오른쪽두번째"));
	AddChildObject(new BossGun(382, 71,"오른쪽세번째"));

	//보스 캐논 자식 객체 추가하기

	AddChildObject(new BossCannon(265 + 5, 97 + 10,"오른쪽대포")); // 오른쪽
	AddChildObject(new BossCannon(206 - 5, 97 + 10,  "왼쪽대포")); // 왼쪽

	//보스 레이더 자식객체 추가하기

	AddChildObject(new BossRadar(241, 105));
	AddChildObject(new BossRadar(241, 117));






}
void Boss::Update()
{
	if (state == State::moveDown)
	{
		Translate(0, speed * Time::deltaTime);
		if (GetPy() > attackpos)
		{
			
			state = State::attack;
		}
	}
	else if (state == State::attack)
	{
		/**********************************************************
		//캐논 자식 객체를 찾아서 발사 시작을 알려줌//
		BossCannon* RCannon = (BossCannon *)Find("오른쪽대포");

		if (RCannon != nullptr)
		{
			RCannon->OnStartFire();
		}

		BossCannon* LCannon = (BossCannon*)Find("왼쪽대포");

		if (LCannon != nullptr)
		{
			LCannon->OnStartFire();
		}
		***********************************************************/

		string cannons[2] = { "오른쪽대포", "왼쪽대포" };

		for (int i = 0; i < 2; i++)
		{
			BossCannon * c = (BossCannon *)Find(cannons[i]);
			if (c != nullptr)
			{
				c->OnStartFire();
			}
		}

		gunFireTimer += Time::deltaTime;

		if (gunFireTimer >= gunFireDelay)
		{

			string guns[7] = { "왼쪽첫번째","왼쪽두번째","왼쪽세번째",
											"가운데"
							,"오른쪽첫번째","오른쪽두번째","오른쪽세번째" };


			for (int i = 0; i < 7; i++)
			{
				if (gunPatttern[gunPatternIdx][i] == true)
				{

					BossGun* g = (BossGun*)Find(guns[i]);

					if (g != nullptr)
					{

						g->OnFire();
					}
				}

			}

			gunFireTimer = 0;
			gunPatternIdx++;

			if (gunPatternIdx >= 20)
			{
				gunPatternIdx = 0;
			}

		}
		
	}
	else if (state == State::fall)
	{
		Translate(0, fallsp * Time::deltaTime);

		//추락 시간 측정

		fallTimeOut = fallTimeOut - Time::deltaTime;

		if (fallTimeOut <= 0)
		{
			//보스 제거하기
			Destroy(this);
			//스테이지 클리어
		}
	}
	
}
void Boss::OnChildDestroy(string name)
{
	//제거된 자식 카운트 증가시키기
	deadChildCount++;

	printf("---제거된 자식 수 %d ---\n", deadChildCount);

	if (deadChildCount == 25) //보스의 모든 자식객체가 제거됌
	{
		//보스 폭발
		float px = GetPx();
		float py = GetPy();

		Instantiate(new EnemyExp(px, py));
		
		//보스가 폭발후 이미지로 변경
		SetSprite("Asset/보스.bmp", 0, 613, 385, 182,-47,-7);

		//보스 추락 상태로 변경하기//
		state = State::fall;

		//보스 제거
		//Destroy(this);
	}
}
void BossCannon::OnStartFire()
{
	doFire = true;
}

