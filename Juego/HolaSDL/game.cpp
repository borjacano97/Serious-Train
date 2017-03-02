#include "game.h"
#include "error.h"
#include "menu.h"
#include "play.h"

#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>

Game::Game()
{
	//inicialización de texturas, SDL y demás atributos privados

	ntexturas[0] = "../bmps/fondo.jpg";
	ntexturas[1] = "../bmps/personaje.jpg";
	ntexturas[2] = "../bmps/enemigo.png";
	ntexturas[3] = "../bmps/tren.png";
	ntexturas[4] = "../bmps/barraHP.png";
	ntexturas[5] = "../bmps/boton.png";

	srand(SDL_GetTicks()); // no se que coño es esto xd

	initSDL();
	initMedia();

	espera = false;
	gameOver = false;
	exit = false;
	cadencia = 20;

	estados.push(new Menu(this)); // estado que queremos inicial
}


Game::~Game()
{
	freeMedia();
	closeSDL();

	pWin = nullptr;
	pRender = nullptr;
}

SDL_Renderer* Game::getRender()const {
	return pRender;
}

void Game::initMedia() {

	//cargar todo tipo de texturas
	texts.emplace_back(new Texturas);
	texts[0]->load(getRender(), ntexturas[0]);

	texts.emplace_back(new Texturas);
	texts[1]->load(getRender(), ntexturas[1]);

	texts.emplace_back(new Texturas);
	texts[2]->load(getRender(), ntexturas[2]);

	texts.emplace_back(new Texturas);
	texts[3]->load(getRender(), ntexturas[3]);

	texts.emplace_back(new Texturas);
	texts[4]->load(getRender(), ntexturas[4]);

	texts.emplace_back(new Texturas);
	texts[5]->load(getRender(), ntexturas[5]);

}

void Game::getMousePos(int & mpx, int & mpy) const{ //obtener posicion del mouse
	mpx = mx;
	mpy = my;
}

void Game::freeMedia() {
	//borramos las texturas y hacemos el puntero nulo
	for (unsigned int i = 0; i < texts.size(); i++) {
		delete texts[i];
		texts[i] = nullptr;
	}
}


bool Game::initSDL() {


	bool success = true; //Initialization flag

						 //Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		throw Error("SDL could not initialize!");///////

		std::cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		//Create window: SDL_CreateWindow("SDL Hello World", posX, posY, width, height, SDL_WINDOW_SHOWN);
		//le paso el tama�o que quiero que tenga la ventana de mi juego
		pWin = SDL_CreateWindow("SDL Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1300, 700, SDL_WINDOW_SHOWN);
		if (pWin == nullptr) {
			throw Error("Window could not be created!");///////////////

			std::cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			success = false;
		}
		else {
			//Get window surface:
			pRender = SDL_CreateRenderer(pWin, -1, SDL_RENDERER_ACCELERATED);
			//SDL_SetRenderDrawColor(pRender, color.r, color.g, color.b, color.a); //Set background color to black 
			if (pRender == nullptr) {
				throw Error("Renderer could not be created!");//////Puedes hacer un error especial para render

				std::cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
				success = false;
			}
		}
	}

	return success;
}

//para destruir la ventana el render y cerrarla
void Game::closeSDL() {
	SDL_DestroyRenderer(pRender);
	pRender = nullptr;

	SDL_DestroyWindow(pWin);
	pWin = nullptr;

	SDL_Quit();
}

void Game::render() { //const
						 //limpiamos el render
	SDL_RenderClear(pRender);

	//fondo
	texts[0]->draw(pRender, nullptr, nullptr);
	

	topEstado()->draw();
	SDL_RenderPresent(pRender);
}

void Game::run()
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

void Game::onClick(int pmx, int pmy) { //se guardan las posiciones que pasan por par�metro
	mx = e.button.x;
	my = e.button.y;
	topEstado()->onClick();
}

void Game::update() { //el juego corre mientras existan globos en el juego (aunque puede ser pausado)

	topEstado()->update();
}


bool Game::handle_event() { //eventos del teclado y raton
	while (SDL_PollEvent(&e) && !exit) {
		if (e.type == SDL_QUIT) {
			exit = true;
		}
		else if (e.type == SDL_KEYUP) {
			if (e.key.keysym.sym == SDLK_s || e.key.keysym.sym == SDLK_w || e.key.keysym.sym == SDLK_a || e.key.keysym.sym == SDLK_d)
			    topEstado()->move('N');
		}
		else if (e.type == SDL_KEYDOWN){
			if (e.key.keysym.sym == SDLK_s){ //mov lateral
				topEstado()->move('S');
			}
			else if (e.key.keysym.sym == SDLK_w){
				topEstado()->move('W');
			}
			if (e.key.keysym.sym == SDLK_a) {
				topEstado()->move('A');
			}
			else if (e.key.keysym.sym == SDLK_d) {
				topEstado()->move('D');
			}	
			if (e.key.keysym.sym = SDLK_ESCAPE) {
				//pushState(new Pausa(this));				
			}
		}
		

		else if (e.type == SDL_MOUSEBUTTONDOWN) { // click izquierdo para llamar al onclick
			if (e.button.state == SDL_BUTTON_LEFT && cadencia >=100) {
				cadencia = 0;
				topEstado()->onClick();
				onClick(e.button.x, e.button.y);
			}
		}

	}
	cadencia++;
	return espera;
}

raizEstado * Game::topEstado() {
	return estados.top();
}

void Game::setSalir(){
	exit = true;
	closeSDL();

}
void Game::changeState(raizEstado* newSt){
	popState();
	pushState(newSt);
}
void Game::pushState(raizEstado* newState){
	estados.push(newState);
}


void Game::popState(){
	delete estados.top();
	estados.pop();
}