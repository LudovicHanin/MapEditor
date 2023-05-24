#include "MouseInputManager.h"
#include <iostream>

using namespace std;

void MouseInputManager::OnMouseClickLeft()
{
	NotifyObservers();
}

void MouseInputManager::Update(const Event & event)
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			cout << "Mouse Click from Update" << endl;
			OnMouseClickLeft();
			return;
		}
	}
}
