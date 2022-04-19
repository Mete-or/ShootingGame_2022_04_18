#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("", "", true, px, py)
{

}
Boss::~Boss()
{

}

void Boss::Start()
{
	//�������� ���� ���� 
	SetSprite("Asset/����.bmp", 0 , 0 , 493 , 206 );

	//������ ���� �̹���
	//SetSprite("Asset/����.bmp", 0, 613, 385, 182);

	//�����緯 �ڽİ�ü �߰��ϱ�
	AddChildObject(new Bossprop(63, 41));
	AddChildObject(new Bossprop(111, 41));
	AddChildObject(new Bossprop(159, 41));

	AddChildObject(new Bossprop(302, 41));
	AddChildObject(new Bossprop(350, 41));
	AddChildObject(new Bossprop(398, 41));



	AddChildObject(new BossWing(256, 97,	 0)); //������ ù��°
	AddChildObject(new BossWing(302, 94,	 1)); //������ �ι�°
	AddChildObject(new BossWing(350, 90,	 2));
	AddChildObject(new BossWing(405, 84,	 3));

	AddChildObject(new BossWing(206, 98,	 4));
	AddChildObject(new BossWing(158, 94,	 5));
	AddChildObject(new BossWing(110, 90,	 6));
	AddChildObject(new BossWing( 62, 85,	 7));




}
void Boss::Update()
{

}
