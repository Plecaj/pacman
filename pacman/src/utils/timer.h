#pragma once
#include <chrono>

class Timer {
public:
	Timer();
	void reset();
	double getElapsedSeconds();
private:
	std::chrono::high_resolution_clock::time_point m_startTime;
};