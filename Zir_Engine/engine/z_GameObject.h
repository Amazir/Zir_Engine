#pragma once
#include "z_TextureManager.h"
#include "structs/z_Vector2.h"

class GameObject {
public:
	// Constructor takes argument with path to texture and SDL_Renderer object
	GameObject(const char* txtPath, SDL_Renderer * r); 
	~GameObject() {} // Destructor
	
	void update(); // Function for updating game objects
	void render(); // Function for rendering game objects

	int id; // Unique ID number

private:
	vector2 pos; // Current position of object (x, y)

	SDL_Texture* texture; // Texture of object
	SDL_Rect srcRect, dstRect; // Source position and destination position of our object
	SDL_Renderer* renderer; // SDL_Renderer passed through constructor
};