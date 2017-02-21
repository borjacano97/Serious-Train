#pragma once
#include "texturas.h"
#include "raizObjeto.h"
#include "raizEstado.h"

#include <SDL.h>
#include <vector> // para vectores de texturas, objetos, ect.
#include <string>
#include <stack> //  uso de pila para los estados
class Juego 
// la he puesto como �nica clase en may�scula por ser la m�s importante, desde aqu� se llaman a las dem�s ra�ces
{
public:
	Juego();
	~Juego();

	

	enum Texturas_t { TFondo, TPersonaje, TEnemigo, TTren};
	texturas* getTextura(Texturas_t et) const { return texts[et]; }
	SDL_Renderer* getRender() const;

	raizEstado* topEstado();

	void initMedia(); // m�todos para cargar y borrar texturas
	void freeMedia();

	void run(); // m�todo principal (bucle del juego)

private:
	SDL_Window * pWin = nullptr;
	SDL_Renderer* pRender = nullptr;
	SDL_Event e;

	std::string ntexturas[4];
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
};

