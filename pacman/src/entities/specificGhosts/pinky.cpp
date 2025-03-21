#include "pinky.h"
#include "raylib.h"

Pinky::Pinky(Vector2 position, Vector2 velocity, float speed, Map* map, Pacman* pacman)
    : Ghost(position, velocity, speed, map, pacman) {
    m_texture = LoadTexture("assets/ghosts/pinky.png");
}

void Pinky::update(){
	setTarget();
	Ghost::update();
}

void Pinky::setTarget() {
    if (m_state == GhostState::Chase) {
        Vector2 pacmanPosition = m_pacman->getPosition();
        Vector2 pacmanVelocity = m_pacman->getVelocity();
        m_target = { pacmanPosition.x + 4.0f * pacmanVelocity.x, pacmanPosition.y + 4.0f * pacmanVelocity.y };
    }
    else if (m_state == GhostState::Scatter) {
        m_target = { 0.0f, 0.0f };
    }
}

void Pinky::draw() const {
    Rectangle sourceRec = { 0.0f, 0.0f, (float)m_texture.width, (float)m_texture.height };
    Rectangle destRec = { m_position.x, m_position.y, (float)m_texture.width * m_SCALE_FACTOR, (float)m_texture.height * m_SCALE_FACTOR };
    Vector2 origin = { (float)m_texture.width * m_SCALE_FACTOR / 2.0f, (float)m_texture.height * m_SCALE_FACTOR / 2.0f };

    DrawTexturePro(m_texture, sourceRec, destRec, origin, 0.0f, WHITE);
    DrawRectangle((int)m_target.x, (int)m_target.y, 5, 5, PINK);
}


