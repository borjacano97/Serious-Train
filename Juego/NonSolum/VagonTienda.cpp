#include "VagonTienda.h"
#include "Tienda.h"



VagonTienda::VagonTienda(Game* juego, Tienda* ti, float x, float y, int p, Game::Vagon_t tipo, bool est) : ObjetoTienda()
{
	TTF_Init();

	juegootp = juego;
	t = ti;

	Ttextura = Game::Texturas_t::TVacioBloq;

	alto = 130;
	ancho = 95;
	precio = p;

	pos.set(x, y);

	tip = tipo;


	puntosText = new Texturas();
	puntosText->loadFuente("../fonts/fuenteNumbers.ttf", 250);

	tipoText = new Texturas();
	tipoText->loadFuente("../fonts/AlexBrush-Regular.ttf", 200);

	fontColor.r = 218;
	fontColor.g = 165;
	fontColor.b = 32;

	tipoTextColor.r = 218;
	tipoTextColor.g = 165;
	tipoTextColor.b = 32;



	estatico = est;
	switch (tipo)
	{
	case Game::Automatico: desb = Game::Texturas_t::TVagonAuto; 
		break;
	case Game::Laser: desb = Game::Texturas_t::TVagonLaser; 
		break;
	case Game::Lanzallamas: desb = Game::Texturas_t::TVagonFuego; 
		break;
	case Game::Escudo: desb = Game::Texturas_t::TVagon1; 
		break;
	default:
		break;
	}
	if (estatico) Ttextura = desb;

}
bool VagonTienda::onClick() {
	juegootp->getMousePos(mpbx, mpby);

	if (dentro(mpbx, mpby)) {
		if (!bloqueado && !usado) {
			usado = true;
			t->colocarVagon(tip);

		}
		return true;
	}

	else return false;
}


void VagonTienda::draw() {
	switch (tip)
	{
	case Game::Automatico:
		if (juegootp->spanish) tipoVagon = "Automático";
		else tipoVagon = "Automatic";
		break;
	case Game::Laser:
		if (juegootp->spanish) tipoVagon = "Láser";
		else tipoVagon = "Laser";
		break;
	case Game::Lanzallamas:
		if (juegootp->spanish) tipoVagon = "Lanzallamas";
		else tipoVagon = "Flamethrower";
		break;
	case Game::Escudo:
		if (juegootp->spanish) tipoVagon = "Escudo";
		else tipoVagon = "Shield";
		break;
	default:
		break;
	}
	rect.h = alto;
	rect.w = ancho;
	rect.x = pos.x;
	rect.y = pos.y;
	SDL_Renderer* render = juegootp->getRender();
	juegootp->getTextura(Ttextura)->draw(render, nullptr, &rect);

	if (bloqueado && !estatico) {
		puntosText->draw(juegootp->pRender, nullptr, &puntosText->myFont.setRect(40, 70, this->pos.x + 15, this->pos.y + 85));
		puntosText->loadFromText(juegootp->pRender, "$" + std::to_string(precio), fontColor);
		tipoText->draw(juegootp->pRender, nullptr, &puntosText->myFont.setRect(50, 120, this->pos.x - 13, this->pos.y - 25));
		tipoText->loadFromText(juegootp->pRender, tipoVagon, tipoTextColor);
	}
	else if (!bloqueado) {
		tipoText->draw(juegootp->pRender, nullptr, &puntosText->myFont.setRect(50, 120, this->pos.x - 13, this->pos.y - 25));
		tipoText->loadFromText(juegootp->pRender, tipoVagon, tipoTextColor);
	}
	else {
		puntosText->draw(juegootp->pRender, nullptr, &puntosText->myFont.setRect(50, 45, mpbx, mpby));
		puntosText->loadFromText(juegootp->pRender, " ", fontColor);
		tipoText->draw(juegootp->pRender, nullptr, &puntosText->myFont.setRect(50, 120, this->pos.x - 13, this->pos.y - 25));
		tipoText->loadFromText(juegootp->pRender, " ", tipoTextColor);
	}

}

