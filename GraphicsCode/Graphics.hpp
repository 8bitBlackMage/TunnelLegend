#include<raylib.h>
#include<string>
#include<vector>
#include "TextureLoading.h"
#include "Drawable.h"


enum VideoMode{
layerless, multilayer
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


    void addToBuffer(Drawable texture);
    private:
    VideoMode Rendertype;
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

//layer type for storing and managing a layer of tiled textures
class TileLayer : public Layer
{
    
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