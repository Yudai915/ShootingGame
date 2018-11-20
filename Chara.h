#ifndef DEF_CHARA_H
#define DEF_CHARA_H
#include <DxLib.h>
#define SPEED 4.5

class Chara
{
public:
	Chara();
	~Chara();

	typedef enum { ePlayer, eEnemy, eBallet, eBalletMgr }eName;
	eName name;

	virtual void init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;

	void Move_Up();
	void Move_Down();
	void Move_Right();
	void Move_Left();

	VECTOR pos;
	int *image;
	int m_x;
	int m_y;
	int m_hp;
	float m_speed;
};

#endif // !DEF_CHARA_H
