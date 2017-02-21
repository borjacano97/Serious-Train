// M�todo main a ejecutar, s�lo debe llamar a la clase Juego

#include "SDL.h"       //debe incluir SDL y texturas
#include "texturas.h"
#include "Juego.h"
#include "error.h"

#include <iostream> 

int main(int argc, char *argv[])
{
	// Hacer un try-catch en el main para posibles errores en texturas o SDL


	Juego j;
	
	try {
		j.run();
	}
	catch (error & errorSDL) {
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