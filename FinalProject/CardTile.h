#pragma once

#include "Tile.h"
#include "Card.h"

#include <vector>

//extends tile, used for checking if a tile is a chance or community chest tile
class CardTile : public Tile
{
public:
	explicit CardTile(std::string, std::string, bool);
	Card* drawCard(std::vector<Card*>);
	std::string printTileSpace() override;

private:
	bool chanceTile;
};

