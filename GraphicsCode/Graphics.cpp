#include "Graphics.hpp"


Drawable::Drawable(){

}

Drawable::Drawable(TextureManager Cache ,float x, float y, std::string textureName){
    M_position = {x, y};
    m_fromSpriteSheet= false;
    m_Texture = &Cache.m_Textures.at(textureName);
}



Drawable::Drawable(TextureManager Cache, float x, float y, std::string TextureName,float SheetPosX, float SheetPosY,float SheetPosH, float SheetPosW)
    {
    M_position = {x, y};
    m_fromSpriteSheet = true;
    m_Texture = &Cache.m_Textures.at(TextureName);
    m_sourceRect = {SheetPosX,SheetPosY,SheetPosH,SheetPosW};

    }











Graphics::Graphics(TextureManager &Cache):TextureCache(Cache)
{

}

void Graphics::loop()
{
ClearBackground(BLUE);
BeginDrawing();


EndDrawing();
}


void Graphics::flushBuffer()
{
VideoBuffer.clear();

}