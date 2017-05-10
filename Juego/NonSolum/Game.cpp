﻿#include "Game.h"
#include "Error.h"
#include "Menu.h"
#include "Play.h"
#include "Pausa.h"

#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <string>


using namespace std;
Game::Game()
{
	//inicialización de texturas desde archivo, SDL y demás atributos privados
	ifstream f;
	int i = 0;
	string file = "../data/init.txt";
	string input;	

	f.open(file, ios::in);
	while (!f.eof()){
		
		if (f.eof())
			break;
	getline(f, input);
	ntexturas[i] = input;
	i++;
	}
	f.close();

	srand(SDL_GetTicks()); // no se que coño es esto xd

	initSDL();
	initMedia();
	espera = false;
	exit = false;


	initLibraries();
	sound = new Sound;

	estados.push(new Menu(this)); // estado que queremos inicial
}



Game::~Game()
{
	freeMedia();
	closeSDL();
	sound->stopMusic();

	pWin = nullptr;
	pRender = nullptr;
}



bool Game::initLibraries() {
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}
	return true;
}
SDL_Renderer* Game::getRender()const {
	return pRender;
}

void Game::initMedia() {
	for (unsigned int i = 0; i < 39 /*magic namber dude*/; i++) {
		texts.emplace_back(new Texturas);
		texts[i]->load(getRender(), ntexturas[i]);
	}
}

void Game::getMousePos(int & mpx, int & mpy) const { //obtener posicion del mouse
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

		SDL_DisplayMode dm;
		if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
			SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
			return 1;
		}
		/*SDL_GetCurrentDisplayMode(0, &dm);
		auto SCREEN_WIDTH = dm.w;
		auto SCEEN_HEIGHT = dm.h;*/

		pWin = SDL_CreateWindow("Non Solum", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
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
	/*if (topEstado()->getEst() == 'P' || topEstado()->getEst() == 'S')
		texts[0]->draw(pRender, nullptr, nullptr);*/
	 if (topEstado()->getEst() == 'M')
		texts[23]->draw(pRender, nullptr, nullptr);
	else if (topEstado()->getEst() == 'W')
		texts[23]->draw(pRender, nullptr, nullptr); // texts[24] for Borja :D
	else if (topEstado()->getEst() == 'L')
		texts[10]->draw(pRender, nullptr, nullptr);
	else if (topEstado()->getEst() == 'T')
		texts[1]->draw(pRender, nullptr, nullptr);
	else if (topEstado()->getEst() == 'C') {
		if (spanish) texts[31]->draw(pRender, nullptr, nullptr);
		else texts[30]->draw(pRender, nullptr, nullptr);
	}
		
	topEstado()->draw();
	SDL_RenderPresent(pRender);
}

////////////////////MAINLOOP///////////////////
void Game::run()
{
	Uint32 delta;
	Uint32 lastUpdate = SDL_GetTicks();
	while (!exit) {
		delta = SDL_GetTicks() - lastUpdate;
		update(delta);
		lastUpdate = SDL_GetTicks();
		render();
		handle_event();
	}
}
//////////////////////////////////////////////

void Game::onClick(int pmx, int pmy) { //se guardan las posiciones que pasan por par�metro
	mx = e.button.x;
	my = e.button.y;
	topEstado()->onClick();
}

//Llama al update del estado activo
void Game::update(Uint32 delta) {

	topEstado()->update(delta);
}


bool Game::handle_event() { //eventos del teclado y raton
	while (SDL_PollEvent(&e) && !exit) {
		if (e.type == SDL_QUIT) {
			exit = true;
		}
		else if (e.type == SDL_KEYUP) {
			if (e.key.keysym.sym == SDLK_s || e.key.keysym.sym == SDLK_w || e.key.keysym.sym == SDLK_a || e.key.keysym.sym == SDLK_d)
				topEstado()->move('N');
			else if (e.key.keysym.sym == SDLK_SPACE && topEstado()->getEst() == 'P')
				topEstado()->dispara(false);
		}
		else if (e.type == SDL_MOUSEBUTTONUP && topEstado()->getEst() == 'P')topEstado()->dispara(false);

		else if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_s) { //mov lateral
				topEstado()->move('S');
			}
			else if (e.key.keysym.sym == SDLK_w) {
				topEstado()->move('W');
			}
			if (e.key.keysym.sym == SDLK_a) {
				topEstado()->move('A');
			}
			else if (e.key.keysym.sym == SDLK_d) {
				topEstado()->move('D');
			}
			if (e.key.keysym.sym == SDLK_ESCAPE) {
				if (topEstado()->getEst() == 'P') pushState(new Pausa(this));
			}

			 if ((e.key.keysym.sym ==  SDLK_l || e.key.keysym.sym == SDLK_SPACE)) {
			
				 topEstado()->dispara(true);
			}
			 
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) { // click izquierdo para llamar al onclick
			if (e.button.state == SDL_BUTTON_LEFT) {
				if(topEstado()->getEst() == 'P')topEstado()->dispara(true);
				onClick(e.button.x, e.button.y);
			}
		}
	}
	return espera;
}

RaizEstado * Game::topEstado() {
	return estados.top();
}

void Game::setSalir() {
	exit = true;
	closeSDL();
}
void Game::changeState(RaizEstado* newSt) {
	popState();
	pushState(newSt);
}
void Game::pushState(RaizEstado* newState) {
	estados.push(newState);
}


void Game::popState() {
	delete estados.top();
	estados.pop();
}
