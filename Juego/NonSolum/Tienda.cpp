#include "Tienda.h"
#include "Button.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"
#include "Nivel4.h"
#include "VagonTienda.h"
#include "ArmaTienda.h"
#include "BotonTienda.h"
#include "Selector.h"

Tienda::Tienda(Game* juego) :Estado(juego)
{
	// SELECTOR
	sel = new Selector(ptsjuego, Game::TRect, 20, 170);
	//ARMA ELEGIDA
	armaNivel = Game::Bala_t::Piedra;
	armaActual = new ArmaTienda(ptsjuego, this, 1000, 170, 100, Game::Bala_t::Piedra, true);

	// BOTONES PRINCIPALES 
	botones.emplace_back(new BotonTienda(ptsjuego, this, NULL, Game::TBtienda1, 1130, 650, Game::Boton_t::Jugar));
	botones.emplace_back(new BotonTienda(ptsjuego, this, NULL, Game::TBtienda2, -10, 650, Game::Boton_t::Recolocar));

	//VAGONES PARA COMPRAR Y RESPECTIVOS BOTONES
	vags.emplace_back(new VagonTienda(ptsjuego, this, 200, 200, 100, Game::Vagon_t::Automatico, false));

	botones.emplace_back(new BotonTienda(ptsjuego, this, vags[0], Game::TBotonPosible, 170, 340, Game::Boton_t::Comprar));

	//ARMAS PARA COMPRAR Y RESPECTIVOS BOTONES
	armas.emplace_back(new ArmaTienda(ptsjuego, this, 1000, 300, 0, Game::Bala_t::Piedra, false));

	for (int i = 0; i < 4; i++) {
		vagonesNivel.emplace_back(Game::Vagon_t::Vacio);
	}

	TTF_Init();

	font = new Texturas(100, 80, 50, 50);
	font->loadFuente("../fonts/AlexBrush-Regular.ttf", 200);

	//font->setRect(80, 80, 50, 50);

	fontColor.r = 218;
	fontColor.g = 165;
	fontColor.b = 32;
}


void Tienda::draw() {

	for (auto i : vags) {
		i->draw();
	}
	for (auto i : armas) {
		i->draw();
	}
	
	for (auto i : vagsIzq) {
		if (i!=nullptr)	i->draw();
	}
	for (auto i : botones) {
		i->draw();
	}
	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(50, 45, 1100, 30));
	font->loadFromText(ptsjuego->pRender, std::to_string(ptsjuego->coins), fontColor);
	sel->draw();
	armaActual->draw();
}


void Tienda::jugar(Game * jg) {
	// hacemos pushState para "salvar" la tienda y no tener que volver a hacer un new tienda
	// ya que perderíamos los datos de los objetos desbloqueados
	switch (jg->getNivel())
	{
	case(1) : {
		jg->pushState(new Nivel1(jg, vagonesNivel, armaNivel));
		recolocar(jg);
		break; }
	case(2) : {
		jg->pushState(new Nivel2(jg, vagonesNivel, armaNivel));
		recolocar(jg);
		break; }
	case(3) : {
		jg->pushState(new Nivel3(jg, vagonesNivel, armaNivel));
		recolocar(jg);
		break; }
	case(4) : {
		jg->pushState(new Nivel4(jg, vagonesNivel, armaNivel));
		recolocar(jg);
		break; }
	default:
		break;
	}
}

void Tienda::recolocar(Game * jg){
	for (int i = 0; i < 4; i++) vagonesNivel[i] = Game::Vagon_t::Vacio; 
	 seleccionado = 0;
	 sel->update(1);
	 for (auto o: vags) o->rehacer();
	 for (unsigned int i = 0; i < vagsIzq.size(); i++) {
		 delete vagsIzq[i];
		 vagsIzq[i] = nullptr;
	 }
}

void Tienda::onClick() {
	bool clickeado = false;

	int i = botones.size() - 1;
	while (!clickeado && i >= 0)
	{
		if (botones[i]->onClick())
			clickeado = true;
		i--;
	}
	int j = vags.size() - 1;
	while (!clickeado && j >= 0 )
	{
		if (vags[j]->onClick())
			clickeado = true;
		j--;
	}
	int k = armas.size() - 1;
	while (!clickeado && k >= 0)
	{
		if (armas[k]->onClick())
			clickeado = true;
		k--;
	}
}

void Tienda::select(Uint32 n) {
	seleccionado = n - 1;
	sel->update(n);
}
void Tienda::colocarVagon(Game::Vagon_t v){ 
	vagonesNivel[seleccionado] = v; 
	vagsIzq.emplace_back(new VagonTienda(ptsjuego, this, 30, seleccionado*130 + 170, 100, v, true));
}
void Tienda::elegirArma(Game::Bala_t a) {
	armaNivel = a;
	armaActual = new ArmaTienda(ptsjuego, this, 1000, 170, 100, a, true);
}