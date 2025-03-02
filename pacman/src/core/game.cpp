#include "game.h"

#include <string>
#include <sstream>

#include "../utils/timer.h"
#include "inputHandler.h"

#include "raylib.h"

void Game::run()
{
	m_WINDOW_WIDTH = 960;
	m_WINDOW_HEIGHT = 720;
	InitWindow(m_WINDOW_WIDTH, m_WINDOW_HEIGHT, "Pacman");

	SetTargetFPS(60);

	InputHandler inputHandler;

	Vector2 playerPosition = { 400, 200 };
	float speed = 2.5f;

	Timer timer;
	while (!WindowShouldClose()) {
		auto timeElapsed = timer.getElapsedSeconds();
		std::stringstream ss;
		ss << timeElapsed;
		std::string timeElapsedString = ss.str();

		Direction dir = inputHandler.GetDirection();
		switch (dir) {
			case Direction::Up: playerPosition.y -= speed; break;
			case Direction::Down: playerPosition.y += speed; break;
			case Direction::Left: playerPosition.x -= speed; break;
			case Direction::Right: playerPosition.x += speed; break;
		}

		ClearBackground(WHITE);
		BeginDrawing();
			DrawText(timeElapsedString.c_str(), 400, 500, 12, BLACK);
			DrawCircle(playerPosition.x, playerPosition.y, 10, RED);
		EndDrawing();
	}
	CloseWindow();
}
