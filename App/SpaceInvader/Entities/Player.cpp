#include "Player.hpp"

Player::Player(const Image& spriteImage,
    const Vec2i& position,
    const Vec2i& moveOffset,
    const size_t hp,
    const bool isActive)
    : Entity(spriteImage)
{
    this->position = position;
    this->moveOffset = moveOffset;
    this->hp = hp;
    this->isActive = isActive;
}

void Player::moveUp()
{

}

void Player::moveDown()
{

}

void Player::moveLeft()
{

}

void Player::moveRight()
{
    
}