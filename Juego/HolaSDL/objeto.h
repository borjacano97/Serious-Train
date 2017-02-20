#pragma once
#include "Juego.h" // tiene que incluirse para que pueda heredar de raizObjeto, y para el puntero

class objeto: public raizObjeto 
{
public:
	objeto();
	~objeto();
	// Los métodos de raizObjeto los hereda y no hace falta ponerlos aqui
	// Aún así hay que poner otros métodos aquí

protected: // son protegidas porque las subclases usan estas variables, si no serían privadas

	Juego* juegootp;
	//Juego::Texturas_t Ttextura; // array de texturas (aún no declarado en Juego)
		
};

