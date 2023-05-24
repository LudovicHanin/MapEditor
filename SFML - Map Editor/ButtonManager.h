#ifndef BUTTONMANAGER
#define BUTTONMANAGER

#include "MouseInputManager.h"
#include "Button.h"
#include <vector>

using namespace std;

class ButtonManager : public Observer<>
{
public:
	ButtonManager(RenderWindow* gameWindow);
	~ButtonManager();

	void AddButton(Button* button);

	void Update();

	void Draws(RenderWindow& window);

private:
	vector<Button*> buttons;

	RenderWindow* window;
};

#endif // !BUTTONMANAGER