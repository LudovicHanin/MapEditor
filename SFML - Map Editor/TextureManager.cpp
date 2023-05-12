#include "TextureManager.h"

void TextureManager::LoadTexture(string & texturePath)
{
	Texture* newTexture = new Texture();

	if (newTexture->loadFromFile(texturePath))
	{
		textures.push_back(newTexture);

		MessageBox(NULL, texturePath.c_str(), "Texture Loaded", MB_OK);
	}
	else
	{
		MessageBox(NULL, "The texture wasn't able to be loaded.", "Erreur", MB_OK | MB_ICONERROR);
	}
}

TextureManager::~TextureManager()
{
	for (Texture* texturePtr : textures)
	{
		delete texturePtr;
	}

	textures.clear();
}

TextureManager::TextureManager()
{
}

bool TextureManager::SelectNewTexture()
{
	OPENFILENAME ofn; // structure pour la boîte de dialogue de sélection de fichier
	char szFileName[MAX_PATH] = ""; // tampon pour stocker le chemin du fichier sélectionné

	ZeroMemory(&ofn, sizeof(ofn)); // initialisation de la structure à zéro
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = "Textures (*.png)\0*.png\0Tous les fichiers (*.*)\0*.*\0";
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = "png";

	if (GetOpenFileName(&ofn)) 
	{
		string path = ofn.lpstrFile;
		texturePath.push_back(path);
		LoadTexture(path);

		return true;
	}
	else 
	{
		std::cout << "Aucun fichier sélectionné." << std::endl;

		return false;
	}

}

Texture* TextureManager::GetTexture(int index)
{
	if (textures.empty())
		SelectNewTexture();

	if (textures.capacity() - 1 < index)
		return textures.back();

	return textures[index];
}
