#include "Tile.h"

#include <string>

using namespace std;

string Tile::printTileSpace()
{
	return "";
}

void Tile::setName(string name)
{
	this->name = name;
}

void Tile::setType(string type)
{
	this->type = type;
}

string Tile::getName() const
{
	return this->name;
}

string Tile::getType() const
{
	return this->type;
}

char* Tile::getPlayers() 
{
	char* charPtr = &players[0];
	return charPtr;
}

bool Tile::containsPlayerChar(char player) const
{
	for (char c : players)
	{
		if (c == player)
		{
			return true;
		}
	}
	return false;
}

void Tile::addPlayerChar(char playerChar)
{
	for (int i = 0; i < 6; i++)
	{
		if (players[i] == ' ')
		{
			players[i] = playerChar;
			break;
		}
	}
}

void Tile::removePlayerChar(char playerChar)
{
	for (int i = 0; i < 6; i++)
	{
		if (players[i] == playerChar)
		{
			players[i] = ' ';
		}
	}
}
