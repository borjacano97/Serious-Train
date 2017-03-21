#include "Error.h"

Error::Error(std::string mens)
{
	mailinfo = mens;
}


Error::~Error()
{
}

const std::string & Error::mensaje() {
	return mailinfo;
}