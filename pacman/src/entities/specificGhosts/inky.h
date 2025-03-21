#pragma once

#include "../ghost.h"
#include "blinky.h"

class Inky : public Ghost {
public:
    Inky(Vector2 position, Vector2 velocity, float speed, Map* map, Pacman* pacman, Blinky* blinky);
    void setTarget() override;
    void draw() const override;
	void update() override; 
private:
    Texture2D m_texture;
    const int m_SCALE_FACTOR = 2.0f;
    Blinky* m_blinky;
};


