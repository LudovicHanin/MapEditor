#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Button.h"

using namespace std;
using namespace sf;

#endif // !BUTTONMANAGER_H



class ButtonManager
{
public:
	static ButtonManager& GetInstance()
	{
		static ButtonManager instance;
		return instance;
	}

	void RegisterButton(Button* newButton);
	void RemoveButton(Button* button);

private:
	list<Button*> buttons;

	ButtonManager() {}
	
	ButtonManager(ButtonManager const&) = delete;
	void operator=(ButtonManager const&) = delete;
};

