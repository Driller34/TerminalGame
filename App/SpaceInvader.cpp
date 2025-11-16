#include "SpaceInvader.hpp"

SpaceInvader::SpaceInvader(ResourceManager& resourceManager,
    const GameSettings& settings)
    : mResourceManager(resourceManager),
    mGameSettings(settings),
    mIsGameOver(false),
    mPlayer(mResourceManager.getImage("Images/spaceship.bmp"), mGameSettings),
    mAsteroids(mGameSettings.numAsteroids, 
        mResourceManager.getImage("Images/asteroid.bmp")),
    mAsteroidsClock()
{
    srand(time(NULL));

    mPlayer.setPosition(mGameSettings.playerStartPosition);
    mPlayer.setHp(mGameSettings.fullPlayerHp);
    mIsGameOver = false;
    initAsteroids();
}

void SpaceInvader::update()
{
    if(mIsGameOver){ return; }

    mPlayer.update();

    playerColision();
    bulletColision();

    updateAsteroids();
    updateBullets();

    if(mPlayer.getHp() <= 0)
    {
        gameOver();
    }
}

void SpaceInvader::draw(Window& renderTarger, 
        const Vec2i& position)
{
    if(mIsGameOver)
    {
        renderTarger.draw(mResourceManager.getImage("Images/gameover.bmp"));
    }

    renderTarger.draw(mPlayer);

    for(Mob& asteroid : mAsteroids)
    {
        renderTarger.draw(asteroid);
    }

    for(Mob& bullet : mBullets)
    {
        renderTarger.draw(bullet);
    }
}

bool SpaceInvader::isGameOver() const
{
    return mIsGameOver;
}

void SpaceInvader::fire()
{
    makeBullet();
}

void SpaceInvader::moveUp()
{
    mPlayer.moveUp();
}

void SpaceInvader::moveDown()
{
    mPlayer.moveDown();
}

void SpaceInvader::moveLeft()
{
    mPlayer.moveLeft();
}

void SpaceInvader::moveRight()
{
    mPlayer.moveRigth();
}

void SpaceInvader::updateAsteroids()
{
    if(mAsteroidsClock.elapsedTime() >= std::chrono::milliseconds(500))
    {
        for(Mob& asteroid : mAsteroids)
        {
            asteroid.update();
            if(checkAsteroidFinish(asteroid))
            {
                startAsteroid(asteroid);
                mPlayer.setHp(mPlayer.getHp() - mGameSettings.hpWhenAsteridFinish);
            }
        }

        mAsteroidsClock.restart();
    }
}

void SpaceInvader::updateBullets()
{
    for(Mob& bullet : mBullets)
    {
        bullet.update();
    }
}

void SpaceInvader::playerColision()
{
    for(Mob& asteroid : mAsteroids)
    {
        if(checkColision(asteroid))
        {
            mPlayer.setHp(mPlayer.getHp() - mGameSettings.hpWhenCollision);
            startAsteroid(asteroid);
        }
    }
}

void SpaceInvader::bulletColision()
{
    for(Mob& bullet : mBullets)
    {
        for(Mob& asteroid : mAsteroids)
        {
            if(checkColision(asteroid, bullet))
            {
                startAsteroid(asteroid);
            }
        }   
    }
}

void SpaceInvader::makeBullet()
{
    mBullets.emplace_back(Image(1, 1, {255, 0, 0, 255}));
    mBullets.back().setMoveOffset({0, -1});
    mBullets.back().setPosition(mPlayer.getPosition());
}

int SpaceInvader::randomInt(const Vec2i& range)
{
    return range.x + rand() % (range.y + 1 - range.x);
}

Vec2i SpaceInvader::randAsteroidPosition()
{
    return {
        randomInt(mGameSettings.spawnXRange),
        -randomInt(mGameSettings.spawnYRange)
    };
}

void SpaceInvader::initAsteroids()
{
    for(Mob& asteroid : mAsteroids)
    {
        startAsteroid(asteroid);
        asteroid.setMoveOffset({0, 1});
    }
}

void SpaceInvader::startAsteroid(Mob& asteroid)
{
    asteroid.setPosition(randAsteroidPosition());
}

bool SpaceInvader::checkColision(const Mob& asteroid)
{
    const Vec2i posA = mPlayer.getPosition();
    const Vec2i sizeA = mPlayer.getSize();
    const Vec2i posB = asteroid.getPosition();
    const Vec2i sizeB = asteroid.getSize();

    return (posA.x < posB.x + sizeB.x &&
            posA.x + sizeA.x > posB.x &&
            posA.y < posB.y + sizeB.y &&
            posA.y + sizeA.y > posB.y);
}

bool SpaceInvader::checkColision(const Mob& a, 
    const Mob& b) const
{
    const Vec2i posA = a.getPosition();
    const Vec2i sizeA = a.getSize();
    const Vec2i posB = b.getPosition();
    const Vec2i sizeB = b.getSize();

    return (posA.x < posB.x + sizeB.x &&
            posA.x + sizeA.x > posB.x &&
            posA.y < posB.y + sizeB.y &&
            posA.y + sizeA.y > posB.y);
}

bool SpaceInvader::checkAsteroidFinish(const Mob& asteroid)
{
    return asteroid.getPosition().y == mGameSettings.asteroidFinishPoint;
}

void SpaceInvader::gameOver()
{
    mIsGameOver = true;
}