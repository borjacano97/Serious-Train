#pragma once
#include <vector>
#include <string>
#include "ObjetoJuego.h"
#include <SDL.h>
#include "texturasSDL.h"
#include "EstadoJuego.h"
#include <stack>

class JuegoPG
{
public:
	JuegoPG();
	~JuegoPG();
	void run();


	enum Texturas_t {TFondo, TGlobo, TMariposa, TPremio, BContinuar, BJugar, BMenu, BSalir, BScore};


	texturasSDL* getTextura(Texturas_t et) const { return texturas[et]; }
	SDL_Renderer* getRender() const;
	void getMousePos(int & mpx, int & mpy) const; 
	
	void initMedia(); 
	void freeMedia();

	
	void darPuntos(int i);
	int damePuntos();

	EstadoJuego* topEstado();
	void changeState(EstadoJuego* newSt);
	void pushState(EstadoJuego* newState);
	void popState();
	void setSalir();
	

private:

	SDL_Window * pWin  = nullptr;
	SDL_Renderer* pRender = nullptr;

	std::string ntexturas[9];

	int puntos;

	std::vector<texturasSDL*> texturas;

	int alto = 1500;
	int ancho = 800;


	int mx;
	int my;



	SDL_Color color;


	bool error;
	bool gameOver;
	bool exit;
	bool espera;//evaluacion1

	SDL_Event e;

	bool initSDL();
	void closeSDL();
	void render(); //const
	void onClick(int pmx, int pmy);
	void update();
	bool handle_event();
	void onExit();


	std::stack<EstadoJuego*> Estados; 

	EstadoJuego * ptestados;
};