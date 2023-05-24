#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Button.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <Windows.h>
#include <Commdlg.h>

using namespace sf;
using namespace std;

class TextureManager : public Observer<Button&>
{
public:
	TextureManager();

	Texture* GetTexture();

	void SwitchTextureCoordonate(Button* targetButton);
	
	void Update(Button& buttonRef) override;
private:
	list<string> texturesPaths;
	Texture* selectedTexture;
	IntRect coordTexture;

	void LoadTexture(string& texturePath);
};

#endif // !TEXTUREMANAGER_H