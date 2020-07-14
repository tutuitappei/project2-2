#include "Puyo.h"

Puyo::Puyo()
{
}

Puyo::~Puyo()
{
}

void Puyo::Move(InputID id)
{
	switch (id)
	{
    case InputID::Up:
        //_pos.y -= _size.y
        break;
    case InputID::Down:
        //_pos.y += _size.y
        break;
    case InputID::Left:
        //_pos.x -= _size.x
        break;
    case InputID::Right:
        //_pos.x += _size.x
        break;
    case InputID::Btn1:
        break;
    case InputID::Btn2:
        break;
    default:
        break;
	}
}

void Puyo::Updata(void)
{
}
