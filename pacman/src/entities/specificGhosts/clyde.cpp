#include "clyde.h"
#include "raylib.h"

Clyde::Clyde(Vector2 position, Vector2 velocity, float speed, Map* map, Pacman* pacman)
    : Ghost(position, velocity, speed, map, pacman) {
    m_texture = LoadTexture("assets/ghosts/clyde.png");
}

void Clyde::setTarget() {
    if (m_state == GhostState::Chase) {
        Vector2 pacmanPosition = m_pacman->getPosition();
        double distance = std::sqrt(std::pow(m_position.x - pacmanPosition.x, 2) + std::pow(m_position.y - pacmanPosition.y, 2));
        if (distance <= 8.0 * m_map->getTileSize()) {
            m_target = { 0.0f, 750.0f };
        }
        else {
            m_target = pacmanPosition;
        }
    }
    else if (m_state == GhostState::Scatter) {
        m_target = { 0.0f, 750.0f };
    }
}

void Clyde::draw() const {
    Rectangle sourceRec = { 0.0f, 0.0f, (float)m_texture.width, (float)m_texture.height };
    Rectangle destRec = { m_position.x, m_position.y, (float)m_texture.width * m_SCALE_FACTOR, (float)m_texture.height * m_SCALE_FACTOR };
    Vector2 origin = { (float)m_texture.width * m_SCALE_FACTOR / 2.0f, (float)m_texture.height * m_SCALE_FACTOR / 2.0f };

    DrawTexturePro(m_texture, sourceRec, destRec, origin, 0.0f, WHITE);
    DrawRectangle((int)m_target.x, (int)m_target.y, 5, 5, ORANGE);
}

void Clyde::update(){
    setTarget();
    Ghost::update();
}
