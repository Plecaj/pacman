#include "game.h"

// Core
#include "inputHandler.h"
#include "entityMenager.h"

// Utils
#include "../utils/timer.h"

// Entities
#include "../entities/entity.h"
#include "../entities/pacman.h"
#include "../entities/specificGhosts/blinky.h"
#include "../entities/specificGhosts/pinky.h"
#include "../entities/specificGhosts/inky.h"
#include "../entities/specificGhosts/clyde.h"

#include "raylib.h"

#include <string>
#include <sstream>

void Game::run(){
	m_WINDOW_WIDTH = 630;
	m_WINDOW_HEIGHT = 750;
	InitWindow(m_WINDOW_WIDTH, m_WINDOW_HEIGHT, "Pacman");
	SetWindowIcon(LoadImage("assets/pacman-right/1.png"));

	SetTargetFPS(60);

	InputHandler inputHandler;
	EntityMenager entityMenager;

	Map map("assets/other/map.png");

	Vector2 startPosition = { 415.0f, 310.0f };
	Vector2 startDirection = { 1.0f, 0.0f };
	Pacman pacman(startPosition, startDirection, 2.5f, &inputHandler, &map);

	entityMenager.addEntity(&pacman);

	Blinky blinky({ 290.0f, 280.0f }, { 1.0f, 0.0f }, 2.0f, &map, &pacman);
	Pinky pinky({ 310.0f, 280.0f }, { 1.0f, 0.0f }, 2.0f, &map, &pacman);
	Inky inky({ 330.0f, 280.0f }, { 1.0f, 0.0f }, 2.0f, &map, &pacman, &blinky);
	Clyde clyde({ 350.0f, 280.0f }, { 1.0f, 0.0f }, 2.0f, &map, &pacman);

	entityMenager.addEntity(&blinky);
	entityMenager.addEntity(&pinky);
	entityMenager.addEntity(&inky);
	entityMenager.addEntity(&clyde);

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
