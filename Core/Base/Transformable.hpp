#pragma once
#include <concepts>
#include "../Utils/Vec.hpp"

class Transformable
{
public:
    Transformable()
        : mPosition({0, 0})
    {}

    virtual ~Transformable() = default;

    void setPosition(const Vec2i& position)
    {
        mPosition = position;
    }

    Vec2i getPosition() const
    {
        return mPosition;
    }

    void move(const Vec2i& offset)
    {
        setPosition(mPosition + offset);
    }

private:
    Vec2i mPosition;
};

template<typename T>
concept IsTransformable = std::derived_from<T, Transformable>;