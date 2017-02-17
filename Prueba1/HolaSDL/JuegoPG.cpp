#include "JuegoPG.h"
#include "Globo.h"
#include "GloboA.h"
#include "Mariposa.h"
#include "Premio.h"
#include "SDLError.h"
#include "PlayPG.h"
#include "Pausa.h"
#include "MenuPG.h"
#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>



JuegoPG::JuegoPG()
{  
	//array de ntexturas
	ntexturas[0] = "../bmps/fondo.png";
	ntexturas[1] = "../bmps/globo.png";
	ntexturas[2] = "../bmps/mariposa.png";
	ntexturas[3] = "../bmps/premio.png";
	ntexturas[4] = "../bmps/buttonContinuar.png";
	ntexturas[5] = "../bmps/buttonJugar.png";
	ntexturas[6] = "../bmps/buttonMenu.png";
	ntexturas[7] = "../bmps/buttonSalir.png";
	ntexturas[8] = "../bmps/buttonScore.png";

	srand(SDL_GetTicks());

	gameOver = false;
	
	exit = false;
	espera = false;
	puntos = 0;

	initSDL();
	initMedia();

	Estados.push(new MenuPG(this));

}


JuegoPG::~JuegoPG()
{
	freeMedia();
	closeSDL();
	pWin = nullptr;
	pRender = nullptr;
	while (!Estados.empty()){
		popState();
	}
}

SDL_Renderer* JuegoPG::getRender()const{
	return pRender;
}

void JuegoPG::getMousePos(int & mpx, int & mpy) const{ //obtener posicion del mouse
	mpx = mx;
	mpy = my;
}


void JuegoPG::initMedia(){

	//cargar todo tipo de texturas
		texturas.emplace_back(new texturasSDL);
		texturas[0]->load(getRender(), ntexturas[0]);

		texturas.emplace_back(new texturasSDL);
		texturas[1]->load(getRender(), ntexturas[1]);

		texturas.emplace_back(new texturasSDL);
		texturas[2]->load(getRender(), ntexturas[2]);

		texturas.emplace_back(new texturasSDL);
		texturas[3]->load(getRender(), ntexturas[3]);

		texturas.emplace_back(new texturasSDL);
		texturas[4]->load(getRender(), ntexturas[4]);

		texturas.emplace_back(new texturasSDL);
		texturas[5]->load(getRender(), ntexturas[5]);

		texturas.emplace_back(new texturasSDL);
		texturas[6]->load(getRender(), ntexturas[6]);

		texturas.emplace_back(new texturasSDL);
		texturas[7]->load(getRender(), ntexturas[7]);

		texturas.emplace_back(new texturasSDL);
		texturas[8]->load(getRender(), ntexturas[8]);

}

void JuegoPG::freeMedia(){
	//borramos las texturas y hacemos el puntero nulo
	for (int i = 0; i < texturas.size(); i++){
		delete texturas[i];
		texturas[i] = nullptr;
	}
}




void JuegoPG::run(){ 

	Uint32 MSxUpdate = 500;
	std::cout << "PLAY \n";
	Uint32 lastUpdate = SDL_GetTicks();
	render();
	espera = handle_event();
	while (!exit && !gameOver) {
		if ((SDL_GetTicks() - lastUpdate) >= MSxUpdate && !espera) { // while(elapsed >= MSxUpdate)
			update();
			lastUpdate = SDL_GetTicks();
		}
		render();
		espera = handle_event();
	}
	if (exit)
		std::cout << "EXIT \n";
	else {//para que aparezca la ventana final con la puntuacion
		std::cout << "Has obtenido " << puntos << " puntos\n";
		std::string spuntos = "HAS OBTENIDO " + std::to_string(puntos) + " PUNTOS";
		char const *cpuntos = spuntos.c_str();

		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "END GAME", cpuntos, nullptr);
	}
	SDL_Delay(1000);
	//std::cin.get();

}


bool JuegoPG::initSDL() {


	bool success = true; //Initialization flag

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		throw SDLError("SDL could not initialize!");///////

		std::cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		//Create window: SDL_CreateWindow("SDL Hello World", posX, posY, width, height, SDL_WINDOW_SHOWN);
		//le paso el tamaño que quiero que tenga la ventana de mi juego
		pWin = SDL_CreateWindow("SDL Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, alto, ancho, SDL_WINDOW_SHOWN);
		if (pWin == nullptr){
			throw SDLError("Window could not be created!");///////////////

			std::cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			success = false;
		}
		else {
			//Get window surface:
			pRender = SDL_CreateRenderer(pWin, -1, SDL_RENDERER_ACCELERATED);
			//SDL_SetRenderDrawColor(pRender, color.r, color.g, color.b, color.a); //Set background color to black 
			if (pRender == nullptr){
				throw SDLError("Renderer could not be created!");//////Puedes hacer un error especial para render

				std::cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
				success = false;
			}
		}
	}

	return success;
}

//para destruir la ventana el render y cerrarla
void JuegoPG::closeSDL() {
	SDL_DestroyRenderer(pRender);
	pRender = nullptr;

	SDL_DestroyWindow(pWin);
	pWin = nullptr;

	SDL_Quit();
}



void JuegoPG::render(){ //const
	//limpiamos el render
	SDL_RenderClear(pRender);

	//fondo
	texturas[0]->draw(pRender, nullptr, nullptr);

	topEstado()->draw();
	SDL_RenderPresent(pRender);
}


void JuegoPG::onClick(int pmx, int pmy){ //se guardan las posiciones que pasan por parámetro
	mx = e.button.x;
	my = e.button.y;
	topEstado()->onClick();
}

void JuegoPG::update(){ //el juego corre mientras existan globos en el juego (aunque puede ser pausado)
	
	topEstado()->update();
}


bool JuegoPG::handle_event(){ //eventos del teclado y ratón
	while (SDL_PollEvent(&e) && !exit) {
		if (e.type == SDL_QUIT){
			exit = true;
			std::cout << "QUIT";
		}
		else if (e.type == SDL_KEYUP){
			if (e.key.keysym.sym = SDLK_ESCAPE){
				pushState(new Pausa(this));
				std::cout << "PAUSE \n";
			}
		}
		else if (e.type == SDL_MOUSEBUTTONUP) { // click izquierdo para llamar al onclick
			if (e.button.button == SDL_BUTTON_LEFT) {
				std::cout <<puntos << " CLICK \n";
				onClick(e.button.x, e.button.y);
				
			}
		}
	}

	return espera;
}


EstadoJuego * JuegoPG::topEstado(){
	return Estados.top();
}

void JuegoPG::changeState(EstadoJuego* newSt){
		popState();
		pushState(newSt);
}


void JuegoPG::pushState(EstadoJuego* newState){
	Estados.push(newState);
}


void JuegoPG::popState(){
	delete Estados.top();
	Estados.pop();
}


void JuegoPG::setSalir(){
	exit = true;
	closeSDL();
	
}

void JuegoPG::darPuntos(int i){
	puntos = i;
}

int JuegoPG::damePuntos(){
	return puntos;
}
