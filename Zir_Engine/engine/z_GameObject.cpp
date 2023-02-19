#include "z_GameObjectManager.h"

GameObject::GameObject(const char* txtPath, SDL_Renderer* r) {
	renderer = r;
	texture = TextureManager::LoadTexture(txtPath, r);
}

void GameObject::update() {
	srcRect.h = 50;
	srcRect.w = 50;
	srcRect.x = 0;
	srcRect.y = 0;

	dstRect.x = pos.x;
	dstRect.y = pos.y;
	dstRect.w = srcRect.w * 2;
	dstRect.h = srcRect.h * 2;
}

void GameObject::render() {
	SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
}