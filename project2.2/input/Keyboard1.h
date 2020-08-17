#pragma once
#include<array>
#include "Controller.h"
struct Keyboard1 :
	public Controller
{
public:

	ContType GetType(void) override;
	bool Setup(int no) override;

	void Update(void) override;
private:
	std::array<char, 256>_KeyData;		//�L�[�̃f�[�^
	std::map<InputID, int>_inputTbl;	//�C���v�b�g�p�e�[�u��
};

