#ifndef MOUSEINPUTMANAGER
#define MOUSEINPUTMANAGER

#include "Subject.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class MouseInputManager : public Subject<>
{
public:
	void OnMouseClickLeft();

	void Update(const Event& event);
private:
};

#endif // !MOUSEINPUTMANAGER
