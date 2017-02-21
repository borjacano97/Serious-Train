#pragma once
class raizEstado
{
public:

	raizEstado()
	{
	}

	virtual ~raizEstado()
	{
	}
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void onClick() = 0;

};

