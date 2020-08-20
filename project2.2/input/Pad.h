#pragma once
#include<array>
#include"../Vector2.h"
#include "Controller.h"
class Pad :
	public Controller
{
public:

	ContType GetType(void) override;
	bool Setup(int no) override;

	void Update(void) override;
private:
	std::array<char, 28>_PadData;		//�L�[�̃f�[�^
	std::map<InputID, int>_inputTbl;	//�C���v�b�g�p�e�[�u��
};

