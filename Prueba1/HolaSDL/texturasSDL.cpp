#include "texturasSDL.h"
#include "SDL.h"
#include <iostream>
#include "texturasError.h"


texturasSDL::texturasSDL()
{//inicializo el puntero a nulo y las variables alto y ancho
	ptext = nullptr;
	ancho = 0;
	alto = 0;
}


texturasSDL::~texturasSDL()
{
	SDL_DestroyTexture(ptext);
	ptext = nullptr;
	//destruir textura
}
//load para cargar la imagen y asignar un valor a alto y ancho
bool texturasSDL::load(SDL_Renderer*prender, std::string const& nombArch){

	SDL_Surface* pTempSurface = nullptr;
	bool cargar = true;

	pTempSurface = IMG_Load(nombArch.c_str());
	if (pTempSurface == nullptr) {
		throw texturasError("Unable to load image");/////
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
void texturasSDL::draw(SDL_Renderer*prender, SDL_Rect* const& rect2, SDL_Rect* const& rect){
	SDL_RenderCopy(prender, ptext, rect2, rect);
}

