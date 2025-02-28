#include "SpecialCard.h"
#include <iostream>

using namespace std;

SpecialCard::SpecialCard(string type, string description, int specialCardType) 
	:specialCardType{specialCardType}
{
	this->setType(type);
	this->setDescription(description);
}

int SpecialCard::doSomething()
{
	cout << this->getDescription() << endl;
	return this->specialCardType;
}
