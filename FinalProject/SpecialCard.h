#pragma once

#include "Card.h"
#include <string>

//extends from card, holds some flavor text and an int for validation if the card is drawn
class SpecialCard : public Card
{
public:
	explicit SpecialCard(std::string, std::string, int);
	int doSomething() override;

private:
	int specialCardType;

};

