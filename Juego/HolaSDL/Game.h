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
		TFondo, TPersonaje, TEnemigo, TEnemigo2, TLocomotora, TBarra, TBotonJ, TBotonS, TBotonC, Tlose, TWin,
		TVagon1, TVagon2, TVagon3, TVagon4, TRoca, TLaser
	};
	enum Enemigo_t { Normal, Rapido/*...*/ };
	enum Vagon_t { Locom, Vacio, Automatico, Laser/*...*/ };
	enum Bala_t { Piedra, Rayo/*...*/ };


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
	void addCoins(int n) { coins += n; std::cout << coins << "\n"; }
	SDL_Window * pWin = nullptr;
	SDL_Renderer* pRender = nullptr;
	int coins = 0;

private:
	/*SDL_Window * pWin = nullptr;
	SDL_Renderer* pRender = nullptr;*/
	SDL_Event e;

	std::string ntexturas[17];
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