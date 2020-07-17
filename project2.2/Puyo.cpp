#include<DxLib.h>
#include "Puyo.h"

Puyo::Puyo(Vector2 vec, PuyoID id)
{
    _pos = vec;
    _size = { 32, 32};
    _id = id;

    _dropcnt = 0;
    _dropinter = 30;
    _dropspeed = 8;
}

Puyo::~Puyo()
{
}

void Puyo::Move(InputID id)
{
	switch (id)
	{
    case InputID::Up:
        //_pos.y -= _size.y;
        break;
    case InputID::Down:
        break;
    case InputID::Left:
        _pos.x -= _size.x;
        break;
    case InputID::Right:
        _pos.x += _size.x;
        break;
    case InputID::Btn1:
        break;
    case InputID::Btn2:
        break;
    default:
        break;
	}
}

bool Puyo::Updata(void)
{
    if (_dropcnt < _dropinter)
    {
        _dropcnt++;
        return false;
    }
    else
    {
        _pos.y += _dropspeed;
        _dropcnt = 0;
        return true;
    }
    return false;
}

void Puyo::Draw(void)
{
    DrawCircle(_pos.x, _pos.y, _size.x/2, 0xffffff, true);
}

bool Puyo::SoftDrop(void)
{
    _dropcnt += _dropinter;
    return false;
}

bool Puyo::SetDirParmit(Dirpermit dirparmit)
{
    return false;
}

const Vector2 Puyo::GetGrid(int size)
{
    return Vector2(_pos.x - size/2, _pos.y - size/2);
}
