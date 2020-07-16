#include<DxLib.h>
#include "Puyo.h"

Puyo::Puyo(Vector2 vec, PuyoID id)
{
    _pos = vec;
    _size = { 32, 32};
    _id = id;
}

Puyo::~Puyo()
{
}

void Puyo::Move(InputID id)
{
	switch (id)
	{
    case InputID::Up:
        _pos.y -= _size.y;
        break;
    case InputID::Down:
        _pos.y += _size.y;
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

void Puyo::Updata(void)
{
    Draw();
}

void Puyo::Draw(void)
{
    DrawCircle(_pos.x, _pos.y, _size.x/2, 0xffffff, true);
}

bool Puyo::SetDirParmit(Dirpermit dirparmit)
{
    return false;
}

const Vector2 Puyo::GetGrid(int size)
{
    return Vector2(_pos.x - size/2, _pos.y - size/2);
}
