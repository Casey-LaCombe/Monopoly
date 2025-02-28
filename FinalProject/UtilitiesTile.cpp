#include "UtilitiesTile.h"

#include <ctime>
#include <iostream>

using namespace std;

UtilitiesTile::UtilitiesTile(string name, string type, string utilType) 
	:utilType{utilType}
{
	this->setName(name);
	this->setType(type);
}

int UtilitiesTile::getRent()
{
	int rent;

	srand(static_cast<unsigned int>(time(0)));

	int diceRoll = (rand() % 12);

	if (this->getSameOwner())
	{
		rent = (10 * diceRoll);
	}
	else
	{
		rent = (4 * diceRoll);
	}

	return rent;
}

int UtilitiesTile::getBuyValue() const
{
	return this->buyValue;
}

int UtilitiesTile::getMortgageValue() const
{
	return this->mortgageValue;
}

bool UtilitiesTile::getSameOwner() const
{
	return this->sameOwner;
}

char UtilitiesTile::getOwnerChar() const
{
	return this->ownerChar;
}

string UtilitiesTile::getUtilType() const
{
	return this->utilType;
}

bool UtilitiesTile::getMortgage() const
{
	return this->mortgage;
}

void UtilitiesTile::setSameOwner(bool sameOwnerTF)
{
	this->sameOwner = sameOwnerTF;
}

void UtilitiesTile::setOwnerChar(char owner)
{
	this->ownerChar = owner;
}

void UtilitiesTile::setMortgage(bool mortgage)
{
	this->mortgage = mortgage;
}

string UtilitiesTile::printTileSpace()
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

