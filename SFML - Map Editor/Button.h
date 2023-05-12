#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "EventManager.h"
#include "ButtonManager.h"

using namespace std;
using namespace sf;

#endif // !BUTTON_H

class Button
{
public:
	Button(string eventName);
	~Button();

	string GetEventName() const;

private:
	string onButtonPressedEventName;

	RectangleShape* buttonShape;

	void OnButtonPressed();
	//void OnButtonReleased();
};

