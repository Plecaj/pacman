#pragma once

#include <vector>
#include <iostream>
#include "raylib.h"

enum class MapField {
	Empty,
	Wall,
	Path,
};

class Map {
public:
	Map(const char* imagePath);
	bool isPath(Vector2 position) const;
	void draw() const;
	int getTileSize() const { return m_tileSize; };
	int getMapSize() const { return m_mapSize; };
private:
	void loadMapFromImage(const char* imagePath);
private:
	std::vector<std::vector<MapField>> m_mapGridLayout;
	int m_mapSize;
	int m_tileSize;
};