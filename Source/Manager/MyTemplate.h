#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;



//! Delete pointer variable in Destructor
template<class T> void Delete(T* ptr) {
	if (ptr != nullptr) {
		delete ptr;
		ptr = nullptr;
	}
}



//! Singleton pattern use for inheritance
template<class T> class Singleton
{
private:
	static T* mInstance;

protected:
	Singleton() {}

	virtual ~Singleton() {
		if (mInstance != nullptr) {
			delete mInstance;
			mInstance = nullptr;
		}
		Delete<T>(mInstance);
	}

public:
	static T* GetInstance() {
		if (mInstance == nullptr) {
			mInstance = new T();
		}
		return mInstance;
	}

	static bool HasInstance() {
		return mInstance != nullptr;
	}

	static void FreeInstance() {
		if (mInstance != nullptr) {
			delete mInstance;
			mInstance = nullptr;
		}
	}
};

template<class T> T* Singleton<T>::mInstance = nullptr;