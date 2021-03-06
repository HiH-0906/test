#pragma once
#include <string>
#include <vector>
#include <map>
#include <Vector2.h>

using AnimVector = std::vector<std::pair<int, unsigned int>>;

class Obj
{
public:
	Obj();
	void Update(void);
	void Draw(void);											// ｱﾆﾒｰｼｮﾝありの描画
	void Draw(int id);											// ｱﾆﾒｰｼｮﾝなしの描画
	virtual ~Obj();

	bool animKey(const std::string key);						// ｱﾆﾒｰｼｮﾝｷｰの追加
	const std::string animKey(void) const;						// 現在のｱﾆﾒｰｼｮﾝｷｰの取得

	void pos(int x, int y);

	bool SetAnim(const std::string key, AnimVector& data);		// ﾃﾞｰﾀ格納用関数
private:
	Vector2 _pos;
	std::map<std::string, AnimVector> _animMap;					// ｱﾆﾒｰｼｮﾝﾃﾞｰﾀ管理変数
	std::string _animKey;										// ﾃﾞｰﾀｱｸｾｽ用ｷｰ
	unsigned int _animFrame;									// 現在ｱﾆﾒｰｼｮﾝ
	unsigned int _animCount;									// ｶｳﾝﾄ
};

