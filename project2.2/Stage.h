#pragma once
#include<vector>
#include"Vector2.h"
#include"input/Controller.h"
#include"Puyo.h"

//class Vector2

#define STAGE_SIZE_X 8
#define STAGE_SIZE_Y 14

enum class StgMode
{
	DROP,
	RENSA,
	MAX,
};

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
	bool EleseData(void);

	int _screenID;
	Vector2 _offset;
	Vector2 _size;

	StgMode _stgmode;

	std::unique_ptr<Controller> controller;

	std::vector<int*> _data;
	std::vector<int> _dataBaase;
	std::vector<int*> _erasedataBaase;

	int _blocksize;
	int count;
	
	void Deletopuyo(void);

	std::unique_ptr<Puyo> puyo;
	std::vector<Puyo> PuyoVec;

	static int _stagecount;
	int _id;
	int _color;
};

