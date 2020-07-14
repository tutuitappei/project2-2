#pragma once
#include"input/Inputid.h"

enum class PuyoID 
{
	NON,
	Red,
	Blue,
	Green,
	Yellow,
	MAX
};

class Puyo
{
public:
	Puyo();
	~Puyo();

	void Move(InputID id);
	void Updata(void);
private:
};

