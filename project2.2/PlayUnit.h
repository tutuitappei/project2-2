#pragma once
#include"Vector2.h"
#include"Stage.h"



class PlayUnit
{
public:
	PlayUnit(Stage &stage);
	~PlayUnit();

	void Updata(Vector2 vec1, Vector2 vec2, bool RightFlag);
private:
	Stage &stage;
};

