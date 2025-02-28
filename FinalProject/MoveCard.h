#pragma once

#include "Card.h"

//extends from card, holds a value for the player to move to and some flavor text
class MoveCard : public Card
{
public:
	explicit MoveCard(std::string, std::string, int = 0);
	int doSomething() override;
	int getMoveValue() const;

private:
	const int moveValue;

};

