#include "MoveCard.h"
#include <iostream>

using namespace std;

MoveCard::MoveCard(string type, string description, int value) 
    : moveValue{ value }
{
    this->setType(type);
    this->setDescription(description);
}

int MoveCard::doSomething()
{
    cout << this->getDescription() << endl;
    return getMoveValue();
}

int MoveCard::getMoveValue() const
{
    return this->moveValue;
}
