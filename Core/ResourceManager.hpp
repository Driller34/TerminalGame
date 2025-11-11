#pragma once
#include <filesystem>
#include <unordered_map>
#include "Graphic/Image.hpp"
#include "Loader/BMPLoader.hpp"

class ResourceManager
{
public:
    ResourceManager(const std::filesystem::path& path);

    void addResource(const std::filesystem::path& path);

    void addImage(const std::filesystem::path& path);

    Image getImage(const std::filesystem::path& path) const;

private:
    std::filesystem::path mMainPath;
    std::unordered_map<std::filesystem::path, Image> mImages;
};