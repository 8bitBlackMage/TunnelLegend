#include "MapLoader.hpp"
#include "tmxlite/include/tmxlite/TileLayer.hpp"
#include "GraphicsCode/TextureLoading.h"
mapmanager::mapmanager(TextureManager& TextureLoader):textureLoader(TextureLoader)
{


}

mapmanager::~mapmanager()
{

}
void mapmanager::setMapPath(std::string mapPath)
{
    MapPath = mapPath;

}

bool mapmanager::loadNewMap(std::string mapname)
{

    std::string fullpath = MapPath + mapname + ".tmx";

    if(CurrentMap.load(fullpath))
    {
        return true;
    }
   
    
    return false;
    

}
void mapmanager::processTilesets()
{

    for(const auto & tileset : *Tilesets)
    {
        std::string Path = tileset.getImagePath();



    }


}


mapmanager & mapmanager::getManager(TextureManager& TextureLoader)
{
    static mapmanager instance(TextureLoader);

    return instance;
}

