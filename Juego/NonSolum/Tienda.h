#ifndef H_TIENDA_H
#define H_TIENDA_H

#include "Estado.h"
#include "VagonTienda.h"
#include "ArmaTienda.h"
#include "Selector.h"
#include "BotonTienda.h"
#include "Menu.h"
#include "Sound.h"

class Tienda :
	public Estado
{
public:
	Tienda(Game* juego);
	~Tienda(){}
	Estado_t getEstado() { return Estado_t::Tienda_t; }
	void draw();
	void onClick();

	void comprar(ObjetoTienda*o) { o->desbloquear(); ptsjuego->buy(o->getPrecio()); }
	void select(Uint32 n);
	void update(Uint32 d);
	bool handle_events(SDL_Event * e);
	void colocarVagon(Game::Vagon_t v);
	void elegirArma(Game::Bala_t a);
	void recolocar(Game * jg);
	void jugar(Game * jg);
	void salir(Game * jg) { jg->pushState(new Menu(jg)); s->stopMusic(); jg->sound->playMusic("../sounds/musicaMenuP.mp3", 2, 12); }
private:
	

	Selector* sel;

	std::vector <BotonTienda*> botones;
	std::vector <VagonTienda*> vags; //  vagones del nivel
	std::vector <ArmaTienda*> armas; //  armas del nivel

	std::vector <VagonTienda*> vagsIzq; // vagones visuales en el tren izq
	ArmaTienda* armaActual; // arma actual elegida

	Game::Bala_t armaNivel; //tipo de arma finalmente usada
	std::vector <Game::Vagon_t> vagonesNivel; // va a contener los tipos de vagones que pasarán a cada nvl sin locomotora
	int seleccionado = 0;

	bool initLibraries();
	Sound* s;
	Sound*s1;
	Sound*s2;
	Sound*s3;
	Sound*s4;

	bool suena = false;

	Texturas* font;
	SDL_Color fontColor;
};

#endif