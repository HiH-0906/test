#include "Player.h"
#include <ImageMng.h>


void Player::Init(void)
{
	AnimVector data;
	data.reserve(5);
	data.emplace_back(IMAGE_ID("·¬×")[0], 30);
	data.emplace_back(IMAGE_ID("·¬×")[1], 60);
	SetAnim("NORMAL", data);

	data.reserve(1);
	data.emplace_back(IMAGE_ID("·¬×")[2], 0);
	SetAnim("EX", data);
	data.emplace_back(IMAGE_ID("PL­")[0], 20);
	data.emplace_back(IMAGE_ID("PL­")[1], 25);
	data.emplace_back(IMAGE_ID("PL­")[2], 30);
	data.emplace_back(IMAGE_ID("PL­")[3], 35);
	data.emplace_back(-1, 40);
	SetAnim("BLAST", data);
}

Player::Player()
{
	Init();
}


Player::~Player()
{
}
