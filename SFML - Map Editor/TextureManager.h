#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <Commdlg.h>

using namespace sf;
using namespace std;

#endif // !TEXTUREMANAGER_H

class TextureManager
{

private:
	vector<string> texturePath;
	vector<Texture*> textures;

	void LoadTexture(string& texturePath);

	~TextureManager();

public:
	TextureManager();

	bool SelectNewTexture();

	Texture* GetTexture(int index);
};

