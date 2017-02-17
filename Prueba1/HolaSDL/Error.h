#pragma once
#include <string>

class Error
{
public:
	Error(std::string mens);
	virtual ~Error();
	const std::string& mensaje();

protected:
	std::string mailinfo;
};
