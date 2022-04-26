#include "ShootingGame.h"

Boss::Boss(float px, float py) : Sprite("����", "", true, px, py)
{
	this->deadChildCount = 0;
	this->speed			 = 30;
	this->state			 = State::moveDown;
	this->attackpos		 = 50;
	this->fallsp = 15;

	this->fallTimeOut = 5;
}
Boss::~Boss()
{

}
//��ӿ� ���ؼ�
//����Ŭ�������� 
//void GameObject::AddChildObject(GameObject* child, int layer)
//{
//	child->parent = this; //this�� child ��ü �� �θ�ü ������
//
//	childObjects.push_back(child);
//
	//�ڽİ�ü�� �θ� ��ǥ ��������..�̵���Ű��
//	child->Translate(px, py);
//
//	ObjectManager::Instantiate(child, layer);
//}


void Boss::Start()
{
	//�������� ���� ���� 
	SetSprite("Asset/����.bmp", 0 , 0 , 493 , 206 );

	//������ ���� �̹���
	//SetSprite("Asset/����.bmp", 0, 613, 385, 182);

	//�����緯 �ڽİ�ü �߰��ϱ�
	AddChildObject(new Bossprop( 63+16, 41+6));
	AddChildObject(new Bossprop(111+16, 41+6));
	AddChildObject(new Bossprop(159+16, 41+6));

	AddChildObject(new Bossprop(302+16, 41+6));
	AddChildObject(new Bossprop(350+16, 41+6));
	AddChildObject(new Bossprop(398+16, 41+6));


	//���� ���� �ڽİ�ü �߰��ϱ�
	AddChildObject(new BossWing(256, 97,	 0)); //������ ù��°
	AddChildObject(new BossWing(302, 94,	 1)); //������ �ι�°
	AddChildObject(new BossWing(350, 90,	 2));
	AddChildObject(new BossWing(405, 84,	 3));

	AddChildObject(new BossWing(206, 98,	 4));
	AddChildObject(new BossWing(158, 94,	 5));
	AddChildObject(new BossWing(110, 90,	 6));
	AddChildObject(new BossWing( 62, 85,	 7));

	//���� �� �ڽ� ��ü �߰��ϱ�

	AddChildObject(new BossGun( 94, 71));
	AddChildObject(new BossGun(142, 71));
	AddChildObject(new BossGun(190, 71));

	AddChildObject(new BossGun(238, 71));

	AddChildObject(new BossGun(286, 71));
	AddChildObject(new BossGun(334, 71));
	AddChildObject(new BossGun(382, 71));

	//���� ĳ�� �ڽ� ��ü �߰��ϱ�

	AddChildObject(new BossCannon(265 + 5, 97 + 10,"�����ʴ���")); // ������
	AddChildObject(new BossCannon(206 - 5, 97 + 10,  "���ʴ���")); // ����

	//���� ���̴� �ڽİ�ü �߰��ϱ�

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
		//ĳ�� �ڽ� ��ü�� ã�Ƽ� �߻� ������ �˷���//

	}
	else if (state == State::fall)
	{
		Translate(0, fallsp * Time::deltaTime);

		//�߶� �ð� ����

		fallTimeOut = fallTimeOut - Time::deltaTime;

		if (fallTimeOut <= 0)
		{
			//���� �����ϱ�
			Destroy(this);
			//�������� Ŭ����
		}
	}
	
}
void Boss::OnChildDestroy(string name)
{
	//���ŵ� �ڽ� ī��Ʈ ������Ű��
	deadChildCount++;

	printf("---���ŵ� �ڽ� �� %d ---\n", deadChildCount);

	if (deadChildCount == 25) //������ ��� �ڽİ�ü�� ���ŉ�
	{
		//���� ����
		float px = GetPx();
		float py = GetPy();

		Instantiate(new EnemyExp(px, py));
		
		//������ ������ �̹����� ����
		SetSprite("Asset/����.bmp", 0, 613, 385, 182,-47,-7);

		//���� �߶� ���·� �����ϱ�//
		state = State::fall;

		//���� ����
		//Destroy(this);
	}
}

