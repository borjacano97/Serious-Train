#ifndef H_GAME_H
#define H_GAME_H

#include "Texturas.h"
#include "RaizObjeto.h"
#include "RaizEstado.h"

#include <SDL.h>
#include <vector> // para vectores de texturas, objetos, ect.
#include <string>
#include <stack> //  uso de pila para los estados
class Game {
public:
	Game();
	~Game();

	enum Texturas_t {
		TFondo, TFondoT, TPersonaje, TEnemigo, TEnemigo2, TLocomotora, TVagon1, TVacioBloq, TBarra, TBotonJ, TBotonS, TBotonC, TBotonB, 
		TBtienda1, TBtienda2, Tlose, TWin, TRoca, TLaser, TFuegod, TFuegoi, TRect, TVagonAuto, TBotonPosible};
	enum Enemigo_t { Normal, Rapido, Tank, ElQueDispara/*...*/ };
	enum Vagon_t { Locom, Vacio, Automatico, Laser, Lanzallamas/*...*/ };
	enum Bala_t { BalaEnem, Piedra, Rayo, Fuego/*...*/ };
	enum Boton_t { Comprar, Jugar, Recolocar/*...*/ };

	Texturas* getTextura(Texturas_t et) const { return texts[et]; }
	SDL_Renderer* getRender() const;

	RaizEstado* topEstado();

	void initMedia(); // métodos para cargar y borrar texturas
	void freeMedia();

	void run(); // método principal (bucle del juego)
	void getMousePos(int & mpx, int & mpy) const;

	void changeState(RaizEstado* newSt);
	void pushState(RaizEstado* newState);
	void popState();
	void setSalir();
	void incrNivel() { nivel++; }
	int getNivel() { return nivel;; }
	void addCoins(int n) { coins += n; }
	void buy(int n) { coins -= n; }

	SDL_Window * pWin = nullptr;
	SDL_Renderer* pRender = nullptr;
	int coins = 0;

private:
	/*SDL_Window * pWin = nullptr;
	SDL_Renderer* pRender = nullptr;*/
	SDL_Event e;

	std::string ntexturas[24];
	std::vector<Texturas*> texts;
	std::stack<RaizEstado*> estados;

	bool initSDL(); //ventana de render SDL (pantalla)
	void closeSDL();
	void render(); //const
	void onClick(int pmx, int pmy);
	void update(Uint32 delta);
	bool handle_event();


	bool espera, exit;
	int mx, my;
	int cadencia;
	int nivel = 1;

};


#endif