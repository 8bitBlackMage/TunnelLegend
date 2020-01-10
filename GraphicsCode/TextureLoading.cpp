#include "TextureLoading.h"
#include <dirent.h>

//texture management singleton implimentation! 
TextureManager::TextureManager(std::string path, bool autoload)
{
 /*   if(autoload){
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

    }*/
}



void TextureManager::loadFromFile(std::string Path)
{

    //format the string for key generation / texture loading
    std::string Fullpath = "./assets/Images/" + Path;
    size_t lastdot = Path.find_last_of(".");

    std::string ShortPath = Path.substr(0,lastdot);

    //generate integer key from the string
    uint Key = generateID(ShortPath);
    
    //check if the texture manager has already got that texture in memory
    if(m_Textures.count(Key) == 0){
    
        //if it is not present load it into VRAM 
        Texture2D Vram = LoadTexture(Fullpath.c_str());
        // add it to texture lookup to be used later
        m_Textures.emplace(Key,Vram);
        m_lookup.emplace(Path,Key);

        printf("%lu", m_Textures.size() );
    }


}

uint TextureManager::generateID(std::string Path)
{
unsigned int output;
for(int i = 0; i < Path.size(); i++)
{
char value = Path.at(i);

output += (int)value<<output;


}

return output;
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