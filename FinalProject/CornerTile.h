#pragma once

#include "Tile.h"

//extends tile, used to check if a tile is one of the corner tiles, holds information for a corner tile
class CornerTile : public Tile
{
public:
	explicit CornerTile(std::string, std::string);
};

