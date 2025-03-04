#include "game.h"

// Core
#include "inputHandler.h"
#include "entityMenager.h"

// Utils
#include "../utils/timer.h"

// Entities
#include "../entities/entity.h"
#include "../entities/pacman.h"
#include "../entities/ghosts.h"

#include "raylib.h"

#include <string>
#include <sstream>

void Game::run()
{
	m_WINDOW_WIDTH = 960;
	m_WINDOW_HEIGHT = 720;
	InitWindow(m_WINDOW_WIDTH, m_WINDOW_HEIGHT, "Pacman");

	SetTargetFPS(60);

	InputHandler inputHandler;
	EntityMenager entityMenager;

	Vector2 startPosition = { 400.0f, 300.0f };
	Vector2 startDirection = { 1.0f, 0.0f };
	Pacman pacman(startPosition, startDirection, 2.0f, &inputHandler);

	entityMenager.addEntity(&pacman);

	while (!WindowShouldClose()) {
		entityMenager.update();
		ClearBackground(WHITE);
		BeginDrawing();
		entityMenager.draw();
		EndDrawing();
	}
	CloseWindow();
}
