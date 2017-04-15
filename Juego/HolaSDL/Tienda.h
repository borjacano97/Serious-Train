#ifndef H_TIENDA_H
#define H_TIENDA_H

#include "estado.h"
#include "ObjetoTienda.h"

class Tienda :
	public Estado
{
public:
	Tienda(Game* juego);
	~Tienda(){}
	char getEst(){  return 'T';}
	void draw();
	void onClick();
	void comprar(ObjetoTienda*o) { o->desbloquear(); ptsjuego->buy(o->getPoints()); }
private:
	static void recolocar(Game * jg);
	static void jugar(Game * jg);

	Texturas* font;
	SDL_Color fontColor;

	std::vector <Game::Vagon_t> vagonesNivel; // va a contener los tipos de vagones que pasarán a cada nvl sin locomotora
	std::vector <ObjetoTienda*> objs; // armas y vagones del nivel
};

#endif