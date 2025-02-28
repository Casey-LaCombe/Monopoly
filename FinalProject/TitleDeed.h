#pragma once

#include <vector>

//makes a title deed object for the street tiles, holds all the information found on a typical title deed card
class TitleDeed
{
public:
	explicit TitleDeed(std::vector<int>, int = 0, int = 0, int = 0);
	int getHouseCost() const;
	int getHotelCost() const;
	int getMortgageValue() const;
	//int* getRentVector();
	int getRent(int element) const;
	


private:
	const int houseCost;
	const int hotelCost;
	const int mortgageValue;
	std::vector<int> rent;

};

