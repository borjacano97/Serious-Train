#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string>

class Texturas 
{
public:
	Texturas();
	~Texturas();
	//métodos públicos para cargar y pintar
	bool load(SDL_Renderer*prender, std::string const& nombArch);
	void draw(SDL_Renderer*prender, SDL_Rect* const &rect2, SDL_Rect* const& rect);

private:
	SDL_Texture* ptext;

	int alto; // en principio las texturas han de ser cuadradas
	int ancho;
};

