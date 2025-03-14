#include "pacman.h"

Pacman::Pacman(Vector2 position, Vector2 velocity, float speed, InputHandler* inputHandler, Map* map)
	: Entity(position, velocity, speed), m_lives(3), m_score(0), m_isInPowerMode(false), m_startPosition(position), 
    m_inputHandler(inputHandler), m_map(map), m_animationSpeed(0.1f), m_frameCounter(0) 
{
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
	setVelocity();
    m_frameCounter++;
	Entity::update();
}

void Pacman::draw() const {
    Direction direction = m_inputHandler->getDirection();
    int frame = (m_frameCounter / (int)(1.0f / m_animationSpeed)) % 3;
    Texture2D texture = m_textures.at(direction)[frame];

    Rectangle sourceRec = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
    Rectangle destRec = { m_position.x, m_position.y, texture.width * m_SCALE_FACTOR, texture.height * m_SCALE_FACTOR };
    Vector2 origin = { (float)texture.width * m_SCALE_FACTOR / 2.0f, (float)texture.height * m_SCALE_FACTOR / 2.0f };

    DrawTexturePro(texture, sourceRec, destRec, origin, 0.0f, WHITE);
}

void Pacman::setVelocity() {
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
    if (m_map && m_map->isPath(nextPosition)) {
        m_velocity = nextVelocity;
        m_inputHandler->setQueuedDirection(direction);
    }
    else {
        direction = m_inputHandler->getQueuedDirection();
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

        nextPosition = { m_position.x + nextVelocity.x, m_position.y + nextVelocity.y };
        if (m_map && m_map->isPath(nextPosition)) {
            m_velocity = nextVelocity;
        }
        else {
            m_velocity = { 0, 0 };
        }
    }
}
