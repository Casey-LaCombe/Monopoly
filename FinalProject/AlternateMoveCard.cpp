#include <iostream>

#include "AlternateMoveCard.h"


using namespace std;

AlternateMoveCard::AlternateMoveCard(string type, string description, int value)
	: moveValue{ value }
{
	this->setType(type);
	this->setDescription(description);
}

int AlternateMoveCard::doSomething()
{
	cout << this->getDescription() << endl;
	return this->moveValue;
}

int AlternateMoveCard::getMoveValue() const
{
	return this->moveValue;
}
