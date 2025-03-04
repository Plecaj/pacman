#include "pacman.h"

Pacman::Pacman(Vector2 position, Vector2 velocity, float speed, InputHandler* inputHandler)
	: Entity(position, velocity, speed), m_lives(3), m_score(0), m_isInPowerMode(false), m_startPosition(position), m_inputHandler(inputHandler){
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
	Entity::update();
	//checkColision();
	//checkForDots();
	//checkForGhost();
}

void Pacman::draw() const{
	Direction direction = m_inputHandler->getDirection();
	int frame = ((int)GetTime()) % 3; 
	DrawTexture(m_textures.at(direction)[frame], static_cast<int>(m_position.x), static_cast<int>(m_position.y), WHITE);
}

void Pacman::move(){
	auto direction = m_inputHandler->getDirection();
	switch (direction) {
	case Direction::Left:
		m_velocity = { -m_speed, 0 };
		break;
	case Direction::Right:
		m_velocity = { m_speed, 0 };
		break;
	case Direction::Up:
		m_velocity = { 0, -m_speed };
		break;
	case Direction::Down:
		m_velocity = { 0, m_speed };
		break;
	}
}
