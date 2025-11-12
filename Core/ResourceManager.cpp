#include "ResourceManager.hpp"

ResourceManager::ResourceManager(const std::filesystem::path& path)
    : mMainPath(path)
{

}

void ResourceManager::addImage(const std::filesystem::path& path)
{
    mImages.emplace(path, BMPLoader::loadBMP(mMainPath / path));
}

Image ResourceManager::getImage(const std::filesystem::path& path)
{
    if(!mImages.contains(path)){ addImage(path); }
    return mImages.at(path);
}