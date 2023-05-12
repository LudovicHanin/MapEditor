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

	TextureManager();
	~TextureManager();

	TextureManager(TextureManager const&) = delete;
	void operator=(TextureManager const&) = delete;

public:
	static TextureManager& GetInstance()
	{
		static TextureManager instance;
		return instance;
	}



	bool SelectNewTexture();

	Texture* GetTexture(int index);
};

