//entry point for program, holds main loop and other core functions 
#include <raylib.h>
#include <iostream>
#include "Settings.hpp"
#include "MapLoader.hpp"
#include "GraphicsCode/Graphics.hpp"
settings GameSettings;
TextureManager & TextureLoader = TextureManager::getManager(GameSettings.ImgPath, false);
mapmanager & mapManager = mapmanager::getManager(TextureLoader);
Graphics VideoDevice(TextureLoader);


bool init()
{

    
    if(GameSettings.G_FullScreen == true)
    {
    InitWindow(GetScreenWidth(),GetScreenHeight(), "testing");
    
    ToggleFullscreen();
    }
    else{
    InitWindow(GameSettings.G_WinWidth,GameSettings.G_WinHeight, "testing"); 
    }

    if(IsWindowReady() == false)
    {
    std::cerr << "window init failed" << std::endl;
    return false;
    }
    SetTargetFPS(GameSettings.G_FPS);
    return true;
}



int main()
{
if(init() == true){
    while(WindowShouldClose() == false)
    {
    
    VideoDevice.loop();
    }
  
}


}