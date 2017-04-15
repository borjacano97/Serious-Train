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
		TFondo, TPersonaje, TEnemigo, TEnemigo2, TLocomotora, TVagon1, TVacioBloq, TBarra, TBotonJ, TBotonS, TBotonC, TBtienda1, TBtienda2, Tlose, TWin,
		 TRoca, TLaser, TFuegod, TFuegoi	};
	enum Enemigo_t { Normal, Rapido/*...*/ };
	enum Vagon_t { Locom, Vacio, Automatico, Laser, Lanzallamas/*...*/ };
	enum Bala_t { Piedra, Rayo, Fuego/*...*/ };


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
	void buy(int n) { for (unsigned int i = 0; i < n; i++) coins--; }
	SDL_Window * pWin = nullptr;
	SDL_Renderer* pRender = nullptr;
	int coins = 0;

private:
	/*SDL_Window * pWin = nullptr;
	SDL_Renderer* pRender = nullptr;*/
	SDL_Event e;

	std::string ntexturas[19];
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