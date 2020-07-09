#include<DxLib.h>
#include<mutex>
#include "Stage.h"

Stage::Stage(Vector2&& offset, Vector2&& size)
{
	_offset = std::move(offset);
	_size = std::move(size);
	init();
}

Stage::Stage():ScreenID(0),_id(0)
{

}

Stage::~Stage()
{
}

int Stage::GetStageDraw(void)
{
	return 0;
}

void Stage::Draw(void)
{
}

bool Stage::init(void)
{
	ScreenID = MakeScreen(_size.x,_size.y,true );
	return true;
}
