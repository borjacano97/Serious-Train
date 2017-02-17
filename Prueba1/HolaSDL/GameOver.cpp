#include "GameOver.h"
#include "MenuPG.h"


GameOver::GameOver(JuegoPG* juego) : EstadoPG(juego)
{
	objetos.emplace_back(new Boton(ptsjuego, JuegoPG::BScore, 800, 400, score));
	objetos.emplace_back(new Boton(ptsjuego, JuegoPG::BMenu, 400, 400, menu));
}


GameOver::~GameOver()
{
}


void GameOver::score(JuegoPG * jg){
	std::string puntos = "Has obtenido " + std::to_string(jg->damePuntos()) + " puntos";
	char const *puntosChar = puntos.c_str();
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Puntuacion", puntosChar, nullptr);
}

void GameOver::menu(JuegoPG * jg){
	jg->changeState(new MenuPG(jg));
}