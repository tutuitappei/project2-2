#pragma once
#include<mutex>
#include"Vector2.h"

#define lpScene SceneManager::GetInstance()


class SceneManager
{
public:
	static SceneManager& GetInstance()
	{
		static SceneManager sta_Instance;
		return sta_Instance;
	}

	void Run(void);


	Vector2 pos;

private:
	SceneManager();
	~SceneManager();

	int time;
	int color;
	int speed;
	const Vector2 screensize;
	const Vector2 csreenOffset;


	static SceneManager* sta_Instance;
};

