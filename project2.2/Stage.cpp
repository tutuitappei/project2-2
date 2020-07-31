#include<DxLib.h>
#include<mutex>
#include<functional>
#include<algorithm>
#include "Stage.h"
#include"PlayUnit.h"
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
	puyo = std::make_unique<Puyo>(Vector2{ 64,32 }, PuyoID::Red);
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
	//DrawGraph(_offset.x,_offset.y,_screenID,true);
	for (int no = 0; no < 2; no++)
	{
		DrawBox(_offset.x + (_size.x*8)*no , _offset.y, _offset.x + _size.x * 8 + (_size.x * 8) * no, _size.y * 14, 0xffffff, false);
	}
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
			if (_data[pos.x][pos.y-1])
			{
				dirparmit.perBit.up = 0;
			}
			 if (_data[pos.x][pos.y+1])
			{
				dirparmit.perBit.down = 0;
			}
			 if (_data[pos.x-1][pos.y + offset_y])
			{
				dirparmit.perBit.left = 0;
			}
			 if (_data[pos.x+1][pos.y + offset_y])
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
	/*PlayUnit().Updata(,,);*/
	puyo->Updata();
	puyo->Draw();

}

bool Stage::init(void)
{
	_screenID = MakeScreen(_size.x,_size.y,true );
	_color = 0x000033 << (16 * _id);

	_dataBase.resize(STAGE_SIZE_X * STAGE_SIZE_Y);
	for (size_t no = 0; no < STAGE_SIZE_Y; no++)
	{
		_data.emplace_back(&_dataBase[no * static_cast<size_t>(STAGE_SIZE_X)]);
	}

	SetWall();

	controller = std::make_unique<Keyboard1>();
	controller->Setup(_id);
	return false;
}

bool Stage::InstancePuyo(void)
{

	auto id = puyo->GetID();
	//PuyoVec.emplace(PuyoVec.begin());
	id = puyo->GetID();

	return true;
}

bool Stage::EleseData(void)
{
	memset(_erasedataBase.data(), 0, _erasedataBase.size() * sizeof(PuyoID));

	std::function<void(PuyoID, Vector2)> chpuyo = [&](PuyoID id, Vector2 vec) {
		if (_erasedata[vec.x][vec.y]->GetID() == PuyoID::Non)
		{
			if (_data[vec.x][vec.y])
			{
				count++;
				_erasedata[vec.x][vec.y] = _data[vec.x][vec.y];
				chpuyo(id, { vec.x,vec.y - 1 });
				chpuyo(id, { vec.x,vec.y + 1 });
				chpuyo(id, { vec.x - 1,vec.y });
				chpuyo(id, { vec.x + 1,vec.y });
			}
		}
	};
	if (count < 4)
	{
		memset(_erasedataBase.data(), 0, _erasedataBase.size() * sizeof(PuyoID));
	}
	else
	{
		//for (auto&& puyoo : PuyoVec )
		//{

		//}
		return true;
	}
	return false;
}

void Stage::Deletopuyo(void)
{
}

bool Stage::SetWall(void)
{
	for (auto j = 0; j < STAGE_SIZE_Y; j++)
	{
		for (auto i = 0; i < STAGE_SIZE_X; i++)
		{
			if (i == 0 || i == STAGE_SIZE_X || j == STAGE_SIZE_Y)
			{
				//_data[i][j]->GetID() = PuyoID::Wall;
			}
		}
	}
	return true;
}
