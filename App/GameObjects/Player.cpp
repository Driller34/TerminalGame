#include "Player.hpp"

Player::Player(const Image& image,
    const GameSettings& settings)
    : Mob(image),
    mGameSettings(settings)
{}

void Player::update()
{
    Vec2i newPosition = getPosition() + getMoveOffset();
    Vec2i size = getSize();

    if(newPosition.x >= 0 
        && newPosition.y >= 0)
    {
        setPosition(newPosition);
    }
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