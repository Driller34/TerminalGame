#include "Clock.hpp"

Clock::Clock()
{
    restart();
}

std::chrono::milliseconds Clock::restart()
{
    auto now = clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - mStart);
    mStart = now;
    return elapsed;
}

std::chrono::milliseconds Clock::elapsedTime() const
{
    auto now = clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now - mStart);
}