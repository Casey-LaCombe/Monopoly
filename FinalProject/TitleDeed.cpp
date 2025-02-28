#include "TitleDeed.h"

using namespace std;

TitleDeed::TitleDeed(vector<int> rent, int houseCost, int hotelCost, int mortgageValue)
	: houseCost{ houseCost }, hotelCost{ hotelCost }, mortgageValue{ mortgageValue }
{
	for (int i : rent)
	{
		this->rent.push_back(i);
	}
}

int TitleDeed::getHouseCost() const
{
	return this->houseCost;
}

int TitleDeed::getHotelCost() const
{
	return this->hotelCost;
}

int TitleDeed::getMortgageValue() const
{
	return this->mortgageValue;
}

//int* TitleDeed::getRentVector() 
//{
//	int* arrayPtr = rent;
//	return arrayPtr;
//}

int TitleDeed::getRent(int element) const
{
	return rent[element];
}
