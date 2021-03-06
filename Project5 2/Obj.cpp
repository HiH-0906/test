#include <DxLib.h>
#include "Obj.h"
#include <SceneMng.h>
#include <ImageMng.h>


Obj::Obj()
{
	_animFrame = 0;
	_animCount = 0;
}


Obj::~Obj()
{
}

bool Obj::animKey(const std::string key)
{
	// ｷｰが使えるかﾁｪｯｸ
	if (_animMap.find(key) == _animMap.end())
	{
		// 無いので使えない
		return false;
	}
	// あったら登録
	if (_animKey != key)
	{
		// 同じｷｰでなければ0ｸﾘ
		_animFrame = 0;
		_animCount = 0;
	}

	_animKey = key;
	return true;
}

const std::string Obj::animKey(void) const
{
	return _animKey;
}

void Obj::pos(int x, int y)
{
	_pos.x += x;
	_pos.y += y;
}


bool Obj::SetAnim(const std::string key, AnimVector& data)
{
	// c++17以降
	return (_animMap.try_emplace(key, std::move(data))).second;

	//// すでにあるかﾁｪｯｸ
	//if (_animMap.find(key) == _animMap.end())
	//{
	//	// 無かったら登録
	//	_animMap[key] = data;
	//	return true;
	//}
	//return false;
}

void Obj::Update(void)
{
}

void Obj::Draw(void)
{
	// 念のためｷｰﾁｪｯｸ
	if (_animMap.find(_animKey) == _animMap.end())
	{
		// 存在しなかったらreturn
		return;
	}
	// ｱﾆﾒｰｼｮﾝﾌﾚｰﾑもﾁｪｯｸ
	if (_animMap[_animKey].size() <= _animFrame ||
		0 > _animFrame)
	{
		// 存在しなかったらreturn
		return;
	}
	_animCount++;
	if (_animCount == _animMap[_animKey][_animFrame].second)
	{
		_animFrame++;
	}
	if (_animMap[_animKey].size() <= _animFrame)
	{
		_animFrame = 0;
		_animCount = 0;
	}
	// ｷｭｰへの追加
	lpSceneMng.AddDrawQue({ _animMap[_animKey][_animFrame].first,_pos.x,_pos.y });
}

void Obj::Draw(int id)
{
	lpSceneMng.AddDrawQue({ id, _pos.x,_pos.y });
}

