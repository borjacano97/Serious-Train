#ifndef H_GAMEMANAGER_H
#define H_GAMEMANAGER_H

#include "Textura.h"

using namespace std;
class GameManager
{
public:
	GameManager();
	~GameManager();

	enum HUD_t {TTren, TBarra, TBotonJ, TBotonS, TBotonC};
	enum Fondo_t{ FDesierto, FNieve/*...*/ };
	enum Enemigo_t{EBasico, ERapido/*...*/ };
	enum Arma_t{ APistola, AEscopeta, AMetralleta/*...*/ };
	enum Vagon_t{ VBasico /*...*/ };


	Texturas* getTextura(Texturas_t et) const { return texts[et]; }
};
#endif // !H_GAMEMANAGER_H



