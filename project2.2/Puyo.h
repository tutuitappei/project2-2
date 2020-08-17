#pragma once
#include<map>
#include"input/Inputid.h"
#include"Vector2.h"

enum class PuyoID 
{
	Non,			//�Ȃ�
	Red,			//��
	Blue,			//��
	Green,			//��
	Yellow,			//���F
	Purpule,		//��
	Ojama,			//�������
	Wall,			//��
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

	const Vector2 GetGrid(int size);	//�O���b�h���W�擾
	const Dirpermit dirpermit(void);
	const Vector2& pos(void);			//���W�擾

	void pos(Vector2&& pos);
private:
	static Puyocolor _puyocolor;		//�Ղ�̐F

	Dirpermit _olddirparmit;
	Dirpermit _dirparmit;

	Vector2 _size;						//�T�C�Y
	Vector2 _pos;						//���W
	Vector2 _pos1;						
	Vector2 _pos2;
	PuyoID _id;							//�Ղ��ID

	int _dropcnt;						//�����܂ł̃J�E���g
	int _dropinter;						//�����܂ł̑҂�����
	int _dropspeed;						//�������x
};

