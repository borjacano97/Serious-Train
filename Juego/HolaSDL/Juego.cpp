#include "Juego.h"
#include "error.h"

#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>

Juego::Juego()
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
}


Juego::~Juego()
{
	freeMedia();
	closeSDL();

	pWin = nullptr;
	pRender = nullptr;
}

SDL_Renderer* Juego::getRender()const {
	return pRender;
}

void Juego::initMedia() {

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

void Juego::freeMedia() {
	//borramos las texturas y hacemos el puntero nulo
	for (int i = 0; i < texts.size(); i++) {
		delete texts[i];
		texts[i] = nullptr;
	}
}


bool Juego::initSDL() {


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
		pWin = SDL_CreateWindow("SDL Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);
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
void Juego::closeSDL() {
	SDL_DestroyRenderer(pRender);
	pRender = nullptr;

	SDL_DestroyWindow(pWin);
	pWin = nullptr;

	SDL_Quit();
}

void Juego::render() { //const
						 //limpiamos el render
	SDL_RenderClear(pRender);

	//fondo
	texts[0]->draw(pRender, nullptr, nullptr);

	SDL_RenderPresent(pRender);
}

void Juego::run()
{
	Uint32 MSxUpdate = 500; // velocidad del juego
	std::cout << "PLAY \n";
	Uint32 lastUpdate = SDL_GetTicks();
	render();
	espera = handle_event();
	while (!exit && !gameOver) {
		if ((SDL_GetTicks() - lastUpdate) >= MSxUpdate && !espera) { 
			update();
			lastUpdate = SDL_GetTicks();
		}
		render();
		espera = handle_event();
	}
	if (exit)
		std::cout << "EXIT \n";
	
	SDL_Delay(1000);
	//std::cin.get();
}