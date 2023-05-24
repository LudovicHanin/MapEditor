#include "Button.h"
#include "ApplicationInstance.h"

void Button::OnButtonPressed()
{
	NotifyObservers(*this);
}

Button::Button()
{
	ApplicationInstance::GetInstance()->buttonManagerInstance->AddButton(this);

}

Button::Button(const Vector2f & position, const Vector2f size)
{
	SetPosition(position);
	SetSize(size);

	ApplicationInstance::GetInstance()->buttonManagerInstance->AddButton(this);
}

Button::Button(const Vector2f & position, const Vector2f size, const Texture & texture, const IntRect & rectSize)
{
	SetPosition(position);
	SetSize(size);
	SetTexture(texture);
	SetRectTexture(rectSize);

	ApplicationInstance::GetInstance()->buttonManagerInstance->AddButton(this);

}

void Button::SetSize(const Vector2f size)
{
	buttonShape.setSize(size);
}

void Button::SetTexture(const Texture & texture)
{
	buttonShape.setTexture(&texture);
}

void Button::SetRectTexture(const IntRect & rectSize)
{
	buttonShape.setTextureRect(rectSize);
}

void Button::SetOutlineThickness(const float & thickness)
{
	buttonShape.setOutlineThickness(thickness);
}

void Button::SetOutlineColor(const Color & color)
{
	buttonShape.setOutlineColor(color);
}

void Button::SetColor(const Color & color)
{
	buttonShape.setFillColor(color);
}

void Button::SetPosition(const Vector2f & position)
{
	buttonShape.setPosition(position);
}

bool Button::DoTouch(const Vector2i & position)
{
	return buttonShape.getGlobalBounds().contains(position.x, position.y);
}

void Button::Draw(RenderWindow & window)
{
	window.draw(buttonShape);
}
