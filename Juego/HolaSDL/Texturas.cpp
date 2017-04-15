#include "Texturas.h"
#include "Error.h"
#include "SDL.h"
#include <iostream>


Texturas::Texturas() //constructora
{
	ptext = nullptr;
	ancho = 0;
	alto = 0;
}



Texturas::~Texturas() // destructora
{
	//SDL_DestroyTexture(ptext);
	ptext = nullptr;
}



//load para cargar la imagen y asignar un valor a alto y ancho
bool Texturas::load(SDL_Renderer*prender, std::string const& nombArch) {

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
void Texturas::draw(SDL_Renderer*prender, SDL_Rect* const& rect2, SDL_Rect* const& rect) {
	SDL_RenderCopy(prender, ptext, rect2, rect);
}

//Metodos para la fuente
bool Texturas::loadFromText(SDL_Renderer* pRenderer, const std::string texture, SDL_Color color) {

	SDL_Surface *pSurface = myFont.textSolid(texture, color);
	//myFont.freeSurface(pSurface);
	SDL_DestroyTexture(ptext);
	ptext = SDL_CreateTextureFromSurface(pRenderer, pSurface);
	SDL_FreeSurface(pSurface);
	return true;
}

bool Texturas::loadFuente(std::string fuente, int tamano) {

	myFont.load(fuente, tamano);
	return true;
}

/*SDL_Rect Texturas::setRect(int h, int w, int x, int y) {
	//return rectFont = { h, w, x, y };
	rectFont.h = h;
	rectFont.w = w;
	rectFont.x = x;
	rectFont.y = y;
	std::cout << "Pues si salgo" << std::endl;
	return rectFont;
}*/