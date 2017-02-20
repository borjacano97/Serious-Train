#pragma once
#include "texturas.h"

#include <SDL.h>
#include <vector> // para vectores de texturas, objetos, ect.
#include <string>
#include <stack> // posible uso de pila
class Juego 
// la he puesto como única clase en mayúscula por ser la más importante, desde aquí se llaman a las demás raíces
{
public:
	Juego();
	~Juego();

	void run(); // método principal (bucle del juego)

	// void initMedia(); // métodos para cargar y borrar texturas
	//void freeMedia();

private:
	//bool initSDL(); //ventana de render SDL (pantalla)
	//void closeSDL();
};

