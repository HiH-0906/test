#pragma once
#include <memory>
#include <vector>
#include <tuple>
#include <common/Vector2.h>
#include "BaseScene.h"

using DrawQueT = std::tuple<int, int, int>;

#define lpSceneMng SceneMng::GetInstance()

enum class DRAW_QUE
{
	IMAGE,
	X,
	Y
};

class SceneMng
{
public:
	static SceneMng &GetInstance(void)			// ｺﾝｽﾄﾗｸﾀｰ呼び出し関数
	{
		Create();								// staticなものしか触れない
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)				// すでにあるか判断
		{
			sInstance = new SceneMng();			// 作成
		}
	}

	static void Destroy()
	{
		if (sInstance != nullptr)				// あるか判定
		{
			delete sInstance;					// 削除
		}
		sInstance = nullptr;
	}


	void Ran(void);								// ﾙｰﾌﾟ

	bool AddDrawQue(DrawQueT dQue);							// ｷｭｰを溜める

	const Vector2 ScreenSize;					// ｽｸﾘｰﾝｻｲｽﾞ reedonly
private:
	static SceneMng* sInstance;					// ﾎﾟｲﾝﾀ

	unipueBase _activeScene;					// ﾕﾆｰｸﾎﾟｲﾝﾀ

	void Draw(void);							// 描画

	std::vector<DrawQueT> _drawList;			// 描画用ｷｭｰ
	SceneMng();									// ｺﾝｽﾄﾗｸﾀ
	~SceneMng();								// ﾃﾞｽﾄﾗｸﾀ
	bool SysInit(void);							// ｼｽﾃﾑｲﾆｯﾄ
};

