#pragma once
#include "Error.h"
#include <string>

class SDLError: public Error
{
public:
	SDLError(std::string const & m) : Error(m){};
	//SDLError();
	~SDLError();
};

