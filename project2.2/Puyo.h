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
	Vector2 _size;
	Vector2 _pos;
	void Move(InputID id);
	void Updata(void);
private:
};

