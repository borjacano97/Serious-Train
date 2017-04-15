#include "Font.h"
#include "SDL_ttf.h"

Font::Font(/*int h, int w, int x, int y*/)
{
	rectFont.h = 80;
	rectFont.w = 80;
	rectFont.x = 50;
	rectFont.y = 50;
}


Font::~Font()
{
}

SDL_Surface* Font::textSolid(std::string texto, SDL_Color color) {
	return TTF_RenderText_Solid(font, texto.c_str(), color);
}

/*void Font::freeSurface(SDL_Surface* surf) {
SDL_FreeSurface(surf);
}*/

bool Font::load(std::string nombre, int tamano) {
	font = TTF_OpenFont(nombre.c_str(), tamano);
	return true;
}