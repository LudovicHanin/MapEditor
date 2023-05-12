#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <string>
#include <Windows.h>
#include <Commdlg.h>
#include <fstream>
#include "TextureManager.h"
#include "EventManager.h"

using namespace sf;
using namespace std;

RectangleShape displayMap[450];

int mapTxt[450];

TextureManager textureManager;

vector<RectangleShape*> textureLoaded;

Texture* textureSelected;

int index = 0;

int capacityTexture = 0;

void MouseInputHandler(Event event, RenderWindow& window);

void CreateShapes();

void ConvertMapToTxt(string path);

string AskPath();

int main()
{
	RenderWindow window(VideoMode(1000, 800), "SFML - Map Editor");

	string map;
	string mapCollision;

	int tileSizeX = 32;
	int tileSizeY = 32;

	int levelSizeX = 25;
	int levelSizeY = 18;

	for (unsigned int y = 0; y < levelSizeY; y++)
	{
		for (unsigned int x = 0; x < levelSizeX; x++)
		{
			int tileIndex = levelSizeX * y + x;

			Vector2f position(tileSizeX * x, tileSizeY * y);
			displayMap[tileIndex].setPosition(position);
			displayMap[tileIndex].setSize(Vector2f(tileSizeX, tileSizeY));
			displayMap[tileIndex].setFillColor(Color::White);
			displayMap[tileIndex].setOutlineColor(Color::Black);
			displayMap[tileIndex].setOutlineThickness(1.f);
		}
	}

	for (size_t i = 0; i < 450; i++)
	{
		mapTxt[i] = 0;
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

			MouseInputHandler(event, window);
		}

		window.clear();

		for (unsigned int i = 0; i < 450; i++)
		{
			window.draw(displayMap[i]);
		}

		for (size_t i = 0; i < capacityTexture; i++)
		{
			window.draw(*textureLoaded[i]);
		}

		window.display();
	}

	return 0;
}

void MouseInputHandler(Event event, RenderWindow& window)
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{

			Vector2i mousePosition = Mouse::getPosition(window);

			for (unsigned int i = 0; i < 450; i++)
			{
				if (displayMap[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y))
				{
					displayMap[i].setTexture(textureLoaded[index]->getTexture());
					displayMap[i].setTextureRect(textureLoaded[index]->getTextureRect());
					mapTxt[i] = index;
					return;
				}
			}

			for (unsigned int i = 0; i < capacityTexture; i++)
			{
				if (textureLoaded[i]->getGlobalBounds().contains(mousePosition.x, mousePosition.y))
				{
					index = i;
					return;
				}
			}

			CreateShapes();
		}

		if (Mouse::isButtonPressed(Mouse::Right))
			ConvertMapToTxt(AskPath());
	}
}

void CreateShapes()
{
	if (!textureManager.SelectNewTexture())
		return;

	Texture* texturePtr = textureManager.GetTexture(capacityTexture);

	int sizeX = texturePtr->getSize().x;
	int sizeY = texturePtr->getSize().y;

	if (sizeX > 32)
	{
		int numberOfTileX = sizeX / 32;
		int numberOfTileY = sizeY / 32;

		for (unsigned int y = 0; y < 5; y++)
		{
			for (size_t x = 0; x < numberOfTileX; x++)
			{
				RectangleShape* newShape = new RectangleShape();

				newShape->setTexture(texturePtr);
				newShape->setTextureRect(IntRect(x * 32, y * 32, 32, 32));
				newShape->setPosition(Vector2f(x * 32, 600 + (y * 32)));
				newShape->setOutlineThickness(1.f);
				newShape->setOutlineColor(Color::Black);

				newShape->setSize(Vector2f(32, 32));

				textureLoaded.push_back(newShape);
				capacityTexture++;
			}
		}

		index = capacityTexture - 1;
	}
	else
	{
		RectangleShape* newTexture = new RectangleShape();


		newTexture->setTexture(texturePtr);
		newTexture->setTextureRect(IntRect(32, 0, 32, 32));

		if (capacityTexture == 0)
		{
			newTexture->setPosition(Vector2f(0, 620));
		}
		else
		{
			newTexture->setPosition(Vector2f(capacityTexture * 32 + (15 * capacityTexture), 620));
		}

		newTexture->setSize(Vector2f(32, 32));

		index = capacityTexture;

		textureLoaded.push_back(newTexture);
		capacityTexture++;
	}
}

void ConvertMapToTxt(string path)
{
	string toCopy;

	for (unsigned int i = 0; i < 450; i++)
	{
		string numStr = to_string(mapTxt[i]);
		for (unsigned int j = 0; j < numStr.length(); j++) {
			toCopy.push_back(numStr[j]);
		}
		toCopy.push_back(' ');
	}

	ofstream file(path, ios::out | ios::binary);
	file << "\xEF\xBB\xBF";
	if (file.is_open())
	{
		file.write(toCopy.c_str(), toCopy.size());

		file.close();
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier." << endl;
	}
}

string AskPath()
{
	OPENFILENAME ofn; // structure pour la boîte de dialogue de sélection de fichier
	char szFileName[MAX_PATH] = ""; // tampon pour stocker le chemin du fichier sélectionné

	ZeroMemory(&ofn, sizeof(ofn)); // initialisation de la structure à zéro
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = "Fichier Textes (*.txt)\0*.txt\0Tous les fichiers (*.*)\0*.*\0";
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = "txt";

	if (GetOpenFileName(&ofn))
	{
		return ofn.lpstrFile;
	}
	else
	{
		std::cout << "Aucun fichier sélectionné." << std::endl;

		return "";
	}

}