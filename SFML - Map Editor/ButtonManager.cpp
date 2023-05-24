#include "ButtonManager.h"

ButtonManager::ButtonManager(RenderWindow* gameWindow)
{
	window = gameWindow;
}

ButtonManager::~ButtonManager()
{
	for (Button* buttonPtr : buttons)
		delete buttonPtr;

	buttons.clear();
}

void ButtonManager::AddButton(Button * button)
{
	buttons.push_back(button);
}

void ButtonManager::Update()
{
	Vector2i mousePosition = Mouse::getPosition(*window);

	for (Button* button : buttons)
	{
		if (button->DoTouch(mousePosition))
		{
			button->OnButtonPressed();
		}
	}
}

void ButtonManager::Draws(RenderWindow & window)
{
	for (Button* buttonPtr : buttons)
	{
		buttonPtr->Draw(window);
	}
}
