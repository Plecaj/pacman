#pragma once

enum class Direction { 
    None, 
    Up, Down, 
    Left, 
    Right 
};

class InputHandler {
public:
    InputHandler();
    Direction GetDirection();

private:
    Direction m_lastDirection;
};