#pragma once
#include "tmxlite/include/tmxlite/Map.hpp"
#include "GraphicsCode/TextureLoading.h"
#include <string>


class mapmanager
{
public:
static mapmanager& getManager(TextureManager& TextureLoader);

mapmanager(mapmanager const&) = delete;
void operator = (mapmanager const&) = delete;

bool loadNewMap(std::string mapName);
void setMapPath(std::string mapPath);
void processTilesets();


void ClearMap();
 std::vector<tmx::Tileset> *Tilesets;

private:
tmx::Map CurrentMap;
std::string MapPath;
mapmanager(TextureManager& TextureLoader);
~mapmanager();
TextureManager& textureLoader;
};