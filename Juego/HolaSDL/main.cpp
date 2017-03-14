// Método main a ejecutar, sólo debe llamar a la clase Juego

#include "SDL.h"       //debe incluir SDL y texturas
#include "Texturas.h"
#include "Game.h"
#include "Error.h"

#include <iostream> 


int main(int argc, char *argv[])
{
	// Hacer un try-catch en el main para posibles errores en texturas o SDL


	Game j;
	
	try {
		j.run();
	}
	catch (Error & errorSDL) {
		char const *eMens = errorSDL.mensaje().c_str();
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error SDL", eMens, nullptr);
		//j.freeMedia();
	}
	/*catch (texturasError & errorT) {
		char const *eMens = errorT.mensaje().c_str();
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error texturas", eMens, nullptr);
	}*/

	return 0;
}