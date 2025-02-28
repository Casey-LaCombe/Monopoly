#pragma once

#include "Tile.h"

//extends tile, used to check if a tile is a tax tile, holds information for a tax tile
class TaxTile : public Tile
{
public:
	explicit TaxTile(std::string, std::string, int = 0);
	std::string printTileSpace() override;
	int getTaxValue() const;

private:
	const int taxValue;
};

