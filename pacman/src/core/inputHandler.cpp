#include "inputHandler.h"

#include "raylib.h"

InputHandler::InputHandler() : m_lastDirection(Direction::Right), m_queuedDirection(Direction::Right) {}

Direction InputHandler::getDirection() {
    if (IsKeyDown(KEY_LEFT)) m_lastDirection = Direction::Left;
    else if (IsKeyDown(KEY_RIGHT)) m_lastDirection = Direction::Right;
    else if (IsKeyDown(KEY_UP)) m_lastDirection = Direction::Up;
    else if (IsKeyDown(KEY_DOWN)) m_lastDirection = Direction::Down;

    return m_lastDirection;
}

Direction InputHandler::getQueuedDirection() const {
    return m_queuedDirection;
}

void InputHandler::setQueuedDirection(Direction direction) {
    m_queuedDirection = direction;
}
