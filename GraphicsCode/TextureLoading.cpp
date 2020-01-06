#include "TextureLoading.h"
#include <dirent.h>

//texture management singleton implimentation! 
TextureManager::TextureManager(std::string path, bool autoload)
{
    if(autoload){
        //standard constructor 
        DIR * pdir;

        struct dirent *entry;
        if(pdir==opendir(path.c_str()))
        {   
            while(entry == readdir(pdir))
            {
        
        
                std::string rawname = entry->d_name;
                if(rawname.find("png") != std::string::npos){


                    std::string Fullpath = "./../assets/" + rawname;
                    Texture2D Texture = LoadTexture(Fullpath.c_str());
                    size_t lastdot = rawname.find_last_of(".");
                    rawname = rawname.substr(0,lastdot);
         
                    m_Textures.emplace(rawname,Texture);
         
                }
            }
        }

    }
}



Texture2D& TextureManager::loadFromFile(std::string Path)
{
    std::string Fullpath = "./../assets/" + Path;
    Texture2D Texture = LoadTexture(Fullpath.c_str());
    size_t lastdot = Path.find_last_of(".");
    Path = Path.substr(0,lastdot);
    m_Textures.emplace(Path,Texture);
    return &Texture;
}
//remove all textures from Vram and clear out the arrays
TextureManager::~TextureManager()
{

    m_Textures.empty();

}


//static instance producer 
TextureManager & TextureManager::getManager(std::string path, bool autoload)
{
    static TextureManager instance(path, autoload);

    return instance;

}