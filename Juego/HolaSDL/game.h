#pragma once
#include "texturas.h"
#include "raizObjeto.h"
#include "raizEstado.h"

#include <SDL.h>
#include <vector> // para vectores de texturas, objetos, ect.
#include <string>
#include <stack> //  uso de pila para los estados
class game 

{
public:
	game();
	~game();

	

	enum Texturas_t { TFondo, TPersonaje, TEnemigo, TTren, TBarra};
	texturas* getTextura(Texturas_t et) const { return texts[et]; }
	SDL_Renderer* getRender() const;

	raizEstado* topEstado();

	void initMedia(); // métodos para cargar y borrar texturas
	void freeMedia();

	void run(); // método principal (bucle del juego)

private:
	SDL_Window * pWin = nullptr;
	SDL_Renderer* pRender = nullptr;
	SDL_Event e;

	std::string ntexturas[5];
	std::vector<texturas*> texts;
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

