#include "SFML/Graphics.hpp"

using namespace sf;

class GameObject
{
protected:
	int x, y;
	int w, h;

public:
	GameObject(int x = 0, int y = 0, int w = 0, int h = 0);
	virtual ~GameObject();
	
	Vector2f GetPosition();
	Vector2f GetSize();
};