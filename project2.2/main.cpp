#include<DxLib.h>
#include"Vector2.h"
#include"_debug/_DebugConOut.h"
#include"_debug/_DebugDispOut.h"
#include"SceneManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

		SetGraphMode(640, 480, 16);								// 640*480ﾄﾞｯﾄ、65536色ﾓｰﾄﾞに設定
		ChangeWindowMode(true);									// true:window false:ﾌﾙｽｸﾘｰﾝ
	
		SetWindowText("PUYOPUYO");
		if (DxLib_Init() == -1)									// DXﾗｲﾌﾞﾗﾘの初期化処理
		{
			return false;
		}
		lpScene.GetInstance().Run();
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}
