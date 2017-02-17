#pragma once
#include "Error.h"

class texturasError: public Error
{
public:
	texturasError(std::string const & m) : Error(m){};
	//texturasError();
	~texturasError();
};

