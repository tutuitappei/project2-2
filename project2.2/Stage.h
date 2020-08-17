#pragma once
#include<vector>
#include<memory>
#include<list>
#include"Vector2.h"
#include"input/Controller.h"
#include"Puyo.h"


//class Vector2

#define STAGE_SIZE_X 8
#define STAGE_SIZE_Y 14

class NextPuyo;
class PlayUnit;

struct Dorop;
struct Elase;
struct Puyon;
struct Munyon;
struct Fall;

enum class StgMode
{
	DROP,
	PUYON,
	ELASE,
	MOVE,
	MUNYON,
	MAX
};

using Sharepuyo = std::shared_ptr<Puyo>;
using Unipuyo = std::unique_ptr<Puyo>;

class Stage
{
public:
	Stage();
	Stage(Vector2&& offset, Vector2&& size);
	~Stage();

	int GetStageDraw(void);
	void Draw(void);
	void Updata(void);
private:
	bool init(void);
	bool InstancePuyo(void);	//�m�[�}���C���X�^���X����z
	bool OjamaInstance(void);	//���ז��C���X�^���X����z
	bool GameOverCheck(void);	//�Q�[���I�[�o�[�`�F�b�N
	bool SetWall(void);			//�ǔz�u
	bool EleseData(void);		//�����Ղ攻�肷��z
	void Deletopuyo(void);		//�Ղ�����z

	int _screenID;				//�X�N���[��ID
	Vector2 _offset;			//�I�t�Z�b�g�T�C�Y
	Vector2 _size;				//�X�N���[���T�C�Y

	StgMode _stgmode;			//�X�e�[�W�̏�

	Unipuyo puyo;
	std::vector<Sharepuyo> PuyoVec;

	std::unique_ptr<Controller> controller;
	std::unique_ptr<NextPuyo> nextpuyo;

	std::vector<Sharepuyo*> _data;
	std::vector<Sharepuyo> _dataBase;
	std::vector<Sharepuyo*> _erasedata;
	std::vector<Sharepuyo> _erasedataBase;

	std::list<Sharepuyo> OjamaList;

	//std::vector<int*> _data;
	//std::vector<int> _dataBase;
	//std::vector<int*> _erasedataBase;

	int _blocksize;			//1�}�X�̑傫��
	int count;

	static int _stagecount;	//�X�e�[�W�p�J�E���g
	int _id;				//�v���C���[�pID
	int _color;				//�F

	int _maxrensa;			//�ő�A����
	int _rensa;				//�A����
	int _erasenum;			//erase��
	int _ojamanum;			//���ז��̐�

	bool _ojamaFlag;		//���ז��p�̃t���O

	friend PlayUnit;
	friend Dorop;
	friend Elase;
	friend Munyon;
	friend Puyon;
	friend Fall;
};

