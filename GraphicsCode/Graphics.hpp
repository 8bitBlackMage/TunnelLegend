#include<raylib.h>
#include<string>
#include<vector>
#include "TextureLoading.h"
//drawable struct (sprites and such)
struct Drawable{
    Drawable();
    //standard non spritesheet constructor
    Drawable(TextureManager Cache, float x, float y, std::string textureName);
    //spritesheet constructor, 
    Drawable(TextureManager Cache, float x, float y, std::string TextureName,float SheetPosX, float SheetPosY,float SheetPosH, float SheetPosW);


    //variables 

    Texture2D* m_Texture;
    Vector2 M_position;
    int m_Height;
    int m_Width;
    bool m_fromSpriteSheet;
    Rectangle m_sourceRect;
    TextureManager * Cache;
};



//container class for graphics related options. 
class Graphics{
    public:
    //initialisation function, creates the graphics object, handles video callbacks.
    Graphics(TextureManager &Cache);

    //standard loop function, called once per frame, draws non ui Screen content. 
    void loop();

    //empties the video buffer of the graphics system, used to free memory and clear screen 
    void flushBuffer();

    private:
    Camera2D M_Camera;
    std::vector<Drawable>VideoBuffer;
    TextureManager&  TextureCache;
};



    //master object type for video Layers. only used for polymorphism reasons
class Layer{

    public:
    int layernum;
    int hRes;
    int wRes;
    std::vector<Drawable>renderBuffer;
    };


class TileLayer : public Layer
{
    //layer type for storing and managing a layer of tiled textures
    public:
    Vector2 TileSize;
    



};

//class type for background layer, usually a single image, with parallax effects
class BackGroundLayer: public Layer
{
     




};


    //class type for layer of movable animated sprites. 
class SpriteLayer: public Layer
{



};