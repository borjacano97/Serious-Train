#pragma once

#include <iostream>
#include "SDL_ttf.h"
class Font
{
public:
	Font(/*int h, int w, int x, int y*/);
	virtual ~Font();
	TTF_Font * font;
	SDL_Rect rectFont;

	bool load(std::string text, int tamaño);
	SDL_Surface* textSolid(std::string texto, SDL_Color color);
	SDL_Rect setRect(int h, int w, int x, int y);
	//void freeSurface(SDL_Surface* surf);

};
