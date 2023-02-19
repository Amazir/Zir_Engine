#include "z_TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fName, SDL_Renderer* r) {
	SDL_Surface* tmpSurface = IMG_Load(fName);
	SDL_Texture* txt = SDL_CreateTextureFromSurface(r, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return txt;
}