#ifndef BUTTON
#define BUTTON

#include "Subject.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class Button : public Subject<Button&>
{
public:
	void OnButtonPressed();
	Button();
	Button(const Vector2f& position, const Vector2f size);
	Button(const Vector2f& position, const Vector2f size, const Texture& texture, const IntRect& rectSize);

	void SetSize(const Vector2f size);
	void SetTexture(const Texture& texture);
	void SetRectTexture(const IntRect& rectSize);
	void SetOutlineThickness(const float& thickness);
	void SetOutlineColor(const Color& color);
	void SetColor(const Color& color);
	void SetPosition(const Vector2f& position);

	bool DoTouch(const Vector2i& position);

	void Draw(RenderWindow& window);

private:
	RectangleShape buttonShape;
};
#endif // !BUTTON

