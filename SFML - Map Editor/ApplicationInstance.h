#ifndef APPLICATIONINSTANCE
#define APPLICATIONINSTANCE

#include "ButtonManager.h"

class ApplicationInstance
{
public:
	static ApplicationInstance* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new ApplicationInstance();
		}
		return instance;
	}

	ButtonManager* buttonManagerInstance;

private:
	static ApplicationInstance* instance;

	ApplicationInstance(){}
};

#endif // !APPLICATIONINSTANCE
