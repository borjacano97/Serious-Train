
#include "SDL.h" 
#include "JuegoPG.h"
#include "ObjetoJuego.h"
#include "texturasSDL.h"
#include "SDLError.h"
#include "texturasError.h"
#include <iostream>  

int main(int argc, char *argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);// para mostrar la basura 
	JuegoPG juego;
	//mostramos una ventana para empezar el juego y llamamos al metodo run
	//SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "PLAY GAME", "Ready ? ", nullptr);
	try{
		juego.run();
	}
	catch (SDLError & errorSDL){
		char const *eMens = errorSDL.mensaje().c_str();
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error SDL", eMens, nullptr);
		juego.freeMedia();
	}
	catch (texturasError & errorT){
		char const *eMens = errorT.mensaje().c_str();
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Error texturas", eMens, nullptr);
	}
	/////catch (...){} otros tipos
	
	return 0;
}
