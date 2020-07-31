#include "PlayUnit.h"

PlayUnit::PlayUnit(Stage &stage)
{

}

PlayUnit::~PlayUnit()
{
}

void PlayUnit::Updata(Vector2 vec1, Vector2 vec2, bool RightFlag)
{
	Dirpermit dirparmit;
	dirparmit.perBit = { 1,1,1,1 };
	
	auto pos = stage.puyo->GetGrid(stage._blocksize);
	int offset_y = ((pos.y % stage._blocksize) != 0);

	for (auto data : stage.controller->GetCntData())
	{
		if (data.second[static_cast<int>(Trg::Now)] && !data.second[static_cast<int>(Trg::Old)])
		{
			if (stage._data[pos.x][pos.y - 1])
			{
				dirparmit.perBit.up = 0;
			}
			if (stage._data[pos.x][pos.y + 1])
			{
				dirparmit.perBit.down = 0;
			}
			if (stage._data[pos.x - 1][pos.y + offset_y])
			{
				dirparmit.perBit.left = 0;
			}
			if (stage._data[pos.x + 1][pos.y + offset_y])
			{
				dirparmit.perBit.right = 0;
			}

			stage.puyo->SetDirParmit(dirparmit);
			stage.puyo->Move(data.first);

		}
		if ((data.first == InputID::Down) && data.second[static_cast<int>(Trg::Now)])
		{
			stage.puyo->SoftDrop();
		}
	}



	if (RightFlag)
	{

	}
	if (vec1.y < vec2.y)
	{

	}
	if (vec1.y > vec2.y)
	{

	}
	if (vec1.x < vec2.x)
	{

	}
	if (vec1.x > vec2.x)
	{

	}


}
