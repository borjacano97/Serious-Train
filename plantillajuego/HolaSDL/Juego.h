#pragma once
#include "texturas.h"

#include <SDL.h>
#include <vector> // para vectores de texturas, objetos, ect.
#include <string>
#include <stack> // posible uso de pila
class Juego 
// la he puesto como �nica clase en may�scula por ser la m�s importante, desde aqu� se llaman a las dem�s ra�ces
{
public:
	Juego();
	~Juego();

	void run(); // m�todo principal (bucle del juego)

	// void initMedia(); // m�todos para cargar y borrar texturas
	//void freeMedia();

private:
	//bool initSDL(); //ventana de render SDL (pantalla)
	//void closeSDL();
};

