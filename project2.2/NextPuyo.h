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
	Vector2 _pos;			//�l�N�X�g�Ղ�p���W	
	nextList _nextPuyoList;	//�Ղ惊�X�g
	int _drawCount;			//�`�搔
	int _screenID;			//�l�N�X�g�Ղ�p�X�N���[��ID
};

