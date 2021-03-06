#ifndef H_PANTALLAINICIO_H
#define H_PANTALLAINICIO_H

#include "Estado.h"
#include "Hud.h"
#include "Sound.h"
class PantallaInicio :
	public Estado
{
public:
	PantallaInicio(Game* juego);
	virtual ~PantallaInicio() {};
	void draw();
	void update(Uint32 delta);
	void onClick() { cont = 7000; }
private:
	Hud* fondo;
	Hud* logo;
	Hud* sangre;
	int cont = 0;
	Sound* iniSound;
	bool initLibraries();
};

#endif