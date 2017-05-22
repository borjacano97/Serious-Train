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

using namespace std;
class Game {
public:
	Game();
	virtual ~Game();

	enum Texturas_t {
		TFondo, TFondoT, TPersonaje, TEnemigo, TEnemigo2, TLocomotora, TVagon1, TVacioBloq, TBarra,
		TWin, TLose, TRoca, TLaser, TFuegod, TFuegoi, TRect, TVagonAuto, TBotonPosible, TBala, TPistol,
		TEscopeta, TMetralleta, TSniper, TMenuP, TVagonFuego, TVagonLaser, TMinigun, TBotonV, TBotonR, TBotonA, 
		TControlEng, TControlEsp, TEnemigoD, TEnemigoG, TCanon, TTick, THud, TTrayecto, THud2, TVagonReg, TDesierto,
		TPradera, TVagonEscudo, TOscuridad, TTocho, TInvisible, TEscopetaN, TFrancoN, TMetralletaN, TMinigunN, TRevolverN,
	    TSlender, TExplosion, TLaserRoto, TEscudoRoto, TFuegoRoto, TAutoRoto, TVagonSuc, TVacioR, TSucR, TRegR, TCanonN};
	enum Enemigo_t { Normal, Rapido, Tank, Enano, Invisible, Slender, Tocho/*...*/ };
	enum Vagon_t { Locom, Vacio, Automatico, Laser, Lanzallamas, Escudo, Recuperador, Succionador/*...*/ };
	enum Bala_t { BalaEnem, Piedra, Rayo, Fuego, Escopeta, E1, E2, Pistola, Sniper, Metralleta, Minigun, Canon /*...*/ };
	enum Boton_t { Comprar, Jugar, Recolocar, Salir, Supervivencia, Historia, Spanish, English, Volver, Controles, Extrem /*...*/ };
	enum EnemyDmg_t { Simple, Explosion, Bala };
	enum Hud_t { Tick, Hud1, Trayecto, Tren, Fondo};
	enum Fondo_t { Control, MenuP, Win, Lose, Tienda};
	
	std::string chooseText(string textArr[]);


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

	int contRondas = 1;
	bool tiendaCreada = false;
	bool spanish = true;
	bool survival = false;
	bool extrem = false;
	bool bigHP = false;
	std::vector<Texturas*> texts;
	Sound* sound;
	Texturas* font;
	SDL_Color fontColor;
	string* arrTextSpa = new string[15];
	string* arrTextEng = new string[15];

private:
	
	SDL_Event e;

	std::string ntexturas[62]; 
	
	std::stack<RaizEstado*> estados;

	bool initSDL(); //ventana de render SDL (pantalla)
	void closeSDL();
	void render(); //const
	void onClick(int pmx, int pmy);
	void update(Uint32 delta);
	void draw();
	bool handle_event();
	bool initLibraries();

	bool espera, exit;
	int mx, my;
	int nivel = 1;
	int cont = 0;
	bool shown = false;
	int arrIndex = 0;
	string texto;

	/***************************************************************************/
	//Propongo pantalla de inicio en la que eliges el idioma.

	/***************************************************************************/
};


#endif