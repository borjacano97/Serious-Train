#include "Game.h"
#include "Error.h"
#include "Menu.h"
#include "Play.h"
#include "Pausa.h"

#include <iostream>
#include <fstream>
#include <typeinfo>
#include <ctime> 
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

	//srand(SDL_GetTicks()); // no se que coño es esto xd

	initSDL();
	initMedia();
	espera = false;
	exit = false;


	initLibraries();
	sound = new Sound;
	TTF_Init();
	font = new Texturas();
	font->loadFuente("../fonts/fuentenumbers.ttf", 300);
	fontColor.r = 250;
	fontColor.g = 250;
	fontColor.b = 250;

	arrTextSpa[0] = "Gasta monedas en armas y vagones";
	arrTextSpa[1] = "Mata enemigos para conseguir monedas";
	arrTextSpa[2] = "Todos los vagones tienen utilidad, colocalos estrategicamente";
	arrTextSpa[3] = "Desafia a tus amigos en el modo supervivencia";
	arrTextSpa[4] = "No olvides colocar los vagones antes de comenzar la aventura";
	arrTextSpa[5] = "Quien conduce el tren?";
	arrTextSpa[6] = "Como pudo mutar el zombie volador? esas alas no le pegan";
	arrTextSpa[7] = "Sabias que en 1815 Stephenson construyo la primera locomotora de vapor?";
	arrTextSpa[8] = "Prueba tus habilidades en el modo Extremo!";
	arrTextSpa[9] = "Utiliza el vagon regenerador, para recuperar vida";
	arrTextSpa[10] = "Cuidado con los enemigos, tienen sed de venganza";
	arrTextSpa[11] = "Manten presionado el raton para disparar continuamente";
	arrTextSpa[12] = "Sabias que la revolucion industrial trajo consigo la tecnologia?";
	arrTextSpa[13] = "Sumergete en el modo historia y conoce el interior del Ubi Trinus!";
	arrTextSpa[14] = "Siguenos en Twitter - nonSolum";

	arrTextEng[0] = "Spend coins on weapons and wagons";
	arrTextEng[1] = "Kill enemies for getting coins";
	arrTextEng[2] = "Every wagon has its own utility, place them strategically";
	arrTextEng[3] = "Challenge your friends in survival mode";
	arrTextEng[4] = "Don't forget placing your wagons before starting the adventure";
	arrTextEng[5] = "Who drives the train?";
	arrTextEng[6] = "How could the flying zombie mutate?. That wings doesn't fit him!";
	arrTextEng[7] = "Did you know that Stephenson built the first steam locomotive in 1815?";
	arrTextEng[8] = "Try your habilities in the Extreme Mode!";
	arrTextEng[9] = "Use the regenerator wagon for getting extra life";
	arrTextEng[10] = "Take care with the enemies, they want revenge!";
	arrTextEng[11] = "Hold down the mouse for shooting repeatedly";
	arrTextEng[12] = "Did you know that Industrial Revolution brought with it technology?";
	arrTextEng[13] = "In story mode you can discover the entrails of Ubi Trinus!";
	arrTextEng[14] = "Follow us on Twitter - nonSolum";

	// ejemplos pa textos:

	// no olvides colocarte los vagones antes de comenzar la aventura
	// el vagón escudo te proporciona una vida extra que te puede salvar el cuello
	// colocate encima del vagon regenerador, ya verás lo que pasa!
	// yo no dejaría hacercarse mucho a los zombies gordos, parece que vayan a explotar!!
	// cambia de ambientación cada 3 niveles en el modo historia!!
	// mantén presionado el raton para disparar continuamente
	// si te equivocas al elegir, no dudes volver atrás, todos tus cambios se guardan
	// algunos niveles de la historia son imposibles pasarselos a la primera, no te frustres
	// algunos enemigos no se pueden matar con las armas de corta distancia, ten cuidado
	// por que el zombie con capucha nunca ataca? es inquietante
	// dale al boton de recolocar si te equivocas eligiendo vagones
	// solo puedes usar un vagon de cada tipo, usalos con cabeza!!
	// quien conduce el tren? :O
	// en supervivencia, las rondas cada vez son mas largas y dificiles
	// el record mundial actualmente es de 8 rondas en el modo supervivencia
	// como pudo mutar el zombie volador? esas alas no le pegan
	// los zombies no son muy listos, yo creo que incluso se les puede poner un cebo...
	// ten cuidado con los zombies que aparecen desde mas abajo!!
	// yo que tú mataría a los zombies enanos lo antes posible
	// adentrate en el modo historia y cruza una gran variedad de lugares!!
	// el zombie volador empezó siendo una lechuza
	// sabias que solo hay una seta en todo el juego? encuentrala
	// a nuestro personaje le ha dado mucho el sol
	// sabias que los zombies son azules porque no respiran??

	//textoo = chooseText(arrTextSpa);



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
	for (unsigned int i = 0; i < 66 /*magic namber dude*/; i++) {
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

string Game::chooseText(string textArr[]) {

		//std::cout << "ALEATORIO: " << arrIndex << std::endl;
		srand((unsigned)time(0));
		arrIndex = rand() % 15;
		texto = textArr[arrIndex];

	return texto;
}
