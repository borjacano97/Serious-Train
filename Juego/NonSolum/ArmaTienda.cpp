#include "ArmaTienda.h"
#include "Tienda.h"



ArmaTienda::ArmaTienda(Game* juego, Tienda* ti, float x, float y, int p, Game::Bala_t tipo, bool est) : ObjetoTienda()
{
	TTF_Init();

	juegootp = juego;
	t = ti;	

	alto = 65;
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
	case Game::Piedra: 

		alto = 60;
		ancho = 80;

		if (t != NULL) {
			pos.y -= 10;
			pos.x += 70;
		}
		

		Ttextura = Game::Texturas_t::TRoca;
		desb = Game::Texturas_t::TRoca;
		tipoArma = "Piedra";

		if (!estatico) desbloquear();

		break;	
	case Game::Pistola: 

		alto = 70; 
		ancho = 100; 
		pos.y += 10;

		Ttextura = Game::Texturas_t::TPistol;  
		desb = Game::Texturas_t::TPistol;
		tipoArma = "Pistola";
		break;

	case Game::Escopeta: Ttextura = Game::Texturas_t::TEscopeta;  desb = Game::Texturas_t::TEscopeta; 
		break;		
	case Game::Metralleta: Ttextura = Game::Texturas_t::TMetralleta;  desb = Game::Texturas_t::TMetralleta;
		break;
	case Game::Sniper: Ttextura = Game::Texturas_t::TSniper;  desb = Game::Texturas_t::TSniper;
		break;
	case Game::Minigun: if (estatico) pos.y += 20; Ttextura = Game::Texturas_t::TMinigun;  desb = Game::Texturas_t::TMinigun; tipoArma = "Minigun";
		break;
	default:
		break;
	}
	if (estatico) Ttextura = desb;

}
bool ArmaTienda::onClick() {
	juegootp->getMousePos(mpbx, mpby);

	if (dentro(mpbx, mpby)) {
		if (!bloqueado && !usado) {
			t->elegirArma(tip);
		}
		return true;
	}

	else return false;
}


void ArmaTienda::draw() {



	switch (tip)
	{
	case Game::Escopeta:
		if (juegootp->spanish) tipoArma = "Escopeta";
		else tipoArma = "Shotgun";
		break;
	case Game::Pistola:
		if (juegootp->spanish) tipoArma = "Pistola";
		else tipoArma = "Revolver";
		break;
	case Game::Sniper:
		if (juegootp->spanish) tipoArma = "Francotirador";
		else tipoArma = "Sniper";
		break;
	case Game::Metralleta:
		if (juegootp->spanish) tipoArma = "Metralleta";
		else tipoArma = "Assault - Rifle";
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
		if (tip == Game::Bala_t::Pistola)puntosText->draw(juegootp->pRender, nullptr, &puntosText->myFont.setRect(40, 70, this->pos.x + 15, this->pos.y + 75));
		else puntosText->draw(juegootp->pRender, nullptr, &puntosText->myFont.setRect(40, 70, this->pos.x + 15, this->pos.y + 85));
		puntosText->loadFromText(juegootp->pRender, "$" + std::to_string(precio), fontColor);
		if (tip==Game::Bala_t::Pistola) tipoText->draw(juegootp->pRender, nullptr, &puntosText->myFont.setRect(50, 110, this->pos.x - 13, this->pos.y - 35));
		else tipoText->draw(juegootp->pRender, nullptr, &puntosText->myFont.setRect(50, 110, this->pos.x - 13, this->pos.y - 25));
		tipoText->loadFromText(juegootp->pRender, tipoArma, tipoTextColor);
	}
	else if (!bloqueado) {
		if (tip == Game::Bala_t::Pistola) tipoText->draw(juegootp->pRender, nullptr, &puntosText->myFont.setRect(50, 110, this->pos.x - 13, this->pos.y - 35));
		else tipoText->draw(juegootp->pRender, nullptr, &puntosText->myFont.setRect(50, 110, this->pos.x - 13, this->pos.y - 25));
		tipoText->loadFromText(juegootp->pRender, tipoArma, tipoTextColor);
	}
	else  {
		puntosText->draw(juegootp->pRender, nullptr, &puntosText->myFont.setRect(50, 45, mpbx, mpby));
		puntosText->loadFromText(juegootp->pRender, " ", fontColor);
		tipoText->draw(juegootp->pRender, nullptr, &puntosText->myFont.setRect(50, 120, 850, 190));
		if (t != NULL) {
			if (juegootp->spanish) tipoText->loadFromText(juegootp->pRender, "Elegida -> ", tipoTextColor);
			else tipoText->loadFromText(juegootp->pRender, "Chosen -> ", tipoTextColor);
		}
			
	}

	if (!bloqueado && !first){
	
		t->elegirArma(tip);
		first = true;
	}

}
