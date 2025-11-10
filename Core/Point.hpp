#pragma once

struct Point
{
    size_t x;
    size_t y;

    Point operator*(const size_t n)
    {
        return {x * n, y * n};
    }

    Point operator+(const Point& other)
    {
        return {x + other.x, y + other.y};
    }

    Point operator-(const Point& other)
    {
        return {x - other.x, y - other.y};
    }

    Point operator-(const size_t n)
    {
        return {x - n, y - n};
    }

    Point& operator-=(const Point& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Point& operator-=(const size_t n)
    {
        x -= n;
        y -= n;
        return *this;
    }

    Point& operator+=(const size_t n)
    {
        x += n;
        y += n;
        return *this;
    }
};