#include<DxLib.h>
#include"Puyo.h"
#include "NextPuyo.h"

NextPuyo::NextPuyo(Vector2& pos, int data, int drawnum)
{
	_pos = pos;
	_drawCount = drawnum;
	Add(data);
}

NextPuyo::~NextPuyo()
{
}

nextPair NextPuyo::PickUp(void)
{
	auto nextdata = *(_nextPuyoList.begin());
	_nextPuyoList.erase(_nextPuyoList.begin());
	Add(1);
	return nextdata;

}

bool NextPuyo::Add(int no)
{
	while (no)
	{

	}
	while (no)
	{
		_nextPuyoList.emplace_back(
			nextPair{
				std::make_shared<Puyo>(Vector2{ 0,0 }, static_cast<PuyoID>((rand() % (static_cast<int>(PuyoID::MAX) - 4)) + 1)),
				std::make_shared<Puyo>(Vector2{ 0,0 }, static_cast<PuyoID>((rand() % (static_cast<int>(PuyoID::MAX) - 4)) + 1))
			}
		);
		no--;
	}
	Vector2 offSet = { 0,0 };
	Vector2 pos1 = { 0,16 };
	Vector2 pos2 = { 0,16 };
	for (auto data : _nextPuyoList)
	{
		data.first->pos(std::move(pos1));
		data.second->pos(std::move(pos2));
		pos1 += offSet;
		pos2 += offSet;
	}
	return true;
}
