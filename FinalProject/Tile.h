#pragma once

#include <string>

//parent class for all board tiles, holds some universal information and getters and setters for that information
class Tile
{
public:
	virtual std::string printTileSpace();
	void setName(std::string name);
	void setType(std::string type);
	std::string getName() const;
	std::string getType() const;
	char* getPlayers();
	bool containsPlayerChar(char) const;
	void addPlayerChar(char);
	void removePlayerChar(char);

private:
	std::string name;
	std::string type;
	char players[6] = {' ', ' ', ' ', ' ', ' ', ' '};

};

