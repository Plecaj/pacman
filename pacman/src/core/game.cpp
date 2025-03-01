#include "game.h"

#include <string>
#include <sstream>
#include "../utils/timer.h"

#include "raylib.h"

void Game::run()
{
	m_WINDOW_WIDTH = 960;
	m_WINDOW_HEIGHT = 720;
	InitWindow(m_WINDOW_WIDTH, m_WINDOW_HEIGHT, "Pacman");

	SetTargetFPS(60);
	Timer timer;
	while (!WindowShouldClose()) {
		auto timeElapsed = timer.getElapsedSeconds();
		std::stringstream ss;
		ss << timeElapsed;
		std::string timeElapsedString = ss.str();
		ClearBackground(WHITE);
		BeginDrawing();
			DrawText(timeElapsedString.c_str(), 400, 500, 12, BLACK);
		EndDrawing();
	}
	CloseWindow();
}
