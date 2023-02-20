#include "z_GameObjectManager.h"

GameObject::GameObject(const char* txtPath, SDL_Renderer* r) {
	renderer = r; // Save renderer
	texture = TextureManager::LoadTexture(txtPath, r); // Load texture from file
}

void GameObject::update() {
	// Some basic data of our rectangle
	srcRect.h = 50;
	srcRect.w = 50;
	srcRect.x = 0;
	srcRect.y = 0;

	// Setting position to our private vector
	dstRect.x = pos.x; // vector(x)
	dstRect.y = pos.y; // vector(y)
	dstRect.w = srcRect.w * 2; // Calculating and setting width
	dstRect.h = srcRect.h * 2; // Calculating and setting height
}

void GameObject::render() {
	// Rendering object through passed in constructor SDL_Renderer
	SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
}