#pragma once

#define lpSysInit System::GetInstance()

class System
{
public:
	static System& GetInstance()
	{
		static System s_Instance;
		return s_Instance;
	}

private:
	System();
	~System();

	static System* s_Instance;
};

