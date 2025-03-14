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
	m_WINDOW_WIDTH = 630;
	m_WINDOW_HEIGHT = 750;
	InitWindow(m_WINDOW_WIDTH, m_WINDOW_HEIGHT, "Pacman");

	SetTargetFPS(60);

	InputHandler inputHandler;
	EntityMenager entityMenager;

	Map map("assets/other/map.png");

	Vector2 startPosition = { 415.0f, 310.0f };
	Vector2 startDirection = { 1.0f, 0.0f };
	Pacman pacman(startPosition, startDirection, 2.0f, &inputHandler, &map);

	entityMenager.addEntity(&pacman);

	while (!WindowShouldClose()) {
		entityMenager.update();
		ClearBackground(BLACK);
		BeginDrawing();
		map.draw();
		entityMenager.draw();
		EndDrawing();
	}
	CloseWindow();
}
