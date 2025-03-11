#include "pacman.h"

Pacman::Pacman(Vector2 position, Vector2 velocity, float speed, InputHandler* inputHandler, Map* map)
	: Entity(position, velocity, speed), m_lives(3), m_score(0), m_isInPowerMode(false), m_startPosition(position), 
    m_inputHandler(inputHandler), m_map(map), m_animationSpeed(0.1f), m_frameCounter(0) {
	m_textures[Direction::Up] = { LoadTexture("assets/pacman-up/1.png"), LoadTexture("assets/pacman-up/2.png"), LoadTexture("assets/pacman-up/3.png") };
	m_textures[Direction::Down] = { LoadTexture("assets/pacman-down/1.png"), LoadTexture("assets/pacman-down/2.png"), LoadTexture("assets/pacman-down/3.png") };
	m_textures[Direction::Left] = { LoadTexture("assets/pacman-left/1.png"), LoadTexture("assets/pacman-left/2.png"), LoadTexture("assets/pacman-left/3.png") };
	m_textures[Direction::Right] = { LoadTexture("assets/pacman-right/1.png"), LoadTexture("assets/pacman-right/2.png"), LoadTexture("assets/pacman-right/3.png") };
}

Pacman::~Pacman(){
	for (const auto& spritePair : m_textures) {
		auto spriteList = spritePair.second;
		for (const auto& sprite : spriteList) {
			UnloadTexture(sprite);
		}
	}
}

void Pacman::update(){
	move();
    m_frameCounter++;
	Entity::update();
}

void Pacman::draw() const {
    Direction direction = m_inputHandler->getDirection();
    int frame = (m_frameCounter / (int)(1.0f / m_animationSpeed)) % 3; 
    DrawTexture(m_textures.at(direction)[frame], static_cast<int>(m_position.x), static_cast<int>(m_position.y), WHITE);
}

void Pacman::move() {
    auto direction = m_inputHandler->getDirection();
    Vector2 nextVelocity = { 0, 0 };

    switch (direction) {
    case Direction::Left:
        nextVelocity = { -m_speed, 0 };
        break;
    case Direction::Right:
        nextVelocity = { m_speed, 0 };
        break;
    case Direction::Up:
        nextVelocity = { 0, -m_speed };
        break;
    case Direction::Down:
        nextVelocity = { 0, m_speed };
        break;
    }

    Vector2 nextPosition = { m_position.x + nextVelocity.x, m_position.y + nextVelocity.y };
    Vector2 pacmanSize = { m_textures.at(direction)[0].width, m_textures.at(direction)[0].height };
    if (m_map && !m_map->isWall(nextPosition, pacmanSize)) {
        m_velocity = nextVelocity;
    }
    else {
        m_velocity = { 0, 0 };  
    }
}
