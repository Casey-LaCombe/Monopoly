#include "User.h"

User::User(char symbol, int startingAmount)
	: symbol{ symbol }, money{ startingAmount } {}

bool User::getChanceGetOutOfJail() const
{
	return chanceGetOutOfJail;
}

bool User::getChestGetOutOfJail() const
{
	return chestGetOutOfJail;
}

bool User::getBankrupt() const
{
	return bankrupt;
}

int User::getMoney() const
{
	return money;
}

int User::getSymbol() const
{
	return symbol;
}

bool User::getLost() const
{
	return this->lost;
}

bool User::getInJail() const
{
	return this->inJail;
}

int User::getJailDoubleCounter() const
{
	return this->jailDoubleCounter;
}

bool User::getHasMortgage() const
{
	return this->hasMortgage;
}

void User::incrementJailDoubleCounter()
{
	this->jailDoubleCounter++;
}

void User::setHasMortgage(bool mortgage)
{
	this->hasMortgage = mortgage;
}

void User::resetJailDoubleCounter()
{
	this->jailDoubleCounter = 0;
}

void User::setChanceGetOutOfJail(bool chance)
{
	this->chanceGetOutOfJail = chance;
}

void User::setChestGetOutOfJail(bool chest)
{
	this->chestGetOutOfJail = chest;
}

void User::setMoney(int money)
{
	this->money = money;
}

void User::addMoney(int money)
{
	this->money += money;
}

void User::removeMoney(int money)
{
	this->money -= money;
}

void User::setSymbol(char symbol)
{
	this->symbol = symbol;
}

void User::setBankrupt(bool bankrupt)
{
	this->bankrupt = bankrupt;
}

void User::setLost(bool lost)
{
	this->lost = lost;
}

void User::setInJail(bool inJail)
{
	this->inJail = inJail;
}
