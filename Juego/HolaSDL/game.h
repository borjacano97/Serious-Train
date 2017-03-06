#pragma once
#include "Texturas.h"
#include "RaizObjeto.h"
#include "RaizEstado.h"

#include <SDL.h>
#include <vector> // para vectores de texturas, objetos, ect.
#include <string>
#include <stack> //  uso de pila para los estados
class Game{
public:
	Game();
	~Game();

	

	enum Texturas_t { TFondo, TPersonaje, TEnemigo, TTren, TBarra, TBoton};
	Texturas* getTextura(Texturas_t et) const { return texts[et]; }
	SDL_Renderer* getRender() const;

	raizEstado* topEstado();

	void initMedia(); // métodos para cargar y borrar texturas
	void freeMedia();

	void run(); // método principal (bucle del juego)
	void getMousePos(int & mpx, int & mpy) const;

	void changeState(raizEstado* newSt);
	void pushState(raizEstado* newState);
	void popState();
	void setSalir();

private:
	SDL_Window * pWin = nullptr;
	SDL_Renderer* pRender = nullptr;
	SDL_Event e;

	std::string ntexturas[6];
	std::vector<Texturas*> texts;
	std::stack<raizEstado*> estados;

	bool initSDL(); //ventana de render SDL (pantalla)
	void closeSDL();
	void render(); //const
	void onClick(int pmx, int pmy);
	void update();
	bool handle_event();

	bool espera, gameOver, exit;
	int mx, my;
	int cadencia;
};

