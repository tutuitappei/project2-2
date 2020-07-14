#include<DxLib.h>
#include<mutex>
#include "Stage.h"
#include"input/Keyboard1.h"

int Stage::_stagecount = 0;

Stage::Stage(Vector2&& offset, Vector2&& size)
{
	_id = _stagecount;
	_stagecount++;
	_offset = std::move(offset);
	_size = std::move(size);
	init();
	puyo = std::make_unique<Puyo>(Vector2{ 100,100 }, PuyoID::Red);
}

Stage::Stage():ScreenID(0),_id(0),_color(0x000000)
{

}

Stage::~Stage()
{
	_stagecount--;
}

int Stage::GetStageDraw(void)
{
	return ScreenID;
}

void Stage::Draw(void)
{
}

void Stage::Updata(void)
{
	(*controller)();
	for (auto data : controller->GetCntData())
	{
		if (data.second[static_cast<int>(Trg::Now)] && !data.second[static_cast<int>(Trg::Old)])
		{
			puyo->Move(data.first);
		}
	}
	puyo->Updata();

}

bool Stage::init(void)
{
	ScreenID = MakeScreen(_size.x,_size.y,true );
	_color = 0x000033 << (16 * _id);

	_dataBaase.resize(STAGE_SIZE_X * STAGE_SIZE_Y);
	for (int no = 0; no < STAGE_SIZE_Y; no++)
	{
		_data.emplace_back(&_dataBaase[no * STAGE_SIZE_X]);
	}

	controller = std::make_unique<Keyboard1>();
	controller->Setup(_id);
	return false;
}
