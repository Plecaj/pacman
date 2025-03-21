#include "inky.h"
#include "raylib.h"

Inky::Inky(Vector2 position, Vector2 velocity, float speed, Map* map, Pacman* pacman, Blinky* blinky)
    : Ghost(position, velocity, speed, map, pacman), m_blinky(blinky) {
    m_texture = LoadTexture("assets/ghosts/inky.png");
}

void Inky::update(){
	setTarget();
	Ghost::update();
}

void Inky::setTarget() {
    if (m_state == GhostState::Chase) {
        Vector2 pacmanPosition = m_pacman->getPosition();
        Vector2 pacmanVelocity = m_pacman->getVelocity();
        Vector2 targetPosition = { pacmanPosition.x + 2.0f * pacmanVelocity.x, pacmanPosition.y + 2.0f * pacmanVelocity.y };
		Vector2 blinkyPosition = m_blinky->getPosition();
        m_target = { 2.0f * (targetPosition.x - blinkyPosition.x), 2.0f * (targetPosition.y - blinkyPosition.y) };
    }
    else if (m_state == GhostState::Scatter) {
        m_target = { 630.0f, 750.0f };
    }
}

void Inky::draw() const {
    Rectangle sourceRec = { 0.0f, 0.0f, (float)m_texture.width, (float)m_texture.height };
    Rectangle destRec = { m_position.x, m_position.y, (float)m_texture.width * m_SCALE_FACTOR, (float)m_texture.height * m_SCALE_FACTOR };
    Vector2 origin = { (float)m_texture.width * m_SCALE_FACTOR / 2.0f, (float)m_texture.height * m_SCALE_FACTOR / 2.0f };

    DrawTexturePro(m_texture, sourceRec, destRec, origin, 0.0f, WHITE);
    DrawRectangle((int)m_target.x, (int)m_target.y, 5, 5, SKYBLUE);
}


