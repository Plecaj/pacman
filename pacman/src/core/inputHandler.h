#pragma once

#include "../utils/direction.h"

class InputHandler {
public:
    InputHandler();
    Direction getDirection();
    Direction getQueuedDirection() const;
    void setQueuedDirection(Direction direction);

private:
    Direction m_lastDirection;
    Direction m_queuedDirection;
};