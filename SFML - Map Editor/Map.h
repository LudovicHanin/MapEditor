#ifndef MAP_H
#define MAP_H

#include "SFML/Graphics.hpp"
#include "Button.h"
#include <list>

using namespace sf;
using namespace std;

class Map
{
public:
	Map(Vector2f tileSize, int mapWidth, int mapHeight);
	Map(Vector2f tileSize, int mapWidth, int mapHeight, Color outlineColor, float outlineThickness);

	list<Button*> GetButtons();
private:
	Vector2f tileSize;
	int mapWidth;
	int mapHeight;

	list<Button*> mapTiles;
};

#endif // !MAP_H