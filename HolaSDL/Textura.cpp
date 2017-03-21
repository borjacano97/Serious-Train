#include "Textura.h"
#include "Error.h"
#include "SDL.h"
#include <iostream>


Textura::Textura() //constructora
{
	ptext = nullptr;
	ancho = 0;
	alto = 0;
}


Textura::~Textura() // destructora
{
	SDL_DestroyTexture(ptext);
	ptext = nullptr;
}

//load para cargar la imagen y asignar un valor a alto y ancho
bool Textura::load(SDL_Renderer*prender, std::string const& nombArch) {

	SDL_Surface* pTempSurface = nullptr;
	bool cargar = true;

	pTempSurface = IMG_Load(nombArch.c_str());
	if (pTempSurface == nullptr) {
		throw Error("Unable to load image");/////
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
void Textura::draw(SDL_Renderer*prender, SDL_Rect* const& rect2, SDL_Rect* const& rect) {
	SDL_RenderCopy(prender, ptext, rect2, rect);
}
