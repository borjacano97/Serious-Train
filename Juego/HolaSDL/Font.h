#pragma once

#include <iostream>
#include "SDL_ttf.h"
class Font
{
public:
	Font();
	~Font();
	TTF_Font * font;
	SDL_Rect rectFont;

	bool load(std::string text, int tamaño);
	SDL_Surface* textSolid(std::string texto, SDL_Color color);
	//void freeSurface(SDL_Surface* surf);

};
