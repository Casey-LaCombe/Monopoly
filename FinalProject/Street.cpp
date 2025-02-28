#include "Street.h"

#include <iostream>

using namespace std;

Street::Street(string name, string type, string color, TitleDeed& titleDeed, int buyVal) 
	: buyValue{ buyVal }, titleDeedPtr{&titleDeed}, color{color}
{
	this->setName(name);
	this->setType(type);
}

int Street::getBuyValue() const
{
	return this->buyValue;
}

int Street::getNumHouses() const
{
	return this->numHouses;
}

bool Street::getHotel() const
{
	return this->hotel;
}

bool Street::getMortgage() const
{
	return this->mortgage;
}

TitleDeed* Street::getTitleDeedPtr() const
{
	return this->titleDeedPtr;
}

char Street::getOwnerChar() const
{
	return this->ownerChar;
}

std::string Street::getColor() const
{
	return this->color;
}

void Street::setNumHouses(int numHouse)
{
	this->numHouses = numHouse;
}

void Street::incrementNumHouses()
{
	this->numHouses++;
}

void Street::setHotel(bool hotel)
{
	this->hotel = hotel;
}

void Street::setMortgage(bool mortgage)
{
	this->mortgage = mortgage;
}

void Street::setOwnerChar(char owner)
{
	this->ownerChar = owner;
}

string Street::printTileSpace()
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

	if (mortgage)
	{
		output += "\nMortgaged";
	}
	else if (numHouses > 0)
	{
		output += "\nNumber of houses: ";
		output += this->numHouses;

	}
	else if(hotel)
	{
		output += "\nHas a hotel";

	}

	output += "\n";
	output += this->buyValue;

	return output;

}

