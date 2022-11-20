#include "DataManager.h"
#include <iostream>

DataManager::DataManager()
{
	mTexturePath = "Data/Textures/";
	mFontPath = "Data/Fonts/";
	mSoundPath = "Data/Sounds/";
	mMusicPath = "Data/Musics/";
}

DataManager::~DataManager()
{
	for (auto it : mTextureMap) {
		Delete<Texture>(it.second);
	}
	for (auto it : mFontMap) {
		Delete<Font>(it.second);
	}
	for (auto it : mSoundMap) {
		Delete<Sound>(it.second);
	}
	for (auto it : mMusicMap) {
		Delete<Music>(it.second);
	}
}

Texture* DataManager::getTexture(string name)
{
	auto it = mTextureMap.find(name);
	if (it == mTextureMap.end()) {
		Texture* texture = new Texture();
		texture->loadFromFile(mTexturePath + name + ".png");
		mTextureMap[name] = texture;
	}
	return mTextureMap[name];
}

Font* DataManager::getFont(string name)
{
	auto it = mFontMap.find(name);
	if (it == mFontMap.end()) {
		Font* font = new Font();
		font->loadFromFile(mFontPath + name + ".TTF");
		mFontMap[name] = font;
	}
	return mFontMap[name];
}

Sound* DataManager::getSound(string name)
{
	return nullptr;
}

Music* DataManager::getMusic(string name)
{
	return nullptr;
}