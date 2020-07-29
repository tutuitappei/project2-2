#include<DxLib.h>
#include"Vector2.h"
#include "SceneManager.h"
#include"Stage.h"

void SceneManager::Run(void)
{
	//for(auto&& ››:~~ )
	//{
	//}

	SetDrawScreen(DX_SCREEN_BACK);							// •`‰ææ‚ðÊÞ¯¸ÊÞ¯Ì§‚ÉÝ’è
	ClsDrawScreen();										// ‰æ–Ê‚ÌÁ‹Ž


	DrawBox(60, 55, 240, 450, color, false);
	DrawBox(245, 55, 285, 135, color, false);


	stage->Updata();


	ScreenFlip();
}

SceneManager::SceneManager(): pos(75, 70), screensize(640, 480), time(0), color(0xffffff), speed(0)
{

	Vector2 offset(100,100);
	Vector2 size(32,32);
	stage = std::make_unique<Stage>(std::move(offset), std::move(size));
}

SceneManager::~SceneManager()
{
}
