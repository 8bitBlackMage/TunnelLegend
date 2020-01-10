#include "Graphics.hpp"














Graphics::Graphics(TextureManager &Cache):TextureCache(Cache)
{
Rendertype = layerless;
}

void Graphics::loop()
{
    ClearBackground(BLUE);
    BeginDrawing();
  //  BeginMode2D(M_Camera);
    switch(Rendertype)
    {
        case(layerless):
        {
            for(Drawable TextureObject: VideoBuffer)
            {
                if(TextureObject.m_fromSpriteSheet == true){
                    DrawTextureRec(*TextureObject.m_Texture,TextureObject.m_sourceRect,TextureObject.m_position, WHITE );
                }
                else
                {
                    DrawTextureV(*TextureObject.m_Texture,TextureObject.m_position,WHITE);

                }

            }
        }

        case(multilayer):
        {

        }

    }
  //  EndMode2D();
    EndDrawing();
}

void Graphics::addToBuffer(Drawable Texture){
    VideoBuffer.push_back(Texture);
}


void Graphics::flushBuffer()
{
VideoBuffer.clear();

}