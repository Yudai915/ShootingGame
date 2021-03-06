#include "Player.h"
#include <DxLib.h>
#include "Keyboard.h"
#include "Other.h"
#include "Chara.h"
#include "Battle.h"
#include <climits>


Player::Player()
{
	m_timecount = 0;
	image = new int;
	name = ePlayer;

	pos.x = SET_SCREENSIZE_X / 2;
	pos.y = SET_SCREENSIZE_Y / 2;

	*image = LoadGraph("画像/自機.png");
	GetGraphSize(*image, &image_width, &image_height);
}

Player::~Player()
{
	DeleteGraph(*image);
	delete image;
}

void Player::Update()
{
	// int型の最大値を超えさせない処理
	if (m_timecount >= INT_MAX - 10000) {
		m_timecount = 0;
	}

	m_timecount += Timecount_return();

	if (Get_key(KEY_INPUT_A) >= 1) {
		Move_Left();
	}
	if (Get_key(KEY_INPUT_D) >= 1) {
		Move_Right();
	}
	if (Get_key(KEY_INPUT_W) >= 1) {
		Move_Up();
	}
	if (Get_key(KEY_INPUT_S) >= 1) {
		Move_Down();
	}

	if (pos.x < 0)
	{
		pos.x = 0;
	}
	if (pos.x > SET_SCREENSIZE_X - image_width)
	{
		pos.x = SET_SCREENSIZE_X - image_width;
	}
	if (pos.y < SET_SCREENSIZE_Y / 2)
	{
		pos.y = SET_SCREENSIZE_Y / 2;
	}
	if (pos.y > SET_SCREENSIZE_Y - image_height)
	{
		pos.y = SET_SCREENSIZE_Y - image_height;
	}

	if (Get_key(KEY_INPUT_SPACE) >= 1 && m_timecount >= SHOT_PACE_PLAYER) {
		Ballet_Inst(pos, name);
		m_timecount = 0;
	}
}

void Player::Draw()
{
	DrawGraph(pos.x, pos.y, *image, true);
}