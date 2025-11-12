#include "Game.hpp"

Game::Game(const GameSettings& settings)
    : mGameSettings(settings),
    mWindow(mGameSettings.width, mGameSettings.height),
    mResourceManager(std::filesystem::path(PROJECT_ROOT_DIR ) / "Resources")
{
    mLayerManager.push(Factory::makeMenu(mLayerManager, mResourceManager, mGameSettings));
}

void Game::run()
{
    while(!mLayerManager.empty())
    {
        inputHandler();
        update();
        render();
    }
}

void Game::update()
{
    mLayerManager.update();
}

void Game::render()
{
    mWindow.clear();
    mLayerManager.render(mWindow);
    mWindow.display();
}

void Game::inputHandler()
{
    auto input = Input::getKey();
    if(input)
    {
        mLayerManager.inputHandler(input.value());
    }
}