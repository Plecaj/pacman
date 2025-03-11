#pragma once

#include <vector>
#include <iostream>
#include "raylib.h"

enum class MapField {
	Empty,
	Wall,
};

class Map {
public:
	Map(const char* imagePath);
	bool isWall(Vector2 position, Vector2 size) const;
	void draw() const;
private:
	void loadMapFromImage(const char* imagePath);
private:
	std::vector<std::vector<MapField>> m_mapGridLayout;
	int m_mapSize;
	int m_tileSize;
};