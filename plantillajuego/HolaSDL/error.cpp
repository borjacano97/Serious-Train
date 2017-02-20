#include "error.h"
#include <string>


error::error(std::string mens)
{
	mailinfo = mens;
}


error::~error()
{
}

const std::string & error::mensaje() {
	return mailinfo;
}