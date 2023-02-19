#pragma once
#include "z_TextureManager.h"
#include "structs/z_Vector2.h"

class GameObject {
public:
	GameObject(const char* txtPath, SDL_Renderer * r);
	~GameObject() {}
	
	void update();
	void render();

	int id;

private:
	vector2 pos;

	SDL_Texture* texture;
	SDL_Rect srcRect, dstRect;
	SDL_Renderer* renderer;
};