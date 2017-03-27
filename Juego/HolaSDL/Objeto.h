#ifndef H_OBJETO_H
#define H_OBJETO_H

#include "Game.h" // tiene que incluirse para que pueda heredar de raizObjeto, y para el puntero

class Objeto: public RaizObjeto 
{
public:
	Objeto();
	~Objeto();
	// Los métodos de raizObjeto los hereda y no hace falta ponerlos aqui
	// Aún así hay que poner otros métodos aquí
	void draw();
	bool onClick() { return true; }
	void move(char c){}
	int getx() { return pimgx; }
	int gety() { return pimgy; }
	virtual Direccion getDir() { return dir; };
	bool getDest() { return destruido; }
	void destroy() { destruido = true; }
	bool collision(RaizObjeto* other);
	int getPoints() { return 0; }
	
	bool dentro(int x, int y) const;
protected: // son protegidas porque las subclases usan estas variables, si no serían privadas
	SDL_Rect rect;
	Game* juegootp;
	Game::Texturas_t Ttextura; // array de texturas (aún no declarado en Juego)

	Direccion dir;
	bool destruido = false;
	int alto, ancho; // tamaño del objeto
	
	int pimgx, pimgy; //posición del objeto
};


#endif