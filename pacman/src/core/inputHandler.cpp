#include "inputHandler.h"

#include "raylib.h"

InputHandler::InputHandler() : m_lastDirection(Direction::Right), m_queuedDirection(Direction::Right) {}

Direction InputHandler::getDirection() {
    if (IsKeyDown(KEY_LEFT)) m_queuedDirection = Direction::Left;
    else if (IsKeyDown(KEY_RIGHT)) m_queuedDirection = Direction::Right;
    else if (IsKeyDown(KEY_UP)) m_queuedDirection = Direction::Up;
    else if (IsKeyDown(KEY_DOWN)) m_queuedDirection = Direction::Down;

    return m_lastDirection;
}

void InputHandler::setDirection(Direction direction){
	m_lastDirection = direction;    
}

Direction InputHandler::getQueuedDirection() const {
    return m_queuedDirection;
}

void InputHandler::setQueuedDirection(Direction direction) {
    m_queuedDirection = direction;
}
