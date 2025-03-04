#pragma once

#include "../utils/direction.h"

class InputHandler {
public:
    InputHandler();
    Direction getDirection();

private:
    Direction m_lastDirection;
};