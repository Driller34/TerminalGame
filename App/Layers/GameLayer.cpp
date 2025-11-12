#include "GameLayer.hpp"


GameLayer::GameLayer(LayerManager& layerManager,
    ResourceManager& resourceManager,
    const GameSettings& settings)
    : mLayerManager(layerManager),
    mResourceManager(resourceManager),
    mGameSettings(settings),
    mPlayer(mResourceManager.getImage("Images/spaceship.bmp")),
    mAsteroids(mGameSettings.numAsteroids, 
        mResourceManager.getImage("Images/asteroid.bmp")),
    mAsteroidsClock()
{
    srand(time(NULL));
    init();
}

void GameLayer::init()
{
    mPlayer.setHp(mGameSettings.fullPlayerHp);
    initAsteroids();
}

void GameLayer::update()
{
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

void GameLayer::draw(Window& window)
{
    window.draw(mPlayer);

    for(Mob& asteroid : mAsteroids)
    {
        window.draw(asteroid);
    }

    for(Mob& bullet : mBullets)
    {
        window.draw(bullet);
    }
}

void GameLayer::activateState() 
{
    mPlayer.setPosition(mGameSettings.playerStartPosition);
}

void GameLayer::inputHandler(const char pressedKey)
{
    switch(pressedKey)
    {
        case 'w': mPlayer.moveUp(); break;
        case 's': mPlayer.moveDown(); break;
        case 'a': mPlayer.moveLeft(); break;
        case 'd': mPlayer.moveRigth(); break;
        case ' ': makeBullet(); break;
    }
}

void GameLayer::updateAsteroids()
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

void GameLayer::updateBullets()
{
    for(Mob& bullet : mBullets)
    {
        bullet.update();
    }
}

void GameLayer::playerColision()
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

void GameLayer::bulletColision()
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

void GameLayer::makeBullet()
{
    mBullets.emplace_back(Image(1, 1, {255, 0, 0, 255}));
    mBullets.back().setMoveOffset({0, -1});
    mBullets.back().setPosition(mPlayer.getPosition());
}

int GameLayer::randomInt(const Vec2i& range)
{
    return range.x + rand() % (range.y + 1 - range.x);
}

Vec2i GameLayer::randAsteroidPosition()
{
    return {
        randomInt(mGameSettings.spawnXRange),
        -randomInt(mGameSettings.spawnYRange)
    };
}

void GameLayer::initAsteroids()
{
    for(Mob& asteroid : mAsteroids)
    {
        startAsteroid(asteroid);
        asteroid.setMoveOffset({0, 1});
    }
}

void GameLayer::startAsteroid(Mob& asteroid)
{
    asteroid.setPosition(randAsteroidPosition());
}

bool GameLayer::checkColision(const Mob& asteroid)
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

bool GameLayer::checkColision(const Mob& a, 
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

bool GameLayer::checkAsteroidFinish(const Mob& asteroid)
{
    return asteroid.getPosition().y == mGameSettings.asteroidFinishPoint;
}

void GameLayer::gameOver()
{
    mLayerManager.pop();
}