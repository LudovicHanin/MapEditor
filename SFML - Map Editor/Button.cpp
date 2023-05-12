#include "Button.h"

Button::Button(string eventName)
{
	onButtonPressedEventName = eventName;

	ButtonManager::GetInstance().RegisterButton(this);
}

Button::~Button()
{
	ButtonManager::GetInstance().RemoveButton(this);
}

string Button::GetEventName() const
{
	return onButtonPressedEventName;
}

void Button::OnButtonPressed()
{
	EventManager::GetInstance().TriggerEvent(onButtonPressedEventName);
}
