#include "game.h"
#include "error.h"
#include "play.h"

#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>

game::game()
{
	//inicialización de texturas, SDL y demás atributos privados

	ntexturas[0] = "../bmps/fondo.jpg";
	ntexturas[1] = "../bmps/personaje.jpg";
	ntexturas[2] = "../bmps/enemigo.png";
	ntexturas[3] = "../bmps/tren.png";

	srand(SDL_GetTicks()); // no se que coño es esto xd

	initSDL();
	initMedia();

	espera = false;
	gameOver = false;
	exit = false;

	estados.push(new play(this)); // estado que queremos inicial
}


game::~game()
{
	freeMedia();
	closeSDL();

	pWin = nullptr;
	pRender = nullptr;
}

SDL_Renderer* game::getRender()const {
	return pRender;
}

void game::initMedia() {

	//cargar todo tipo de texturas
	texts.emplace_back(new texturas);
	texts[0]->load(getRender(), ntexturas[0]);

	texts.emplace_back(new texturas);
	texts[1]->load(getRender(), ntexturas[1]);

	texts.emplace_back(new texturas);
	texts[2]->load(getRender(), ntexturas[2]);

	texts.emplace_back(new texturas);
	texts[3]->load(getRender(), ntexturas[3]);

}

void game::freeMedia() {
	//borramos las texturas y hacemos el puntero nulo
	for (int i = 0; i < texts.size(); i++) {
		delete texts[i];
		texts[i] = nullptr;
	}
}


bool game::initSDL() {


	bool success = true; //Initialization flag

						 //Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		throw error("SDL could not initialize!");///////

		std::cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		//Create window: SDL_CreateWindow("SDL Hello World", posX, posY, width, height, SDL_WINDOW_SHOWN);
		//le paso el tama�o que quiero que tenga la ventana de mi juego
		pWin = SDL_CreateWindow("SDL Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1300, 700, SDL_WINDOW_SHOWN);
		if (pWin == nullptr) {
			throw error("Window could not be created!");///////////////

			std::cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			success = false;
		}
		else {
			//Get window surface:
			pRender = SDL_CreateRenderer(pWin, -1, SDL_RENDERER_ACCELERATED);
			//SDL_SetRenderDrawColor(pRender, color.r, color.g, color.b, color.a); //Set background color to black 
			if (pRender == nullptr) {
				throw error("Renderer could not be created!");//////Puedes hacer un error especial para render

				std::cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
				success = false;
			}
		}
	}

	return success;
}

//para destruir la ventana el render y cerrarla
void game::closeSDL() {
	SDL_DestroyRenderer(pRender);
	pRender = nullptr;

	SDL_DestroyWindow(pWin);
	pWin = nullptr;

	SDL_Quit();
}

void game::render() { //const
						 //limpiamos el render
	SDL_RenderClear(pRender);

	//fondo
	texts[0]->draw(pRender, nullptr, nullptr);
	//tren
	texts[3]->draw(pRender, nullptr, nullptr);

	topEstado()->draw();
	SDL_RenderPresent(pRender);
}

void game::run()
{
	Uint32 MSxUpdate = 500; // velocidad del juego
	std::cout << "PLAY \n";
	Uint32 lastUpdate = SDL_GetTicks();
	render();
	espera = handle_event();
	while (!exit && !gameOver) {
		//if ((SDL_GetTicks() - lastUpdate) >= MSxUpdate && !espera) { 
			update();
			lastUpdate = SDL_GetTicks();
		
		render();
		espera = handle_event();
	}
	if (exit)
		std::cout << "EXIT \n";
	
	SDL_Delay(1000);
	//std::cin.get();
}

void game::onClick(int pmx, int pmy) { //se guardan las posiciones que pasan por par�metro
	mx = e.button.x;
	my = e.button.y;
	topEstado()->onClick();
}

void game::update() { //el juego corre mientras existan globos en el juego (aunque puede ser pausado)

	topEstado()->update();
}


bool game::handle_event() { //eventos del teclado y raton
	while (SDL_PollEvent(&e) && !exit) {
		if (e.type == SDL_QUIT) {
			exit = true;
		}
		else if (e.type == SDL_KEYUP) {
			if (e.key.keysym.sym = SDLK_ESCAPE) {
				//pushState(new Pausa(this));				
			}
		}
		else if (e.type == SDL_KEYDOWN){
			if (e.key.keysym.sym == SDLK_s){
				topEstado()->move('S');
			}
			else if (e.key.keysym.sym == SDLK_w){
				topEstado()->move('W');
			}
		}
		
		else if (e.type == SDL_MOUSEBUTTONUP) { // click izquierdo para llamar al onclick
			if (e.button.button == SDL_BUTTON_LEFT) {
				topEstado()->onClick();
			}
		}
	}

	return espera;
}

raizEstado * game::topEstado() {
	return estados.top();
}