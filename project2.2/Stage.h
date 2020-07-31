#pragma once
#include<vector>
#include<memory>
#include"Vector2.h"
#include"input/Controller.h"
#include"Puyo.h"
//#include"PlayUnit.h"
#include"puyomode/Dorop.h"
#include"puyomode/Elase.h"
#include"puyomode/Puyon.h"
#include"puyomode/Munyon.h"
#include"puyomode/Fall.h"

//class Vector2

#define STAGE_SIZE_X 8
#define STAGE_SIZE_Y 14

class PlayUnit;
struct Dorop;
struct Elase;
struct Puyon;
struct Munyon;
struct Fall;

enum class StgMode
{
	DROP,
	PUYON,
	ELASE,
	MOVE,
	MUNYON,
	MAX
};

using Sharepuyo = std::shared_ptr<Puyo>;
using Unipuyo = std::unique_ptr<Puyo>;

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
	bool InstancePuyo(void);
	bool EleseData(void);

	int _screenID;
	Vector2 _offset;
	Vector2 _size;

	StgMode _stgmode;

	Unipuyo puyo;
	std::vector<Sharepuyo> PuyoVec;

	std::unique_ptr<Controller> controller;

	std::vector<Sharepuyo*> _data;
	std::vector<Sharepuyo> _dataBase;
	std::vector<Sharepuyo*> _erasedata;
	std::vector<Sharepuyo> _erasedataBase;

	//std::vector<int*> _data;
	//std::vector<int> _dataBase;
	//std::vector<int*> _erasedataBase;

	int _blocksize;
	int count;
	
	void Deletopuyo(void);
	bool SetWall(void);

	static int _stagecount;
	int _id;
	int _color;

	friend PlayUnit;
	friend Dorop;
	friend Elase;
	friend Munyon;
	friend Puyon;
	friend Fall;
};

