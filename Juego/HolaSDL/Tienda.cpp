#include "Tienda.h"
#include "Button.h"
#include "Nivel1.h"
#include "Nivel2.h"


Tienda::Tienda(Game* juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonJ, 300, 400, jugar));
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonS, 800, 400, recolocar));
}
void Tienda::jugar(Game * jg) {
	switch (jg->getNivel())
	{
	case(1) : {
		jg->changeState(new Nivel1(jg));
		break; }
	case(2) : {
		jg->changeState(new Nivel2(jg));
		break; }
	default:
		break;
	}
}

void Tienda::recolocar(Game * jg){
	jg->changeState(new Tienda(jg));
}