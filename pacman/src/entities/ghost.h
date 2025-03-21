#pragma once

#include "entity.h"
#include "../utils/direction.h"
#include "../map/map.h"
#include "pacman.h"
#include "../utils/timer.h"

enum class GhostState {
	Chase,
	Scatter,
	Frightened,
    Eaten
};

class Ghost : public Entity {
public:
    Ghost(Vector2 position, Vector2 velocity, float speed, Map* map, Pacman* pacman);
    virtual ~Ghost() = default;

    virtual void update() override;
    virtual void draw() const = 0;

protected:
	virtual void setTarget() = 0;
    void setState();
protected:
    Vector2 m_target;
    Map* m_map;
	Pacman* m_pacman;
	GhostState m_state;
    Timer m_timer;
};