#include "Tienda.h"
#include "Button.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "ObjetoTienda.h"
#include "BotonComprar.h"
#include "Selector.h"

Tienda::Tienda(Game* juego) :Estado(juego)
{

	sel = new Selector(ptsjuego, Game::TRect, 20, 170);
	objetos.emplace_back(new Button(ptsjuego, Game::TBtienda1, 1100, 625, jugar));
	objetos.emplace_back(new Button(ptsjuego, Game::TBtienda2, -25, 625, recolocar));
	objs.emplace_back(new ObjetoTienda(ptsjuego, this, Game::TVacioBloq, Game::TVagon1, 200, 200, 100));

	objetos.emplace_back(new BotonComprar(ptsjuego, this, objs[0], Game::TBotonB, 500, 200));

	for (auto i : vagonesNivel) {
		i = Game::Vagon_t::Vacio;
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

	for (auto i : objs) {
		i->draw();
	}
	for (auto i : objetos) {
		i->draw();
	}
	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(50, 45, 1100, 30));
	font->loadFromText(ptsjuego->pRender, std::to_string(ptsjuego->coins), fontColor);
	sel->draw();
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
	while (!clickeado && j >= 0 )
	{
		if (objs[j]->onClick())
			clickeado = true;
		j--;
	}
}
/*void Tienda::update(Uint32 n) {
	std::cout << n;
	sel->update(n);
}*/