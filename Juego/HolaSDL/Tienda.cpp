#include "Tienda.h"
#include "Button.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "ObjetoTienda.h"

Tienda::Tienda(Game* juego) :Estado(juego)
{
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonJ, 300, 400, jugar));
	objetos.emplace_back(new Button(ptsjuego, Game::TBotonS, 800, 400, recolocar));
	objs.emplace_back(new ObjetoTienda(ptsjuego, Game::TVacioBloq, Game::TVagon1,  200, 200, 150 ));

	for (auto i : vagonesNivel) {
		i = Game::Vagon_t::Vacio;
	}
}


void Tienda::draw() {
	for (auto i : objs) {
		i->draw();
	}
	for (auto i : objetos) {
		i->draw();
	}
}


void Tienda::jugar(Game * jg) {
	switch (jg->getNivel())
	{
	case(1) : {
		jg->pushState(new Nivel1(jg)); 
		// hacemos pushState para "salvar" la tienda y no tener que volver a hacer un new tienda
		// ya que perderíamos los datos de los objetos desbloqueados
		break; }
	case(2) : {
		jg->pushState(new Nivel2(jg));
		break; }
	default:
		break;
	}
}

void Tienda::recolocar(Game * jg){
	// no se como vamos a hacer esto xd
}

void Tienda::onClick() {
	bool clickeado = false;

	int i = objetos.size() - 1;
	while (!clickeado && i >= 0)
	{
		if (objetos[i]->onClick())
			clickeado = true;
		i--;
	}
	int j = objs.size() - 1;
	while (!clickeado && j >= 0 /*&& se puede comprar*/)
	{
		if (objs[j]->onClick())
			clickeado = true;
		j--;
	}
}