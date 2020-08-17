#include<DxLib.h>
#include "Puyo.h"

Puyocolor Puyo::_puyocolor = {
    {PuyoID::Red,0xff0000},
    {PuyoID::Blue,0x0000ff},
    {PuyoID::Green,0x00ff00},
    {PuyoID::Yellow,0xffff00},
    {PuyoID::Purpule,0xff00ff},
    {PuyoID::Ojama,0xaaaaaa}
};

Puyo::Puyo(Vector2 vec, PuyoID id)
{
    _pos = vec;
    _pos1 = _pos;
    _pos2 = _pos;
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
    if (_pos1.y + _size.y / 2 < ((_size.y) + _size.y * 12) || (_pos2.y + _size.y / 2 < (_size.y) + _size.y * 12))
    {
        switch (id)
        {
        case InputID::Up:
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
}

bool Puyo::Updata(void)
{
    if (_pos1.y + _size.y/2 < ((_size.y) + _size.y * 12) || (_pos2.y + _size.y/2 < (_size.y) + _size.y * 12))
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
    }
    return false;
}

void Puyo::Draw(void)
{
    _pos1 = Vector2{ (_pos.x + _size.x) + _size.x / 2, (_pos.y + _size.y) + _size.y / 2 };
    _pos2 = Vector2{ (_pos.x + _size.x) + _size.x / 2, (_pos.y + _size.y) + _size.y + _size.y / 2 };
    DrawCircle(_pos1.x, _pos1.y, _size.x/2, 0xff000, true);
    DrawCircle(_pos2.x, _pos2.y, _size.x / 2, 0xff00ff, true);
}

bool Puyo::SoftDrop(void)
{
    _dropcnt += _dropinter;
    return false;
}

bool Puyo::SetDirParmit(Dirpermit dirparmit)
{
    _olddirparmit = _dirparmit;
    _dirparmit = dirparmit;
    return true;
}

PuyoID Puyo::GetID(void)
{
    return PuyoID((rand() % (static_cast<int>(PuyoID::MAX) - 3)) + 1);
}

const Vector2 Puyo::GetGrid(int size)
{
    return Vector2((_pos.x - size/2)/size, (_pos.y - size/2)/size);
}

const Dirpermit Puyo::dirpermit(void)
{
    return _dirparmit;
}

const Vector2& Puyo::pos(void)
{
    return _pos;
}

void Puyo::pos(Vector2&& pos)
{
    _pos = pos;
}

