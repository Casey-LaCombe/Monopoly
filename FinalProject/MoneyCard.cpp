#include "MoneyCard.h"
#include <iostream>

using namespace std;

MoneyCard::MoneyCard(string type, string description, int value) 
	: moneyValue{ value } 
{
	this->setType(type);
	this->setDescription(description);
}

int MoneyCard::doSomething()
{
	cout << this->getDescription() << endl;
	return this->getMoneyValue();
}

int MoneyCard::getMoneyValue() const
{
	return this->moneyValue;
}
