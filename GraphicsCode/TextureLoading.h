#pragma once
#include <raylib.h>
#include <map>
#include <vector>
#include <string.h>





class TextureManager
{
public:


//instance creation
static TextureManager& getManager(std::string path, bool autoload);

//removal of copy constructor
TextureManager(TextureManager const&) = delete;
void operator = (TextureManager const&) = delete;
 
bool loadFromFile(); 
void setAutoLoad(bool flag);

//access to texture memory via a map, but also with vector based indexing
std::map<std::string,Texture2D>m_Textures;
std::vector<std::string>m_lookup;

private:
//init
TextureManager(std::string path, bool autoload);
//standard Desconstructor 
~TextureManager();

};



