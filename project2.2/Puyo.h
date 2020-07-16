#pragma once
#include"input/Inputid.h"
#include"Vector2.h"

enum class PuyoID 
{
	NON,
	Red,
	Blue,
	Green,
	Yellow,
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
	Puyo();
	Puyo(Vector2 vec,PuyoID id);
	~Puyo();
	void Move(InputID id);
	void Updata(void);

	void Draw(void);

	bool SetDirParmit(Dirpermit dirparmit);

	//const Vector2& GetPos(void);

	const Vector2 GetGrid(int size);
private:
	Dirpermit _dirparmit;

	Vector2 _size;
	Vector2 _pos;
	PuyoID _id;

};

