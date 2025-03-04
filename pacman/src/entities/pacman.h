#pragma once

#include "entity.h"
#include "../core/inputHandler.h"
#include "../utils/direction.h"

#include <vector>
#include <unordered_map>
#include <string>

class Pacman : public Entity {
public:
	Pacman(Vector2 position, Vector2 velocity, float speed, InputHandler* inputHandler);
	~Pacman();
	void update() override;
	void draw() const override;
	void move();
private:
	int m_lives;
	int m_score;
	bool m_isInPowerMode;
	Vector2 m_startPosition;
	std::unordered_map<Direction, std::vector<Texture2D>> m_textures;
	InputHandler* m_inputHandler;
};