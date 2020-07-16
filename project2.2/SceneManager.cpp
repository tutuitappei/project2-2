#include<DxLib.h>
#include"Vector2.h"
#include "SceneManager.h"
#include"Stage.h"

void SceneManager::Run(void)
{
	//for(auto&& ����:�~�~ )
	//{
	//}

	DrawLine(screensize.x / 2, 0, screensize.x / 2, screensize.y, color);
	DrawLine(20, 0, 20, screensize.y, color);
	DrawLine(620, 0, 620, screensize.y, color);
	DrawLine(0, 40, screensize.x, 40, color);
	DrawLine(0, 460, screensize.x, 460, color);
	DrawBox(60, 55, 240, 450, color, false);
	DrawBox(245, 55, 285, 135, color, false);


	stage->Updata();
}

SceneManager::SceneManager(): pos(75, 70), screensize(640, 480), time(0), color(0xffffff), speed(0)
{

	Vector2 offset;
	Vector2 size;
	stage = std::make_unique<Stage>(std::move(offset), std::move(size));
}

SceneManager::~SceneManager()
{
}
