#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "GameScene.h"

SceneMng* SceneMng::sInstance = nullptr;

void SceneMng::Draw(void)
{
	SetDrawScreen(DX_SCREEN_BACK);			// 描画先設定
	ClsDrawScreen();

	// ｽﾀｯｸに溜まっているQueを描画する
	//	範囲for文
	for (auto dQue:_drawList)
	{
		DrawGraph(
			std::get<static_cast<int>(DRAW_QUE::X)>(dQue),
			std::get<static_cast<int>(DRAW_QUE::Y)>(dQue),
			std::get<static_cast<int>(DRAW_QUE::IMAGE)>(dQue),
			true);
	}
	//// iteratorfor文
	//for (auto dQue = _drawList.begin(); dQue != _drawList.end; dQue++)
	//{
	//	DrawGraph(
	//		std::get<static_cast<int>(DRAW_QUE::X)>(*dQue),
	//		std::get<static_cast<int>(DRAW_QUE::Y)>(*dQue),
	//		std::get<static_cast<int>(DRAW_QUE::IMAGE)>(*dQue),
	//		true);
	//}
	//// 今までのfor文
	//for (int i = 0; i < _drawList.size(); i++)
	//{
	//	DrawGraph(
	//		std::get<static_cast<int>(DRAW_QUE::X)>(_drawList[i]),
	//		std::get<static_cast<int>(DRAW_QUE::Y)>(_drawList[i]),
	//		std::get<static_cast<int>(DRAW_QUE::IMAGE)>(_drawList[i]),
	//		true);
	//}

	ScreenFlip();
}
SceneMng::SceneMng():ScreenSize{800,600}
{
}


SceneMng::~SceneMng()
{
}

void SceneMng::Ran(void)
{
	SysInit();
	_activeScene = std::make_unique<GameScene>();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		_drawList.clear();			// ﾘｽﾄの削除
		_activeScene = (*_activeScene).Update(std::move(_activeScene));
		Draw();						// 描画
	}
}

bool SceneMng::AddDrawQue(DrawQueT dQue)
{
	if (std::get<static_cast<int>(DRAW_QUE::IMAGE)>(dQue) <= 0)
	{
		// 画像IDが不正なので、追加しない
		return false;
	}
	// Queを追加
	_drawList.emplace_back(dQue);

	return true;
}

bool SceneMng::SysInit(void)
{
	// ｼｽﾃﾑ処理
	SetWindowText("1916035_橋本 大輝 課題5");

	SetGraphMode(ScreenSize.x, ScreenSize.y, 16);	// 800*600ﾄﾞｯﾄ、65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);							// true:Window flse:ﾌﾙｽｸﾘｰﾝ

	if (DxLib_Init() == -1)							// DXﾗｲﾌﾞﾗﾘの初期化設定
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);					// 描写先をﾊﾞｯｸﾊﾞｯﾌｧに設定

	return false;
}
