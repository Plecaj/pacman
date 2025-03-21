#pragma once

#include "../ghost.h"

class Clyde : public Ghost {
public:
    Clyde(Vector2 position, Vector2 velocity, float speed, Map* map, Pacman* pacman);
    void setTarget() override;
    void draw() const override;
	void update() override;
private:
    Texture2D m_texture;
    const int m_SCALE_FACTOR = 2.0f;
};


