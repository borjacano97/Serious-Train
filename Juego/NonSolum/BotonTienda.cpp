#include "BotonTienda.h"
#include "Tienda.h"


BotonTienda::BotonTienda(Game* juego, Tienda*ti, ObjetoTienda*obj,  float x, float y, Game::Boton_t tipo)
{
	TTF_Init();

	juegootp = juego;
	t = ti;
	o = obj;
	
	if (tipo == Game::Boton_t::Comprar) {
		alto = 40;
		ancho = 90;
		Ttextura = Game::Texturas_t::TBotonPosible;
	}
	else if (tipo == Game::Boton_t::Salir) {

		alto = 60;
		ancho = 140;
		Ttextura = Game::Texturas_t::TBotonR;
	}
	else if (tipo == Game::Boton_t::Recolocar) {

		alto = 60;
		ancho = 140;
		Ttextura = Game::Texturas_t::TBotonR;
	}
	else if (tipo == Game::Boton_t::Jugar) {

		alto = 60;
		ancho = 140;
		Ttextura = Game::Texturas_t::TBotonV;
	}
	
	

	pos.set(x, y);
	tip = tipo;

	destruido = false;

	texto = new Texturas();
	texto->loadFuente("../fonts/fuenteNumbers.ttf", 250);

	fontColor.r = 218;
	fontColor.g = 218;
	fontColor.b = 218;
}

bool BotonTienda::onClick() {
	juegootp->getMousePos(mpbx, mpby);


	if (dentro(mpbx, mpby)) {

		juegootp->sound->playEffect("../sounds/buttonSound.mp3", 0, 20, 2);
		switch (tip)
		{
		case Game::Comprar:
			if (o->getBloq() && o->getPrecio() <= juegootp->coins) {
				t->comprar(o);
				destruido = true;
			}
			break;
		case Game::Jugar:
			t->jugar(juegootp);
			break;
		case Game::Recolocar:
			t->recolocar(juegootp);
			break;
		case Game::Salir:
			t->salir(juegootp);
			break;
		default:
			break;
		}			
		return true;
	}
	else return false;
}

void BotonTienda::draw() {
	switch (tip)
	{
	case Game::Jugar:
		if (juegootp->spanish)	textB = "Jugar";
		else textB = "Play";
		break;
	case Game::Salir:
		if (juegootp->spanish) textB = "Salir";
		else textB = "Exit";
		break;
	case Game::Comprar:
		if (juegootp->spanish)	textB = "Comprar";
		else textB = "Buy";
		break;
	case Game::Recolocar:
		if (juegootp->spanish)	textB = "Recolocar";
		else textB = "Relocate";
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
	if (tip == Game::Boton_t::Comprar)
		texto->draw(juegootp->pRender, nullptr, &texto->myFont.setRect(30, 70, this->pos.x + 10, this->pos.y + 5));
	else if (tip==Game::Boton_t::Recolocar)
		texto->draw(juegootp->pRender, nullptr, &texto->myFont.setRect(30, 90, this->pos.x + 40, this->pos.y + 15));
	else texto->draw(juegootp->pRender, nullptr, &texto->myFont.setRect(30, 70, this->pos.x + 50, this->pos.y + 15));
	texto->loadFromText(juegootp->pRender, textB, fontColor);
}
