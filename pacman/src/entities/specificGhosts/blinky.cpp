#include "blinky.h"
#include "raylib.h"

Blinky::Blinky(Vector2 position, Vector2 velocity, float speed, Map* map, Pacman* pacman)
    : Ghost(position, velocity, speed, map, pacman) {
    m_texture = LoadTexture("assets/ghosts/blinky.png");
}

void Blinky::update() {
	setTarget();
	Ghost::update();    
}


void Blinky::setTarget() {
    if (m_state == GhostState::Chase) {
        m_target = m_pacman->getPosition();
    }
    else if (m_state == GhostState::Scatter) {
        m_target = { 630.0f, 0.0f };
    }
}

void Blinky::draw() const {
    Rectangle sourceRec = { 0.0f, 0.0f, (float)m_texture.width, (float)m_texture.height };
    Rectangle destRec = { m_position.x, m_position.y, (float)m_texture.width * m_SCALE_FACTOR, (float)m_texture.height * m_SCALE_FACTOR };
    Vector2 origin = { (float)m_texture.width * m_SCALE_FACTOR / 2.0f, (float)m_texture.height * m_SCALE_FACTOR / 2.0f };

    DrawTexturePro(m_texture, sourceRec, destRec, origin, 0.0f, WHITE);
	DrawRectangle((int)m_target.x, (int)m_target.y, 5, 5, RED);
}
