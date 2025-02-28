#include "CardTile.h"

#include <ctime>
#include <iostream>

using namespace std;

CardTile::CardTile(string name, string type, bool tile)
	: chanceTile{ tile }
{
	this->setName(name);
	this->setType(type);
}

Card* CardTile::drawCard(vector<Card*> cards)
{
	Card* card;

	srand(static_cast<unsigned int>(time(0)));

	int randCard;

	if (chanceTile)
	{
		randCard = (rand() % 14);

		card = cards[randCard];
	}
	else
	{
		randCard = (rand() % 17);

		card = cards[randCard];
	}

	return card;
}

string CardTile::printTileSpace()
{
	string output;

	if (this->chanceTile)
	{
		output = "Chance";
	}
	else
	{
		output = "Community Chest";
	}

	char* charPtr = getPlayers();

	for (int i = 0; i < 6; i++)
	{
		if (charPtr[i] != '\0')
		{
			output += "\n";
			output += charPtr[i];
		}
	}

	return output;
}
