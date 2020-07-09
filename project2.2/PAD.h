#pragma once
#include "Controller.h"
class PAD :
	public Controller
{
public:
	PAD();
	~PAD();
	void Update(void) override;
private:
};

