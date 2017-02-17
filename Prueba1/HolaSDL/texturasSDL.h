#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string>


class texturasSDL
{
public:
	texturasSDL();
	~texturasSDL();
	bool load(SDL_Renderer*prender, std::string const& nombArch);
	void draw(SDL_Renderer*prender, SDL_Rect* const &rect2,  SDL_Rect* const& rect);


private:

	SDL_Texture* ptext;

	int alto;
	int ancho;


};

