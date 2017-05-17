#include "Button.h"

using namespace std;

Button::Button(Game* juego,  float x, float y, Game::Boton_t tipo, CallBack_t * cbCons)
{
	TTF_Init();

	juegootp = juego;
	t = tipo;

	pos.set(x, y);

	alto = 90;
	ancho = 200;


	cb = cbCons;

	texto = new Texturas();
	texto->loadFuente("../fonts/fuenteNumbers.ttf", 250);

	fontColor.r = 218;
	fontColor.g = 218;
	fontColor.b = 218;
	switch (t)
	{	
	case Game::Jugar:Ttextura = Game::Texturas_t::TBotonV;
		break;
	case Game::Salir: Ttextura = Game::Texturas_t::TBotonR;
		break;
	case Game::Supervivencia: Ttextura = Game::Texturas_t::TBotonV;
		break;
	case Game::Historia:Ttextura = Game::Texturas_t::TBotonV;
		break;
	case Game::Volver:Ttextura = Game::Texturas_t::TBotonR;
		break;
	case Game::Controles:Ttextura = Game::Texturas_t::TBotonA;
		break;
	case Game::Spanish: 
		textB = "Spanish";
		Ttextura = Game::Texturas_t::TBotonA;
		break;
	case Game::English: 
		textB = "English";
		Ttextura = Game::Texturas_t::TBotonA;
		break;
	default:
		break;
	}
}
bool Button::onClick(){
	// os odio bastante
	int mx, my;
	juegootp->topEstado()->getMousePos(mx, my);//No se actualizan mx y my, siempre devuelven 0
	///////////////CONSOLA DEBUG/////////////////////////////////////////////////////////////////////////////////////
	cout << "Posicion del objeto: " << pos.x << ", " << pos.y << endl;	//Posicion del boton
	cout << "Mouse position: " << mx << ", "<< my << endl;				//Posicion del raton heredada de estado
	cout << "Boton click: ";											//true->click on button, false if not
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	juegootp->sound->playEffect("../sounds/buttonSound.mp3", 0, 100, 2);

	if (dentro(mx, my)){
		cb(juegootp);
		cout << "true\n";
		return true;
	}
	else {
		cout << "false\n";
		return false;	
	}
}
void Button::draw() {
	

	switch (t)
	{
	case Game::Jugar:
		if (juegootp->spanish)	textB = "Continuar";
		else textB = "Continue";
		break;
	case Game::Salir:
		if (juegootp->spanish) textB = "Salir";
		else textB = "Exit";
		break;
	case Game::Supervivencia:
		if (juegootp->spanish) textB = "Supervivencia";
		else textB = "Survival";
		break;
	case Game::Historia:
		if (juegootp->spanish) textB = "Historia";
		else textB = "The Story";
		break;
	case Game::Volver:
		if (juegootp->spanish) textB = "Volver";
		else textB = "Back";
		break;
	case Game::Controles:
		if (juegootp->spanish) textB = "Controles";
		else textB = "Controls";
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
	if (textB == "Supervivencia")h = 120;
	else h = 90;
	texto->draw(juegootp->pRender, nullptr, &texto->myFont.setRect(a, h, this->pos.x + 60, this->pos.y + 24));
	texto->loadFromText(juegootp->pRender, textB , fontColor);
}
