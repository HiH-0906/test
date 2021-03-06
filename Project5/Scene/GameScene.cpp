#include <DxLib.h>
#include <_DebugConOut.h>
#include "GameScene.h"
#include <ImageMng.h>
#include <Player.h>


GameScene::GameScene()
{
	lpImageMng.GetID("ｷｬﾗ", "image/char.png", { 30,32 }, { 10, 10 });
	lpImageMng.GetID("弾", "image/shot.png", {8, 3}, { 1, 2});
	lpImageMng.GetID("敵爆発", "image/en_blast.png", { 64,64 }, { 5, 1 });
	lpImageMng.GetID("PL爆発", "image/pl_blast.png", { 64,64 }, { 4, 1 });

	TREACE("ｹﾞｰﾑｼｰﾝの生成");
	obj.resize(1);

	obj[0] = new Player();
	obj[0]->animKey("NORMAL");

	/*obj[0] = new Obj("image/char.png", { 0,0 }, 10, 10, 30, 32);
	obj[1] = new Obj("image/char.png", { 500,100 }, 10, 10, 30, 32);*/
}


GameScene::~GameScene()
{
}

unipueBase GameScene::Update(unipueBase own)
{
	// 先頭を取り出し、最後の要素まで回してくれる
	for(auto data :obj)
	{
		data->Draw();
	}
	return std::move(own);
}
