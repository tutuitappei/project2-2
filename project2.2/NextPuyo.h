#pragma once
#include<memory>
#include <list>
#include "Vector2.h"
#include"Puyo.h"
#include "Stage.h"

using nextPair = std::pair<Sharepuyo, Sharepuyo>;
using nextList = std::list<nextPair>;

class NextPuyo
{
public:
	NextPuyo(Vector2& pos, int data, int drawnum);
	~NextPuyo();
	nextPair PickUp(void);

	bool Add(int no);

private:
	Vector2 _pos;			//ネクストぷよ用座標	
	nextList _nextPuyoList;	//ぷよリスト
	int _drawCount;			//描画数
	int _screenID;			//ネクストぷよ用スクリーンID
};

