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
	bool InstancePuyo(void);	//ノーマルインスタンスする奴
	bool OjamaInstance(void);	//お邪魔インスタンスする奴
	bool GameOverCheck(void);	//ゲームオーバーチェック
	bool SetWall(void);			//壁配置
	bool EleseData(void);		//消すぷよ判定する奴
	void Deletopuyo(void);		//ぷよ消す奴

	int _screenID;				//スクリーンID
	Vector2 _offset;			//オフセットサイズ
	Vector2 _size;				//スクリーンサイズ

	StgMode _stgmode;			//ステージの状況

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

	int _blocksize;			//1マスの大きさ
	int count;

	static int _stagecount;	//ステージ用カウント
	int _id;				//プレイヤー用ID
	int _color;				//色

	int _maxrensa;			//最大連鎖数
	int _rensa;				//連鎖数
	int _erasenum;			//erase数
	int _ojamanum;			//お邪魔の数

	bool _ojamaFlag;		//お邪魔用のフラグ

	friend PlayUnit;
	friend Dorop;
	friend Elase;
	friend Munyon;
	friend Puyon;
	friend Fall;
};

