#include "timer.h"

Timer::Timer()
{
	m_startTime = std::chrono::high_resolution_clock::now();
}

void Timer::reset()
{
	m_startTime = std::chrono::high_resolution_clock::now();
}

double Timer::getElapsedSeconds()
{
	auto now = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = now - m_startTime;
	return duration.count();
}
