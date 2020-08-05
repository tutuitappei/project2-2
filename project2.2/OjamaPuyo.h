#pragma once
#include "Puyo.h"

//enum class PuyoTyp
//{
//	NORMAL,
//	MAX
//};

class OjamaPuyo :
	public Puyo
{
public:
	OjamaPuyo(Vector2 vec, PuyoID id);
	~OjamaPuyo();
	
	bool Updata(void);

private:
	PuyoID _id;
	Vector2 _pos;
};

