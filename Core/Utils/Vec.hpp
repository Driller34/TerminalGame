#pragma once
#include <cstddef>

template<typename T>
struct Vec2
{
    T x;
    T y;

    Vec2 operator*(const T n)
    {
        return {x * n, y * n};
    }

    Vec2 operator+(const Vec2& other)
    {
        return {x + other.x, y + other.y};
    }

    Vec2 operator-(const Vec2& other)
    {
        return {x - other.x, y - other.y};
    }

    Vec2 operator-(const T n)
    {
        return {x - n, y - n};
    }

    Vec2& operator-=(const Vec2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2& operator-=(const T n)
    {
        x -= n;
        y -= n;
        return *this;
    }

    Vec2& operator+=(const T n)
    {
        x += n;
        y += n;
        return *this;
    }
};

using Vec2i = Vec2<int>;
using Vec2ull = Vec2<size_t>;