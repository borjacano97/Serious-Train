#include "texturas.h"
#include "error.h"
#include "SDL.h"
#include <iostream>


texturas::texturas() //constructora
{
	ptext = nullptr;
	ancho = 0;
	alto = 0;
}


texturas::~texturas() // destructora
{
	SDL_DestroyTexture(ptext);
	ptext = nullptr;
}

//load para cargar la imagen y asignar un valor a alto y ancho
bool texturas::load(SDL_Renderer*prender, std::string const& nombArch) {

	SDL_Surface* pTempSurface = nullptr;
	bool cargar = true;

	pTempSurface = IMG_Load(nombArch.c_str());
	if (pTempSurface == nullptr) {
		throw error("Unable to load image");/////
		std::cout << "Unable to load image " << nombArch << "! \nSDL Error: " << SDL_GetError() << '\n';
		cargar = false;
	}
	else {
		ptext = SDL_CreateTextureFromSurface(prender, pTempSurface);
		alto = pTempSurface->clip_rect.h;
		ancho = pTempSurface->clip_rect.w;
		SDL_FreeSurface(pTempSurface);
		cargar = ptext != nullptr;
	}

	return cargar;
}

//metodo que llama al rendercopy con el render la textura y un rect
void texturas::draw(SDL_Renderer*prender, SDL_Rect* const& rect2, SDL_Rect* const& rect) {
	SDL_RenderCopy(prender, ptext, rect2, rect);
}
