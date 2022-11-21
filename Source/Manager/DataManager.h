#pragma once
#include "SFML/Graphics.hpp";
#include "MyTemplate.h"
#include <iostream>
#include <map>

using namespace std;
using namespace sf;

class DataManager : public Singleton<DataManager>
{
private:
	map<string, Texture*> mTextureMap;
	map<string, Font*> mFontMap;
	map<string, Sound*> mSoundMap;
	map<string, Music*> mMusicMap;

	string mTexturePath;
	string mFontPath;
	string mSoundPath;
	string mMusicPath;

public:
	DataManager();
	~DataManager();

	Texture* getTexture(string name);
	Font* getFont(string name);
	Sound* getSound(string name);
	Music* getMusic(string name);
};