#include "Railroad.h"

#include <iostream>

using namespace std;

Railroad::Railroad(string name, string type, int buy, int mortgage)
	: buyValue{ buy }, mortgaeValue{ mortgage } 
{
	this->setName(name);
	this->setType(type);
}


void Railroad::setOwner(char owner)
{
	this->ownerChar = owner;
}

void Railroad::setMortgage(bool mortgage)
{
	this->mortgage = mortgage;
}

int Railroad::getBuyValue() const
{
	return this->buyValue;
}

int Railroad::getMortgageValue() const
{
	return this->mortgaeValue;
}

int Railroad::getRentValue(int element) const
{
	return this->rentValue[element];
}

char Railroad::getOwner() const
{
	return this->ownerChar;
}

bool Railroad::getMortgage() const
{
	return this->mortgage;
}

string Railroad::printTileSpace()
{
	string output = this->getName();

	char* charPtr = getPlayers();

	for (int i = 0; i < 6; i++)
	{
		if (charPtr[i] != '\0')
		{
			output += "\n";
			output += charPtr[i];
		}
	}

	if (this->ownerChar == '\n')
	{
		output += "\nUnowned";
	}
	else
	{
		output += "\nOwned by: ";
		output += this->ownerChar;
	}

	output += "\n";
	output += this->buyValue;

	return output;
}
