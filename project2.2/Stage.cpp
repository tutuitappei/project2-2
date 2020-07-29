#include<DxLib.h>
#include<mutex>
#include<functional>
#include<algorithm>
#include "Stage.h"
#include"input/Keyboard1.h"

int Stage::_stagecount = 0;

Stage::Stage(Vector2&& offset, Vector2&& size)
{
	_screenID = 0;
	_id = _stagecount;
	_stagecount++;
	_offset = std::move(offset);
	_size = std::move(size);
	_blocksize = 32;
	count = 0;
	init();
	puyo = std::make_unique<Puyo>(Vector2{ 100,100 }, PuyoID::Red);
	_stgmode = StgMode::DROP;
}

Stage::Stage():_screenID(0),_id(0),_color(0x000000),_blocksize(0),count(0),_stgmode(StgMode::DROP)
{

}

Stage::~Stage()
{
	_stagecount--;
}

int Stage::GetStageDraw(void)
{
	DrawGraph(_offset.x,_offset.y,_screenID,true);
	return _screenID;
}

void Stage::Draw(void)
{
}

void Stage::Updata(void)
{
	(*controller)();

	bool nextFlag = false;
	//std::for_each(PuyoVec.rbegin(), PuyoVec.rend(), [&](){});

	Dirpermit dirparmit;
	dirparmit.perBit = { 1,1,1,1 };

	auto pos = puyo->GetGrid(_blocksize);
	int offset_y = ((pos.y % _blocksize) != 0);

	for (auto data : controller->GetCntData())
	{
		if (data.second[static_cast<int>(Trg::Now)] && !data.second[static_cast<int>(Trg::Old)])
		{
			if (_data[pos.x][pos.y-1] != static_cast<int>(PuyoID::Non))
			{
				dirparmit.perBit.up = 0;
			}
			 if (_data[pos.x][pos.y+1] != static_cast<int>(PuyoID::Non))
			{
				dirparmit.perBit.down = 0;
			}
			 if (_data[pos.x-1][pos.y + offset_y] != static_cast<int>(PuyoID::Non))
			{
				dirparmit.perBit.left = 0;
			}
			 if (_data[pos.x+1][pos.y + offset_y] != static_cast<int>(PuyoID::Non))
			{
				dirparmit.perBit.right = 0;
			}

			puyo->SetDirParmit(dirparmit);
			puyo->Move(data.first);
			
		}
		if ((data.first == InputID::Down)&& data.second[static_cast<int>(Trg::Now)])
		{
			puyo->SoftDrop();
		}
	}
	puyo->Updata();
	puyo->Draw();

}

bool Stage::init(void)
{
	_screenID = MakeScreen(_size.x,_size.y,true );
	_color = 0x000033 << (16 * _id);

	_dataBaase.resize(STAGE_SIZE_X * STAGE_SIZE_Y);
	for (size_t no = 0; no < STAGE_SIZE_Y; no++)
	{
		_data.emplace_back(&_dataBaase[no * static_cast<size_t>(STAGE_SIZE_X)]);
	}

	controller = std::make_unique<Keyboard1>();
	controller->Setup(_id);
	GetStageDraw();
	return false;
}

bool Stage::InstancePuyo(void)
{
	auto id = puyo->GetID();

	id = puyo->GetID();

	return true;
}

bool Stage::EleseData(void)
{
	memset(_erasedataBaase.data(), 0, _erasedataBaase.size() * sizeof(PuyoID));

	std::function<void(PuyoID, Vector2)> chpuyo = [&](PuyoID id, Vector2 vec) {
		if (_erasedataBaase[vec.x][vec.y]/*->GetID()*/ == static_cast<int>(PuyoID::Non))
		{
			if (_data[vec.x][vec.y])
			{
				count++;
				_erasedataBaase[vec.x][vec.y] = _data[vec.x][vec.y];
				chpuyo(id, { vec.x,vec.y - 1 });
				chpuyo(id, { vec.x,vec.y + 1 });
				chpuyo(id, { vec.x - 1,vec.y });
				chpuyo(id, { vec.x + 1,vec.y });
			}
		}
	};
	if (count < 4)
	{
		memset(_erasedataBaase.data(), 0, _erasedataBaase.size() * sizeof(PuyoID));
	}
	else
	{

	}
	return false;
}

void Stage::Deletopuyo(void)
{
}
