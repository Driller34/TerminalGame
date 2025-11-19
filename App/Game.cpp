#include "Game.hpp"

Game::Game(const size_t width,
        const size_t height)
    : mWindow(width, height),
    mResourceManager(std::filesystem::path(PROJECT_ROOT_DIR ) / "Resources"),
    mInputHandler()
{
    mLayerManager.push(factory::createMenu(mLayerManager, mResourceManager));
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
    const std::optional<char> input = mInputHandler.getKey();

    if(input)
    {
        mLayerManager.inputHandler(input.value());
    }
}