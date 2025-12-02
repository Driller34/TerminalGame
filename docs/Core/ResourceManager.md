# ResourceManager

## Header
```
#include "Core/ResourceManager.hpp"
```

## Declaration
```
class ResourceManager
```

## Description
ResourceManager is responsible for loading, storing, and providing access to game assets such as images.  
It maintains a map of file paths to loaded `Image` objects to avoid reloading the same resource multiple times.

## Private attributes
- `std::filesystem::path mMainPath` – base directory path for resources  
- `std::unordered_map<std::filesystem::path, Image> mImages` – map storing loaded images keyed by their file paths

## Member functions
- [constructor](#constructor)  
- [addImage](#addimage)  
- [getImage](#getimage)

## constructor

### Description
Initializes the resource manager with a main resource path.  
This path is used as the base for all resource loading operations.

### Declaration
```
ResourceManager(const std::filesystem::path& path);
```

### Parameters
- `const std::filesystem::path& path` – base path for resource files  

## addImage

### Description
Loads an image from the given path and stores it in the resource manager.  
If the image was previously loaded, it may overwrite the existing entry.

### Declaration
```
void addImage(const std::filesystem::path& path);
```

### Parameters
- `const std::filesystem::path& path` – path to the image file relative to the main path  

## getImage

### Description
Retrieves a previously loaded image from the resource manager.
If the image does not exist, it automatically loads it using addImage before returning.

### Declaration
```
Image getImage(const std::filesystem::path& path);
```

### Parameters
- `const std::filesystem::path& path` – path to the requested image  

### Return type
```
Image
```