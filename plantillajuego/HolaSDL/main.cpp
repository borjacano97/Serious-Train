// Método main a ejecutar, sólo debe llamar a la clase Juego

#include "SDL.h"       //debe incluir SDL y texturas
#include "texturas.h"

#include <iostream> 

int main(int argc, char *argv[])
{
	// Hacer un try-catch en el main para posibles errores en texturas o SDL


	/*JuegoPG juego;
	
	try {
		juego.run();
	}
	catch (SDLError & errorSDL) {
		char const *eMens = errorSDL.mensaje().c_str();
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error SDL", eMens, nullptr);
		juego.freeMedia();
	}
	catch (texturasError & errorT) {
		char const *eMens = errorT.mensaje().c_str();
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error texturas", eMens, nullptr);
	}*/

	return 0;
}