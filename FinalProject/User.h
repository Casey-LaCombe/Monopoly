#pragma once

//class for the player, holds infomation about the player and getters/setters for that information
class User
{
public:
	explicit User(char = 'a', int = 1500); //default constructor
	bool getChanceGetOutOfJail() const;
	bool getChestGetOutOfJail() const;
	bool getBankrupt() const;
	int getMoney() const;
	int getSymbol() const;
	bool getLost() const;
	bool getInJail() const;
	int getJailDoubleCounter() const;
	bool getHasMortgage() const;
	void incrementJailDoubleCounter();
	void setHasMortgage(bool);
	void resetJailDoubleCounter();
	void setChanceGetOutOfJail(bool);
	void setChestGetOutOfJail(bool);
	void setMoney(int);
	void addMoney(int);
	void removeMoney(int);
	void setSymbol(char);
	void setBankrupt(bool);
	void setLost(bool);
	void setInJail(bool);

private:
	bool chanceGetOutOfJail{ false };
	bool chestGetOutOfJail{ false };
	bool inJail{ false };
	bool bankrupt{ false };
	bool lost{ false };
	int money;
	char symbol;
	int jailDoubleCounter{ 0 };
	bool hasMortgage{ false };

};

