#pragma once

#include <string>

//parent abstract class for cards
class Card
{
public:
	virtual int doSomething(); //abstract method that each of the card types must define
	void setType(std::string);
	void setDescription(std::string);
	std::string getDescription() const;
	std::string getType() const;

private:
	std::string type;
	std::string description;

};

