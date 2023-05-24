#ifndef MAIN
#define MAIN

#include <SFML/Graphics.hpp>
#include <iostream>
#include "MouseInputManager.h"
#include "ButtonManager.h"
#include "ApplicationInstance.h"
#include "Map.h"
#include "TextureManager.h"

using namespace sf;
using namespace std;

#endif // !MAIN

RectangleShape displayMap[450];

int mapTxt[450];

vector<RectangleShape*> textureLoaded;

Texture* textureSelected;

int index = 0;

int capacityTexture = 0;

//void MouseInputHandler(Event event, RenderWindow& window);
//
//void ConvertMapToTxt(string path);
//string AskPath();

class TestObserver : public Observer<Button&>
{
public:
	void Update(Button& buttonRef) override
	{
		buttonRef.SetColor(Color::Red);
	}
};

int main()
{
	RenderWindow window(VideoMode(1000, 800), "SFML - Map Editor");
	MouseInputManager mouseInputManager;
	ButtonManager buttonManager(&window);
	ApplicationInstance::GetInstance()->buttonManagerInstance = &buttonManager;
	Map map(Vector2f(32, 32), 25, 18);
	TextureManager textureManager;
	list<Button*> mapTiles = map.GetButtons();

	mouseInputManager.AddObserver(&buttonManager);

	for (Button* buttonPtr : mapTiles)
	{
		buttonPtr->AddObserver(&textureManager);
	}

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::Resized)
				window.setSize(Vector2u(800, 576));

			mouseInputManager.Update(event);
		}

		window.clear();

		buttonManager.Draws(window);

		window.display();
	}

	return 0;
}

//void MouseInputHandler(Event event, RenderWindow& window)
//{
//	if (event.type == Event::MouseButtonPressed)
//	{
//		if (Mouse::isButtonPressed(Mouse::Left))
//		{
//			Vector2i mousePosition = Mouse::getPosition(window);
//		}
//
//		//if (Mouse::isButtonPressed(Mouse::Right))
//		//	ConvertMapToTxt(AskPath());
//	}
//}

//void ConvertMapToTxt(string path)
//{
//	string toCopy;
//
//	for (unsigned int i = 0; i < 450; i++)
//	{
//		string numStr = to_string(mapTxt[i]);
//		for (unsigned int j = 0; j < numStr.length(); j++) {
//			toCopy.push_back(numStr[j]);
//		}
//		toCopy.push_back(' ');
//	}
//
//	ofstream file(path, ios::out | ios::binary);
//	file << "\xEF\xBB\xBF";
//	if (file.is_open())
//	{
//		file.write(toCopy.c_str(), toCopy.size());
//
//		file.close();
//	}
//	else
//	{
//		cout << "Impossible d'ouvrir le fichier." << endl;
//	}
//}

//string AskPath()
//{
//	OPENFILENAME ofn; // structure pour la boîte de dialogue de sélection de fichier
//	char szFileName[MAX_PATH] = ""; // tampon pour stocker le chemin du fichier sélectionné
//
//	ZeroMemory(&ofn, sizeof(ofn)); // initialisation de la structure à zéro
//	ofn.lStructSize = sizeof(ofn);
//	ofn.hwndOwner = NULL;
//	ofn.lpstrFilter = "Fichier Textes (*.txt)\0*.txt\0Tous les fichiers (*.*)\0*.*\0";
//	ofn.lpstrFile = szFileName;
//	ofn.nMaxFile = MAX_PATH;
//	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
//	ofn.lpstrDefExt = "txt";
//
//	if (GetOpenFileName(&ofn))
//	{
//		return ofn.lpstrFile;
//	}
//	else
//	{
//		std::cout << "Aucun fichier sélectionné." << std::endl;
//
//		return "";
//	}
//
//}