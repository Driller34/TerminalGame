#include "Game.hpp"

Game::Game(const size_t width,
    const size_t height)
    : mWindow(width, height),
    mResourceManager(std::filesystem::path(PROJECT_ROOT_DIR))
{
    mLayerManager.push(Factory::makeMenu(mLayerManager, mResourceManager));
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