#pragma once
#include"Vector2.h"
#include"input/Controller.h"
#include"Puyo.h"

//class Vector2

class Stage
{
public:
	Stage(Vector2&& offset, Vector2&& size);
	Stage();
	~Stage();

	int GetStageDraw(void);
	void Draw(void);
	void Updata(void);
private:
	bool init(void);

	int ScreenID;
	Vector2 _offset;
	Vector2 _size;

	std::unique_ptr<Controller> controller;

	std::unique_ptr<Puyo> puyo;
	static int _stagecount;
	int _id;
};

