#ifndef H_TEXTURAS_H
#define H_TEXTURAS_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string>
#include "Font.h"

class Texturas
{
public:
	Texturas();
	Texturas(int h, int w, int x, int y);
	virtual ~Texturas();
	//métodos públicos para cargar y pintar
	bool load(SDL_Renderer*prender, std::string const& nombArch);
	void draw(SDL_Renderer*prender, SDL_Rect* const &rect2, SDL_Rect* const& rect);
	void drawInvertido(SDL_Renderer*prender, SDL_Rect* const& rect2, SDL_Rect* const& rect);

	//Para la fuente
	Font myFont;

	bool loadFuente(std::string fuente, int tamaño);
	bool loadFromText(SDL_Renderer* pRender, const std::string texture, SDL_Color color);
	//SDL_Rect setRect(int h, int w, int x, int y);

	void setColor(Uint8 red, Uint8 green, Uint8 blue){ SDL_SetTextureColorMod(ptext, red, green, blue); }
	void setColor(Uint8 alpha){ SDL_SetTextureAlphaMod(ptext, alpha); };
	   
		
	SDL_Texture* ptext;
private:
	SDL_Surface* pSurface;
	SDL_Rect rectFont;

	int alto; // en principio las texturas han de ser cuadradas
	int ancho;

	Uint8 red;
	Uint8 green;
	Uint8 blue;
	
};

#endif