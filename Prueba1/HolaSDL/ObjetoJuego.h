#pragma once
class ObjetoJuego
{
public:

	/*ObjetoJuego()
	{
	}*/

	virtual ~ObjetoJuego()
	{
	}
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual bool onClick() = 0;
};


	