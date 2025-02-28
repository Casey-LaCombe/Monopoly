#pragma once

#include "Tile.h"
#include "TitleDeed.h"

//extends tile, used to check if a tile is a street, holds information for a street
class Street : public Tile
{
public:
	explicit Street(std::string, std::string, std::string, TitleDeed&, int = 0);
	int getBuyValue() const;
	int getNumHouses() const;
	bool getHotel() const;
	bool getMortgage() const;
	TitleDeed* getTitleDeedPtr() const;
	char getOwnerChar() const;
	std::string getColor() const;
	void setNumHouses(int);
	void incrementNumHouses();
	void setHotel(bool);
	void setMortgage(bool);
	void setOwnerChar(char);
	std::string printTileSpace() override;

private:
	const int buyValue;
	std::string color;
	int numHouses = 0;
	bool hotel{ false };
	bool mortgage{ false };
	TitleDeed *titleDeedPtr;
	char ownerChar{ ' ' };

};

