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
	    TSlender, TExplosion, TLaserRoto, TEscudoRoto, TFuegoRoto, TAutoRoto, TVagonSuc, TVacioR, TSucR, TRegR, 
		TCanonN, TBotonOsc, TPausa, TBala2, THistoria1, TFondoIni, TLogo, TSangre, THistoria2, THistoria3, THistoria4, THistoria5, TBoss,
	    THistEsp1, THistEsp2, THistEsp3, THistEsp4, THistEsp5, THistEng1, THistEng2, THistEng3, THistEng4, THistEng5, TTramoFinal,
		TTramoRoca, THistoria6, THistoriaEspFin, THistoriaEngFin, TCreditosEsp, TCreditosEng, TFondoCreditos};
	enum Enemigo_t { Normal, Rapido, Tank, Enano, Invisible, Slender, Tocho, Boss/*...*/ };
	enum Vagon_t { Locom, Vacio, Automatico, Laser, Lanzallamas, Escudo, Recuperador, Succionador/*...*/ };
	enum Bala_t { BalaEnem, Piedra, Rayo, Fuego, Escopeta, E1, E2, Pistola, Sniper, Metralleta, Minigun, Canon, BalaEnemGorda/*...*/ };
	enum Boton_t { Comprar, Jugar, Recolocar, Salir, Supervivencia, Historia, Spanish, English, Volver, CreditosB, Extrem, Desb /*...*/ };
	enum EnemyDmg_t { Simple, Explosion, Bala };
	enum Hud_t { Tick, Hud1, Trayecto, Tren, Fondo, BotonOsc, Logo, Sangre, LetrasHist, Creditos};
	enum Fondo_t { Control, MenuP, Win, Lose, Tienda, Pause, History, FondoInicio};
	
	std::string chooseText(string textArr[]);


	Texturas* getTextura(Texturas_t et) const { return texts[et]; }
	SDL_Renderer* getRender() const;

	RaizEstado* topEstado();

	void initMedia(); // m�todos para cargar y borrar texturas
	void freeMedia();

	void run(); // m�todo principal (bucle del juego)
	void getMousePos(int & mpx, int & mpy) const;

	void changeState(RaizEstado* newSt);
	void pushState(RaizEstado* newState);
	void popState();
	void setSalir();
	void incrNivel() { nivel++; }
	int getNivel() { return nivel;; }
	void addCoins(int n) { coins += n; }
	void buy(int n) { coins -= n; }
	void restart(){
		coins = 0;
		nivel = 1;
		desbloquear = true;
	}
	SDL_Window * pWin = nullptr;
	SDL_Renderer* pRender = nullptr;

	int contRondas = 1; // svl y extrem
	bool tiendaCreada = false;
	bool spanish = true;
	bool survival = false;
	bool extrem = false;
	bool bigHP = false;
	bool paused = false;

	bool primerArma = false;
	bool primerVagon = false;
	bool segundoArma = false;

	bool desbloquear = false; // solo para version no definitiva, desbloquear svl y extrem

	std::vector<Texturas*> texts;
	Sound* sound;
	Texturas* font;
	SDL_Color fontColor;
	string* arrTextSpa = new string[15];
	string* arrTextEng = new string[15];

	std::stack<RaizEstado*> estados;

	int coins = 0;

private:

	int nivel = 1;

	SDL_Event e;

	std::string ntexturas[92]; 
	

	bool initSDL(); //ventana de render SDL (pantalla)
	void closeSDL();
	void render(); //const
	void onClick(int pmx, int pmy);
	void update(Uint32 delta);
	bool handle_event();
	bool initLibraries();

	bool espera, exit;
	int mx, my;
	int cont = 0;
	bool shown = false;
	int arrIndex = 0;
	string texto;

	/***************************************************************************/
	//Propongo pantalla de inicio en la que eliges el idioma.

	/***************************************************************************/
};


#endif