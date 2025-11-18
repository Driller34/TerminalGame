#include "Player.hpp"

Player::Player(const Image& spriteImage,
    const Vec2i& position,
    const Vec2i& moveOffset,
    const size_t hp,
    const bool isActive)
    : Entity(EntityType::PLAYER, spriteImage)
{
    this->position = position;
    this->moveOffset = moveOffset;
    this->hp = hp;
    this->isActive = isActive;
}

void Player::moveUp()
{
    moveOffset += {0, -1};
}

void Player::moveDown()
{
    moveOffset += {0, 1};
}

void Player::moveLeft()
{
    moveOffset += {-1, 0};
}

void Player::moveRight()
{
    moveOffset += {1, 0};
}