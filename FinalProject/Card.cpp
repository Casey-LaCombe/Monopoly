#include "Card.h"

using namespace std;

int Card::doSomething() 
{
	return 0;
}

void Card::setType(string type)
{
	this->type = type;
}

void Card::setDescription(string description)
{
	this->description = description;
}


std::string Card::getDescription() const
{
	return this->description;
}

std::string Card::getType() const
{
	return this->type;
}
