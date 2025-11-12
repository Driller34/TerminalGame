#pragma once
#include <chrono>

class Clock
{
public:
    Clock();

    std::chrono::milliseconds restart();

    std::chrono::milliseconds elapsedTime() const;

private:
    using clock = std::chrono::high_resolution_clock;
    std::chrono::time_point<clock> mStart;
};