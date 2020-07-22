#pragma once
#include"input/Inputid.h"
#include"Vector2.h"

enum class PuyoID 
{
	Non,
	Red,
	Blue,
	Green,
	Yellow,
	Purpule,
	Wall,
	MAX
};

struct DirBit
{
	unsigned int up : 1;
	unsigned int down : 1;
	unsigned int left : 1;
	unsigned int right : 1;
};

union Dirpermit
{
	DirBit perBit;
	unsigned int per;

};

class Puyo
{
public:
	Puyo(Vector2 vec,PuyoID id);
	~Puyo();
	void Move(InputID id);
	void Draw(void);
	bool SoftDrop(void);
	bool Updata(void);

	bool SetDirParmit(Dirpermit dirparmit);

	PuyoID GetID(void);

	//const Vector2& GetPos(void);

	const Vector2 GetGrid(int size);
private:
	Dirpermit _dirparmit;

	Vector2 _size;
	Vector2 _pos;
	PuyoID _id;

	int _dropcnt;
	int _dropinter;
	int _dropspeed;
};

