#include "ghost.h"
#include "raylib.h"

#include <algorithm>

Ghost::Ghost(Vector2 position, Vector2 velocity, float speed, Map* map, Pacman* pacman)
    : Entity(position, velocity, speed), m_target({ 100.0f, 100.0f }), m_map(map), m_state(GhostState::Scatter), m_pacman(pacman), m_timer() {
    srand(time(NULL));
}

void Ghost::update() {
    setState();
    std::vector<Vector2> possibleDirections;
    Vector2 currentDirection = m_velocity;

    if (currentDirection.x != 0) {
        possibleDirections.push_back({ currentDirection.x, 0 });
        possibleDirections.push_back({ 0, m_speed });
        possibleDirections.push_back({ 0, -m_speed });
    }
    else if (currentDirection.y != 0) {
        possibleDirections.push_back({ 0, currentDirection.y });
        possibleDirections.push_back({ m_speed, 0 });
        possibleDirections.push_back({ -m_speed, 0 });
    }

    std::vector<std::pair<Vector2, float>> distances;
    for (const auto& direction : possibleDirections) {
        Vector2 nextPosition = { m_position.x + direction.x, m_position.y + direction.y };
        if (m_map->isPath(nextPosition)) {
            float distance = std::sqrt(std::pow(nextPosition.x - m_target.x, 2) + std::pow(nextPosition.y - m_target.y, 2));
            distances.push_back({ direction, distance });
        }
    }
    if (!distances.empty()) {
        auto minElement = std::min_element(distances.begin(), distances.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
            });
        m_velocity = minElement->first;
    }
    else {
        m_velocity = { 0, 0 };
    }

    m_position.x += m_velocity.x;
    m_position.y += m_velocity.y;
}

void Ghost::setState() {
    if (m_state == GhostState::Chase && m_timer.getElapsedSeconds() >= 20.0f) {
        m_state = GhostState::Scatter;
        m_timer.reset();
    }
    else if (m_state == GhostState::Scatter && m_timer.getElapsedSeconds() >= 7.0f) {
        m_state = GhostState::Chase;
        m_timer.reset();
    }
}