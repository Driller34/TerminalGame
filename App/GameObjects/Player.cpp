#include "Player.hpp"

Player::Player(const Image& image)
    : Mob(image)
{}

void Player::update()
{
    move(getMoveOffset());
    setMoveOffset({0, 0});
}

void Player::moveUp()
{
    setMoveOffset(getMoveOffset() + Vec2i{0, -1});
}

void Player::moveDown()
{
    setMoveOffset(getMoveOffset() + Vec2i{0, 1});
}

void Player::moveLeft()
{
    setMoveOffset(getMoveOffset() + Vec2i{-1, 0});
}

void Player::moveRigth()
{
    setMoveOffset(getMoveOffset() + Vec2i{1, 0});
}