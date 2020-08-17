#pragma once
#include<map>
#include"input/Inputid.h"
#include"Vector2.h"

enum class PuyoID 
{
	Non,			//ない
	Red,			//赤
	Blue,			//青
	Green,			//緑
	Yellow,			//黄色
	Purpule,		//紫
	Ojama,			//おじゃま
	Wall,			//壁
	MAX
};

struct DirBit
{
	unsigned int up : 1;
	unsigned int down : 1;
	unsigned int left : 1;
	unsigned int right : 1;
};

union Dirpermit
{
	DirBit perBit;
	unsigned int per;

};

using Puyocolor = std::map<PuyoID, int>;

class Puyo
{
public:
	Puyo(Vector2 vec,PuyoID id);
	~Puyo();
	void Move(InputID id);
	void Draw(void);
	bool SoftDrop(void);
	bool Updata(void);

	bool SetDirParmit(Dirpermit dirparmit);

	PuyoID GetID(void);
	//const Vector2& GetPos(void);

	const Vector2 GetGrid(int size);	//グリッド座標取得
	const Dirpermit dirpermit(void);
	const Vector2& pos(void);			//座標取得

	void pos(Vector2&& pos);
private:
	static Puyocolor _puyocolor;		//ぷよの色

	Dirpermit _olddirparmit;
	Dirpermit _dirparmit;

	Vector2 _size;						//サイズ
	Vector2 _pos;						//座標
	Vector2 _pos1;						
	Vector2 _pos2;
	PuyoID _id;							//ぷよのID

	int _dropcnt;						//落下までのカウント
	int _dropinter;						//落下までの待ち時間
	int _dropspeed;						//落下速度
};

