#ifndef H_PANTALLAINICIO_H
#define H_PANTALLAINICIO_H

#include "Estado.h"
#include "Hud.h"
class PantallaInicio:
	public Estado
{
public:
	PantallaInicio(Game* juego);
	virtual ~PantallaInicio(){};
	void draw();

private:
	Hud* fondo;
};

#endif

