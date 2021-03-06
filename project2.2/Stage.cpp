#include<DxLib.h>
#include<mutex>
#include<functional>
#include<algorithm>
#include "Stage.h"
#include"PlayUnit.h"
#include"NextPuyo.h"
#include"input/Keyboard1.h"
#include"puyomode/Dorop.h"
#include"puyomode/Elase.h"
#include"puyomode/Puyon.h"
#include"puyomode/Munyon.h"
#include"puyomode/Fall.h"

int Stage::_stagecount = 0;

Stage::Stage(Vector2&& offset, Vector2&& size)
{
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

Stage::Stage() :_screenID(0), _id(0), _color(0x000000), _blocksize(0), count(0), _stgmode(StgMode::DROP), _maxrensa(0), _rensa(0), _erasenum(0),_ojamanum(0), _ojamaFlag(false)
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
	//for (int y = 0; y < 14; y++) {
	//	for (int x = 0; x < 8; x++) {
	//		if (x == 0 || x == 7 || y == 14)
	//		{
	//			_data[x][y] = static_cast<int>(PuyoID::Wall);
	//		}
	//		else
	//		{
	//			_data[x][y] = static_cast<int>(PuyoID::Non);
	//		}
	//	}
	//}
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
	if (GameOverCheck())
	{

	}

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

	//InstancePuyo();
	return false;
}

bool Stage::InstancePuyo(void)
{
	//auto id = nextpuyo->PickUp();

	//id.first -> pos({ _blocksize / 2 + _blocksize * 3, _blocksize });
	//id.second->pos({ _blocksize / 2 + _blocksize * 3, _blocksize + _blocksize / 2 });

	//auto pos1 = Vector2{ _blocksize / 2 + _blocksize * 3, _blocksize };
	//auto pos2 = Vector2{ _blocksize / 2 + _blocksize * 3, _blocksize + _blocksize / 2 };

	//auto id = puyo->GetID();
	//PuyoVec.emplace(PuyoVec.begin(), std::make_unique<Puyo>(pos1));
	//id = puyo->GetID();
	//PuyoVec.emplace(PuyoVec.begin(), std::make_unique<Puyo>(pos2));


	return true;
}

bool Stage::OjamaInstance(void)
{
	return false;
}

bool Stage::GameOverCheck(void)
{
	return false;
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
				_erasenum++;
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

	//むにょんで行う処理
	//連鎖数の加算
	_rensa++;
	//おじゃまぷよの数 = (過去の最大連鎖数 / 2)＊(今回の連鎖数 - 1) * 消した個数 / 8
	_ojamanum = (_maxrensa / 2) * (_rensa - 1) * _erasenum / 8;

	//ドロップで行う処理
	//過去の最大連鎖数の更新
	_maxrensa = _rensa > _maxrensa ? _rensa : _maxrensa;
	//消した個数の初期化
	_erasenum = 0;
	//連鎖数の初期化
	_rensa = 0;

	return false;
}

void Stage::Deletopuyo(void)
{
}

bool Stage::SetWall(void)
{
	//for (auto j = 0; j < STAGE_SIZE_Y; j++)
	//{
	//	for (auto i = 0; i < STAGE_SIZE_X; i++)
	//	{
	//		if (i == 0 || i == STAGE_SIZE_X || j == STAGE_SIZE_Y)
	//		{
	//			_data[i][j]->SetID(PuyoID::Wall);
	//		}
	//		else
	//		{
	//			_data[i][j]->SetID(PuyoID::Non);
	//		}
	//	}
	//}
	return true;
}
