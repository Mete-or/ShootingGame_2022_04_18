#pragma once

#include "Sprite.h"

class Boss : public Sprite
{
	enum State { moveDown = 0, attack = 1 , fall = 2};

private:
	
	float fallsp;
	float speed;
	int deadChildCount;
	float attackpos;
	float fallTimeOut;
	

	State state;

	float gunFireTimer;
	float gunFireDelay;

	//�� �߻� ���� 
	bool gunPatttern[20][7]   ={{true,false,true,	true,	true,false,true},
								{false,true,false,	true,	false,true,false},
								{true,false,true,	true,	true,false,true},
								{false,true,false,	true,	false,true,false},
								{true,false,true,	true,	true,false,true},

								{false,true,false,	true,	false,true,false},
								{true,false,true,	true,	true,false,true},
								{false,true,false,	true,	false,true,false},
								{true,false,true,	true,	true,false,true},
								{false,true,false,	true,	false,true,false},

								{true,false,true,	true,	true,false,true},
								{false,true,false,	true,	false,true,false},
								{true,false,true,	true,	true,false,true},
								{false,true,false,	true,	false,true,false},
								{true,false,true,	true,	true,false,true},

								{false,true,false,	true,	false,true,false},
								{true,false,true,	true,	true,false,true},
								{false,true,false,	true,	false,true,false},
								{true,false,true,	true,	true,false,true},
								{false,true,false,	true,	false,true,false},
																	};

	int gunPatternIdx;

public:
	Boss(float px, float py);
	~Boss();

	void Start();
	void Update();

	//���� �ڽ��� ���ߵǾ����� �˸��� �̺�Ʈ �Լ�
	void OnChildDestroy(string name);
	void OnStartFire();

};

