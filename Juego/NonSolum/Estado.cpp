#include "Estado.h"
#include "Play.h"

Estado::Estado(Game * j) :ptsjuego(j){};


Estado::~Estado()
{
}
void Estado::draw() {
	for (auto i : objetos) {
		if (i != nullptr) {
			i->draw();
		}
	}
}

void Estado::onClick() {
	bool clickeado = false;

	int i = objetos.size() - 1;
	while (!clickeado && i >= 0)
	{
		if (objetos[i]->onClick())
			clickeado = true;
		i--;
	}
	cout << "Estado onClick\n";
}
bool Estado::handle_events(SDL_Event * evento) {
	if (evento->type == SDL_MOUSEBUTTONDOWN && evento->button.state == SDL_BUTTON_LEFT) {
		mx = evento->button.x;
		my = evento->button.y;
		cout << "Click izquierdo, en la posicion: " << mx << ", " << my << endl;
		onClick();
		
	}
	return evento->type != SDL_QUIT;
}