#pragma once

#include "Card.h"

//extends from card, holds a value for the player to gain money of and some flavor text
class MoneyCard : public Card
{
public:
	explicit MoneyCard(std::string, std::string, int = 0);
	int doSomething() override;
	int getMoneyValue() const;

private:
	const int moneyValue;

};

