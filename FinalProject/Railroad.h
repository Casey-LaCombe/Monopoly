#pragma once

#include "Tile.h"

//extends tile, used to check if a tile is a railroad, holds information for a railroad
class Railroad : public Tile
{
public:
	explicit Railroad(std::string, std::string, int = 200, int = 100);
	void setOwner(char);
	void setMortgage(bool);
	int getBuyValue() const;
	int getMortgageValue() const;
	int getRentValue(int) const;
	char getOwner() const;
	bool getMortgage() const;
	std::string printTileSpace() override;

private:
	const int buyValue;
	const int mortgaeValue;
	bool mortgage{ false };
	const int rentValue[4]{25, 50, 100, 200};
	char ownerChar{ ' ' };

};

