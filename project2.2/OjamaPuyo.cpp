#include "OjamaPuyo.h"

OjamaPuyo::OjamaPuyo(Vector2 vec, PuyoID id) : Puyo(vec, id)
{
	_id = id;
	_pos = vec;
}

OjamaPuyo::~OjamaPuyo()
{
}

bool OjamaPuyo::Updata(void)
{

	return false;
}
