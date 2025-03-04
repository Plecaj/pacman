#pragma once

#include "raylib.h"

class Entity {
public:
    Entity(Vector2 position, Vector2 velocity, float speed)
        : m_position(position), m_velocity(velocity), m_speed(speed), m_isActive(true) {
    }

    virtual void update() {
        m_position.x += m_velocity.x * m_speed;
        m_position.y += m_velocity.y * m_speed;
    }

    virtual void draw() const = 0;

    Vector2 getPosition() const { return m_position; }
    void setPosition(const Vector2& position) { m_position = position; }

    Vector2 getVelocity() const { return m_velocity; }
    void setVelocity(const Vector2& velocity) { m_velocity = velocity; }

    float getSpeed() const { return m_speed; }
    void setSpeed(float speed) { m_speed = speed; }

    bool getIsActive() const { return m_isActive; }
    void setIsActive(bool isActive) { m_isActive = isActive; }

protected:
    Vector2 m_position;
    Vector2 m_velocity;
    float m_speed;
    bool m_isActive;
};