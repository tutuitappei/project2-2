#pragma once

enum MoveControll
{
	Move_Left,
	Move_Right,
	Move_Down
};

class Controller
{
public:
	Controller();
	~Controller();
	virtual void Update(void) ;
private:
};

