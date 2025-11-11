#include "ResourceManager.hpp"

ResourceManager::ResourceManager(const std::filesystem::path& path)
    : mMainPath(path)
{

}

void ResourceManager::addResource(const std::filesystem::path& path)
{
    if(path.extension() == ".bmp")
    {
        addImage(path);
    }
}

void ResourceManager::addImage(const std::filesystem::path& path)
{
    mImages.emplace(path, BMPLoader::loadBMP(mMainPath / path));
}

Image ResourceManager::getImage(const std::filesystem::path& path) const
{
    return mImages.at(path);
}