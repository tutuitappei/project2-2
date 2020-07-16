#pragma once
#include<vector>
#include"Vector2.h"
#include"input/Controller.h"
#include"Puyo.h"

//class Vector2

#define STAGE_SIZE_X 6
#define STAGE_SIZE_Y 12

class Stage
{
public:
	Stage();
	Stage(Vector2&& offset, Vector2&& size);
	~Stage();

	int GetStageDraw(void);
	void Draw(void);
	void Updata(void);
private:
	bool init(void);

	int _screenID;
	Vector2 _offset;
	Vector2 _size;

	std::unique_ptr<Controller> controller;

	std::vector<int*> _data;
	std::vector<int> _dataBaase;

	int _blocksize;

	std::unique_ptr<Puyo> puyo;
	static int _stagecount;
	int _id;
	int _color;
};

