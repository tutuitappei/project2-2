#pragma once
#include "Controller.h"
class Keyboard1 :
	public Controller
{
public:
	Keyboard1();
	~Keyboard1();

	void Update(void) override;
private:
};

