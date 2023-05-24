#include "TextureManager.h"

void TextureManager::LoadTexture(string & texturePath)
{
	if (!selectedTexture) selectedTexture = new Texture();

	if (!selectedTexture->loadFromFile(texturePath))
	{
		MessageBox(NULL, "Unable to load the texture", "Erreur",
			MB_OK | MB_ICONERROR);
	}
}

//bool TextureManager::SelectNewTexture()
//{
//	OPENFILENAME ofn; 
//	char szFileName[MAX_PATH] = ""; 
//
//	ZeroMemory(&ofn, sizeof(ofn)); 
//	ofn.lStructSize = sizeof(ofn);
//	ofn.hwndOwner = NULL;
//	ofn.lpstrFilter = "Textures (*.png)\0*.png\0Tous les fichiers (*.*)\0*.*\0";
//	ofn.lpstrFile = szFileName;
//	ofn.nMaxFile = MAX_PATH;
//	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
//	ofn.lpstrDefExt = "png";
//
//	if (GetOpenFileName(&ofn)) 
//	{
//		string path = ofn.lpstrFile;
//		//texturePath.push_back(path);
//		LoadTexture(path);
//
//		return true;
//	}
//	else 
//	{
//		std::cout << "Aucun fichier sélectionné." << std::endl;
//
//		return false;
//	}
//
//}

TextureManager::TextureManager()
{
	if (!selectedTexture)
	{
		selectedTexture = new Texture;
	}

	if (!selectedTexture->loadFromFile("res/tileset.png"))
	{
		cout << "Texture not loaded" << endl;
	}

	coordTexture = IntRect(0, 0, 32, 32);
}

Texture* TextureManager::GetTexture()
{
	return selectedTexture;
}

void TextureManager::SwitchTextureCoordonate(Button* targetButton)
{
	//targetButton->GetShape().setTextureRect(coordTexture);
}

void TextureManager::Update(Button & buttonRef)
{
	buttonRef.SetTexture(*selectedTexture);
	buttonRef.SetRectTexture(coordTexture);
}
