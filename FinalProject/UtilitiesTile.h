#pragma once

#include "Tile.h"

//extends tile, used to check if a tile is a utility tile, holds information for a utility tile
class UtilitiesTile : public Tile
{
public:
	explicit UtilitiesTile(std::string, std::string, std::string);
	int getRent();
	int getBuyValue() const;
	int getMortgageValue() const;
	bool getSameOwner() const;
	char getOwnerChar() const;
	std::string getUtilType() const;
	bool getMortgage() const;
	void setSameOwner(bool);
	void setOwnerChar(char);
	void setMortgage(bool);
	std::string printTileSpace() override;

private:
	const int buyValue{ 150 };
	const int mortgageValue{ 75 };
	const std::string utilType;
	bool mortgage{ false };
	bool sameOwner{ false };
	char ownerChar{ ' ' };
};

