#include "Tienda.h"
#include "Button.h"

#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"
#include "Nivel4.h"
#include "Nivel5.h"

#include "VagonTienda.h"
#include "ArmaTienda.h"
#include "BotonTienda.h"
#include "Selector.h"
#include "Trigger.h"

Tienda::Tienda(Game* juego) :Estado(juego)
{
	// SELECTOR
	sel = new Selector(ptsjuego, Game::TRect, 20, 170);
	//ARMA ELEGIDA
	armaNivel = Game::Bala_t::Piedra;
	armaActual = new ArmaTienda(ptsjuego, this, 920, 200, 0, Game::Bala_t::Piedra, true);

	// BOTONES PRINCIPALES 
	botones.emplace_back(new BotonTienda(ptsjuego, this, NULL, 1140, 650, Game::Boton_t::Jugar));
	botones.emplace_back(new BotonTienda(ptsjuego, this, NULL, 0, 670, Game::Boton_t::Recolocar));
	botones.emplace_back(new BotonTienda(ptsjuego, this, NULL, 690, 660, Game::Boton_t::Salir));

	//VAGONES PARA COMPRAR Y RESPECTIVOS BOTONES
	vags.emplace_back(new VagonTienda(ptsjuego, this, 200, 200, 50, Game::Vagon_t::Automatico, false));
	botones.emplace_back(new BotonTienda(ptsjuego, this, vags[0], 200, 340, Game::Boton_t::Comprar));

	vags.emplace_back(new VagonTienda(ptsjuego, this, 400, 200, 150, Game::Vagon_t::Lanzallamas, false));
	botones.emplace_back(new BotonTienda(ptsjuego, this, vags[1], 400, 340, Game::Boton_t::Comprar));

	vags.emplace_back(new VagonTienda(ptsjuego, this, 600, 200, 200, Game::Vagon_t::Escudo, false));
	botones.emplace_back(new BotonTienda(ptsjuego, this, vags[2], 600, 340, Game::Boton_t::Comprar));

	vags.emplace_back(new VagonTienda(ptsjuego, this, 200, 500, 300, Game::Vagon_t::Laser, false));
	botones.emplace_back(new BotonTienda(ptsjuego, this, vags[3], 200, 640, Game::Boton_t::Comprar));

	//ARMAS PARA COMPRAR Y RESPECTIVOS BOTONES

	armas.emplace_back(new ArmaTienda(ptsjuego, this, 830, 300, 100, Game::Bala_t::Pistola, false));
	botones.emplace_back(new BotonTienda(ptsjuego, this, armas[0], 830, 430, Game::Boton_t::Comprar));

	armas.emplace_back(new ArmaTienda(ptsjuego, this, 965, 300, 100, Game::Bala_t::Escopeta, false));
	botones.emplace_back(new BotonTienda(ptsjuego, this, armas[1], 965, 430, Game::Boton_t::Comprar));

	armas.emplace_back(new ArmaTienda(ptsjuego, this, 1090, 300, 200, Game::Bala_t::Sniper, false));
	botones.emplace_back(new BotonTienda(ptsjuego, this, armas[2], 1090, 430, Game::Boton_t::Comprar));

	armas.emplace_back(new ArmaTienda(ptsjuego, this, 830, 500, 300, Game::Bala_t::Metralleta, false));
	botones.emplace_back(new BotonTienda(ptsjuego, this, armas[3], 830, 630, Game::Boton_t::Comprar));

	armas.emplace_back(new ArmaTienda(ptsjuego, this, 965, 500, 500, Game::Bala_t::Minigun, false));
	botones.emplace_back(new BotonTienda(ptsjuego, this, armas[4], 965, 630, Game::Boton_t::Comprar));

	//VAGONES DEL NIVEL, EMPIEZAN VACIOS
	for (int i = 0; i < 4; i++) {
		vagonesNivel.emplace_back(Game::Vagon_t::Vacio);
	}
	//TRIGGERS PARA DETECTAR VAG�N SELECCIONADO
	for (int i = 0; i < 4; i++) {
		tgs.emplace_back(new Trigger(ptsjuego, this, 30 , i * 130 + 170));
	}
	initLibraries();

	font = new Texturas(/*100, 80, 50, 50*/);
	font->loadFuente("../fonts/fuenteNumbers.ttf", 200);

	fontColor.r = 218;
	fontColor.g = 165;
	fontColor.b = 32;
	

	s = new Sound;
	//s1 = new Sound;
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
		if (!i->getDest())	i->draw();
	}
	if (ptsjuego->spanish) font->loadFromText(ptsjuego->pRender, "Tienda", fontColor);
	else font->loadFromText(ptsjuego->pRender, "Shop", fontColor);
	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(90, 180, 90, 30));

	if (ptsjuego->spanish) font->loadFromText(ptsjuego->pRender, "Vagones", fontColor);
	else  font->loadFromText(ptsjuego->pRender, "Carriages", fontColor);
	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(70, 160, 480, 55));

	if (ptsjuego->spanish) font->loadFromText(ptsjuego->pRender, "Armas", fontColor);
	else font->loadFromText(ptsjuego->pRender, "Weapons", fontColor);
	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(70, 160, 820, 55));

	font->loadFromText(ptsjuego->pRender, std::to_string(ptsjuego->coins), fontColor);
	font->draw(ptsjuego->pRender, nullptr, &font->myFont.setRect(45, 45, 1100, 30));

	sel->draw();
	armaActual->draw();

}

bool Tienda::initLibraries() {

	TTF_Init();

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}
	return true;
}



void Tienda::jugar(Game * jg) {
	// hacemos pushState para "salvar" la tienda y no tener que volver a hacer un new tienda
	// ya que perder�amos los datos de los objetos desbloqueados
	
	switch (jg->getNivel())
	{		
	case(1) : {		
		jg->pushState(new Nivel1(jg, vagonesNivel, armaNivel));	
		s->stopMusic();
		//jg->sound->playEffect("../sounds/trainEffect.mp3", 300, 17);
		//s1->playEffect("../sounds/trainEffect.mp3", 300, 17);
		//jg->sound->playEffect("../sounds/trainEffect.mp3", 300, 17);
		jg->sound->playMusic("../sounds/nivelpos.mp3", 1, 17);
		break; }
	case(2) : {
		jg->pushState(new Nivel2(jg, vagonesNivel, armaNivel));
		s->stopMusic();
		//s2->playMusic("../sounds/inGameMusic2.mp3", 1, 20);
		jg->sound->playMusic("../sounds/level3Music.mp3", 1, 17);
		break; }
	case(3) : {
		jg->pushState(new Nivel3(jg, vagonesNivel, armaNivel));
		s->stopMusic();
		s3->playMusic("../sounds/inGameMusic2.mp3", 3, 17);
		break; }
	case(4) : {
		jg->pushState(new Nivel4(jg, vagonesNivel, armaNivel));
		s->stopMusic();
		s4->playMusic("../sounds/level4.mp3", 3, 17);
		break; }
	case(5): {
		jg->pushState(new Nivel5(jg, vagonesNivel, armaNivel));
		s->stopMusic();
		s4->playMusic("../sounds/level3Music.mp3", 3, 20);
		break; }
	default:
		break;
	}
	suena = false;
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
	 //armaNivel = Game::Bala_t::Piedra;
	 //armaActual = new ArmaTienda(ptsjuego, this, 920, 200, 0, Game::Bala_t::Piedra, true);
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
	int h = tgs.size() - 1;
	while (!clickeado && h >= 0)
	{
		if (tgs[h]->onClick())
			clickeado = true;
		h--;
	}
}

void Tienda::select(int n) {
	seleccionado = n - 1;
	sel->update(n);
}
void Tienda::colocarVagon(Game::Vagon_t v){ 
	switch (vagonesNivel[seleccionado])
	{
	case Game::Vagon_t::Automatico: vags[0]->rehacer();
		break;
	case Game::Vagon_t::Lanzallamas: vags[1]->rehacer();
		break;
	case Game::Vagon_t::Escudo: vags[2]->rehacer();
		break;
	case Game::Vagon_t::Laser: vags[3]->rehacer();
		break;

	default:
		break;
	}
	
	vagonesNivel[seleccionado] = v; 
	vagsIzq.emplace_back(new VagonTienda(ptsjuego, this, 30, seleccionado*130 + 170, 100, v, true));
}
void Tienda::elegirArma(Game::Bala_t a) {
	armaNivel = a;
	armaActual = new ArmaTienda(ptsjuego, this, 1000, 170, 100, a, true);
}
void Tienda::update(Uint32 d){ 
	if (!suena)	{
		s->playMusic("../sounds/menuMusic1.mp3", 2, 20);
		suena = true;
	}
}