#include "ButtonManager.h"

void ButtonManager::RegisterButton(Button * newButton)
{
	buttons.push_back(newButton);
}

void ButtonManager::RemoveButton(Button * button)
{
	buttons.remove(button);
}
