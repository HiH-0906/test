#include "Enemy.h"
#include <ImageMng.h>


void Enemy::Init()
{
	AnimVector data;
	data.emplace_back(IMAGE_ID("���")[10], 30);
	data.emplace_back(IMAGE_ID("���")[11], 60);
	SetAnim("NORMAL", data);

	data.emplace_back(IMAGE_ID("�G����")[0], 10);
	data.emplace_back(IMAGE_ID("�G����")[1], 15);
	data.emplace_back(IMAGE_ID("�G����")[2], 20);
	data.emplace_back(IMAGE_ID("�G����")[3], 25);
	data.emplace_back(IMAGE_ID("�G����")[4], 30);
	SetAnim("BLAST", data);
}

Enemy::Enemy()
{
	Init();
}


Enemy::~Enemy()
{
}
