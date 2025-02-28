#include "TaxTile.h"

#include <iostream>

using namespace std;

TaxTile::TaxTile(string name, string type, int taxVal) 
	: taxValue{ taxVal } 
{
	this->setName(name);
	this->setType(type);
}

string TaxTile::printTileSpace()
{
	string output = this->getName() + " tile";

	char* charPtr = getPlayers();

	for (int i = 0; i < 6; i++)
	{
		if (charPtr[i] != '\0')
		{
			output += "\n";
			output += charPtr[i];
		}
	}

	output += "\n$";
	output += this->taxValue;

	return output;
}

int TaxTile::getTaxValue() const
{
	return this->taxValue;
}
