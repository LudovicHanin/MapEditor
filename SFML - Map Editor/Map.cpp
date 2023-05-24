#include "Map.h"
#include "TextureManager.h"
#include <string>

Map::Map(Vector2f tileSize, int mapWidth, int mapHeight)
{
	this->tileSize = tileSize;
	this->mapWidth = mapWidth;
	this->mapHeight = mapHeight;

	int numberOfTile = mapWidth * mapHeight;

	for (unsigned int y = 0; y < mapHeight; y++)
	{
		for (unsigned int x = 0; x < mapWidth; x++)
		{
			int indexTile = mapWidth * y + x;
			string buttonEventName = "Tile";
			string numStr = to_string(indexTile);

			for (unsigned int j = 0; j < numStr.length(); j++) {
				buttonEventName.push_back(numStr[j]);
			}

			Button* buttonPtr = new Button(Vector2f(x * tileSize.x, y * tileSize.y), tileSize);
			buttonPtr->SetOutlineThickness(1);
			buttonPtr->SetOutlineColor(Color::Black);

			mapTiles.push_back(buttonPtr);
		}
	}
}

Map::Map(Vector2f tileSize, int mapWidth, int mapHeight, Color outlineColor, float outlineThickness)
{
	this->tileSize = tileSize;
	this->mapWidth = mapWidth;
	this->mapHeight = mapHeight;

	int numberOfTile = mapWidth * mapHeight;

	for (unsigned int y = 0; y < mapHeight; y++)
	{
		for (unsigned int x = 0; x < mapWidth; x++)
		{
			int indexTile = mapWidth * y + x;
			string buttonEventName = "Tile";
			string numStr = to_string(indexTile);

			for (unsigned int j = 0; j < numStr.length(); j++) {
				buttonEventName.push_back(numStr[j]);
			}

			//Button::ButtonSettings settings;
			//settings.position = Vector2f(x * tileSize.x, y * tileSize.y);
			//settings.size = tileSize;
			//settings.outlineColor = outlineColor;
			//settings.outlineThickness = outlineThickness;

			//Button* buttonPtr = new Button(buttonEventName, settings);
		}
	}


}

list<Button*> Map::GetButtons()
{
	return mapTiles;
}
