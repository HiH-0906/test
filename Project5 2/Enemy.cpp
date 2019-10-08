#include "Enemy.h"
#include <ImageMng.h>


void Enemy::Init()
{
	AnimVector data;
	data.emplace_back(IMAGE_ID("·¬×")[10], 30);
	data.emplace_back(IMAGE_ID("·¬×")[11], 60);
	SetAnim("NORMAL", data);

	data.emplace_back(IMAGE_ID("“G”š”­")[0], 10);
	data.emplace_back(IMAGE_ID("“G”š”­")[1], 15);
	data.emplace_back(IMAGE_ID("“G”š”­")[2], 20);
	data.emplace_back(IMAGE_ID("“G”š”­")[3], 25);
	data.emplace_back(IMAGE_ID("“G”š”­")[4], 30);
	SetAnim("BLAST", data);
}

Enemy::Enemy()
{
	Init();
}


Enemy::~Enemy()
{
}
