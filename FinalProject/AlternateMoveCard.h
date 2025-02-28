#pragma once

#include "Card.h"

//extends from card, holds a value for the player to move by and some flavor text
class AlternateMoveCard : public Card
{
public:
	explicit AlternateMoveCard(std::string, std::string, int = 0);
	int doSomething() override;
	int getMoveValue() const;

private:
	const int moveValue;

};