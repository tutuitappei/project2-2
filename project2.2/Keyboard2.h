#pragma once
#include "Controller.h"
#include<map>
class Keyboard2 :
	public Controller
{
public:
	Keyboard2();
	~Keyboard2();

	void Update(void) override;
private:
	
	std::map<MoveControll,int> _keydata;
};

