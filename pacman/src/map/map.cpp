#include "map.h"

Map::Map(const char* imagePath){
	loadMapFromImage(imagePath);
	if (m_mapGridLayout.empty()) {
		std::cout << "Error loading map from image: " << imagePath << std::endl;
	}
	else {
		m_mapSize = 720;
		m_tileSize = m_mapSize / m_mapGridLayout.size();
	}
}


bool Map::isPath(Vector2 position) const {
	int col = (int)(position.x) / m_tileSize;
	int row = (int)(position.y) / m_tileSize;

	if (row < 0 || row >= m_mapGridLayout.size() || col < 0 || col >= m_mapGridLayout[0].size()) {
		return false;
	}

	return m_mapGridLayout[row][col] == MapField::Path;
}

void Map::draw() const {
	for (int row = 0; row < m_mapGridLayout.size(); ++row) {
		for (int col = 0; col < m_mapGridLayout[row].size(); ++col) {
			if (m_mapGridLayout[row][col] == MapField::Wall) {
				DrawRectangleLines(col * m_tileSize, row * m_tileSize, m_tileSize, m_tileSize, BLUE);
			}
			else if (m_mapGridLayout[row][col] == MapField::Path) {
				DrawRectangle(col * m_tileSize, row * m_tileSize, m_tileSize, m_tileSize, WHITE);
			}
		}
	}
}

void Map::loadMapFromImage(const char* imagePath) {
	Image mapImage = LoadImage(imagePath);
	if (mapImage.data == nullptr) {
		return;
	}
	ImageFormat(&mapImage, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
	Color* pixels = LoadImageColors(mapImage);
	if (pixels == nullptr) {
		return;
	}

	m_mapGridLayout.resize(mapImage.height, std::vector<MapField>(mapImage.width));

	for (int row = 0; row < m_mapGridLayout.size(); row++) {
		for (int col = 0; col < m_mapGridLayout[row].size(); col++) {
			Color pixelColor = pixels[row * mapImage.width + col];
			if (pixelColor.r == 0 && pixelColor.g == 0 && pixelColor.b == 0) {
				m_mapGridLayout[row][col] = MapField::Empty;
			}
			else if (pixelColor.r == 255 && pixelColor.g == 255 && pixelColor.b == 255) {
				m_mapGridLayout[row][col] = MapField::Path;
			}
			else {
				m_mapGridLayout[row][col] = MapField::Wall;
			}
		}
	}
	UnloadImageColors(pixels);
	UnloadImage(mapImage);
}
