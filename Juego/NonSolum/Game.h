#ifndef H_GAME_H
#define H_GAME_H

#include "Texturas.h"
#include "RaizObjeto.h"
#include "RaizEstado.h"
#include "Sound.h"

#include <SDL.h>
#include <vector> // para vectores de texturas, objetos, ect.
#include <string>
#include <stack> //  uso de pila para los estados
class Game {
public:
	Game();
	~Game();

	enum Texturas_t {
		TFondo, TFondoT, TPersonaje, TEnemigo, TEnemigo2, TLocomotora, TVagon1, TVacioBloq, TBarra,
		Tlose, TWin, TRoca, TLaser, TFuegod, TFuegoi, TRect, TVagonAuto, TBotonPosible, TBala, TPistol,
		TEscopeta, TMetralleta, TSniper, TMenuP, TVagonFuego, TVagonLaser, TMinigun, TBotonV, TBotonR, TBotonA, TControlEng, TControlEsp, TEnemigoD, TEnemigoG};
	enum Enemigo_t { Normal, Rapido, Tank, ElQueDispara/*...*/ };
	enum Vagon_t { Locom, Vacio, Automatico, Laser, Lanzallamas, Escudo/*...*/ };
	enum Bala_t { BalaEnem, Piedra, Rayo, Fuego, Escopeta, E1, E2, Pistola, Sniper, Metralleta, Minigun /*...*/ };
	enum Boton_t { Comprar, Jugar, Recolocar, Salir, Supervivencia, Historia, Spanish, English, Volver, Controles /*...*/ };
	enum EnemyDmg_t { Simple, Explosion, Bala };
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

	bool tiendaCreada = false;
	bool spanish = true;
	bool survival = false;

	std::vector<Texturas*> texts;
	Sound* sound;

private:
	
	SDL_Event e;

	std::string ntexturas[34]; 
	
	std::stack<RaizEstado*> estados;

	bool initSDL(); //ventana de render SDL (pantalla)
	void closeSDL();
	void render(); //const
	void onClick(int pmx, int pmy);
	void update(Uint32 delta);
	bool handle_event();
	bool initLibraries();

	bool espera, exit;
	int mx, my;
	int nivel = 1;
};


#endif