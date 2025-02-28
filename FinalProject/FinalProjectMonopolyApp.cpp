#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "CornerTile.h"
#include "Railroad.h"
#include "UtilitiesTile.h"
#include "Street.h"
#include "TaxTile.h"
#include "TitleDeed.h"
#include "User.h"
#include "CardTile.h"
#include "MoneyCard.h"
#include "MoveCard.h"
#include "AlternateMoveCard.h"
#include "SpecialCard.h"


using namespace std;

//function prototypes

void checkUtilitiesOwnership(UtilitiesTile* water, UtilitiesTile* electric);
void printMainMenu(User* u, vector<Street*> streets); 
void printOwnedProperties(User* user, vector<Tile*> tiles, vector<int*>& properties);
void mortgageProperty(User* user, Tile* tile); 
void printCheatsMenu();
void giveProperty(User* user, string propertyName, vector<Tile*> tiles);
void giveColorSet(User* user, string color, vector<Street*> streets);
void giveAllProperties(User* user, vector<Tile*> tiles);
void giveMoney(User* user, int money);
void moveToBoardspace(User* user, vector<Tile*> tiles, int tileNumber);
void displayBoard(vector<Tile*> tiles);
void rollDice(User* user, vector<Tile*> tiles, vector<User*> users, vector<Card*> chance, vector<Card*> chest);
void doSomething(User* user, vector<User*> users, vector<Tile*> tiles, vector<Card*> chance, vector<Card*> chest);
int getNumOwnedRailroads(User* user, vector<Tile*> tiles);
bool buyProperty(User* user, Tile* tile);
void auction(vector<User*> users, Tile* tile);
bool checkColorSet(Street* street, vector<Tile*> tiles, User* user);
void buyHouseHotel(Street* street, vector<Tile*> tiles, User* user);
void getOutOfJail(User* user, vector<Tile*> tiles);
void giveHouseHotel(vector<Street*> streets, Street* street, int numHouses, bool hotel);
void printOwnedStreets(User* user, vector<Street*> streets, vector<int*>& properties);
bool hasProperty(User* user, vector<Tile*> tiles);
void sellProperty(User* user, Tile* tile);
void buyBackMortgage(User* user, vector<Tile*> tiles);
void resetProperties(User* user, vector<Tile*>tiles);
void findNumOwnedHouseHotel(User* user, vector<Tile*> tiles, vector<int*>& money, int houseCost, int hotelCost);


int main()
{
	//vector for the board tiles
	vector<Tile*> tiles;
	//vector for the creation of each title deed
	vector<int> titleDeedVector;
	//vector for the street objects
	vector<Street*> streets;
	//vectors for the chance and community chest cards
	vector<Card*> chance;
	vector<Card*> chest;
	
	//creates each title deed
	titleDeedVector = { 2, 4, 10, 30, 90, 160, 250 };
	TitleDeed tdMediterraneanAvenue(titleDeedVector, 50, 50, 30);
	titleDeedVector.clear();

	titleDeedVector = {4, 8, 20, 60, 180, 320, 450};
	TitleDeed tdBalticAvenue(titleDeedVector, 50, 50, 30);
	titleDeedVector.clear();

	titleDeedVector = { 6, 12, 30, 90, 270, 400, 550 };
	TitleDeed tdOrientalAvenue(titleDeedVector, 50, 50, 50);
	titleDeedVector.clear();

	titleDeedVector = { 6, 12, 30, 90, 270, 400, 550 };
	TitleDeed tdVermontAvenue(titleDeedVector, 50, 50, 50);
	titleDeedVector.clear();

	titleDeedVector = { 8, 16, 40, 100, 300, 450, 600 };
	TitleDeed tdConnecticutAvenue(titleDeedVector, 50, 50, 60);
	titleDeedVector.clear();

	titleDeedVector = { 10, 20, 50, 150, 450, 625, 750 };
	TitleDeed tdStCharlesPlace(titleDeedVector, 100, 100, 70);
	titleDeedVector.clear();

	titleDeedVector = { 10, 20, 50, 150, 450, 625, 750 };
	TitleDeed tdStatesAvenue(titleDeedVector, 100, 100, 70);
	titleDeedVector.clear();

	titleDeedVector = { 12, 24, 60, 180, 500, 700, 900 };
	TitleDeed tdVirginiaAvenue(titleDeedVector, 100, 100, 80);
	titleDeedVector.clear();

	titleDeedVector = { 14, 28, 70, 200, 550, 750, 950 };
	TitleDeed tdStJamesPlace(titleDeedVector, 100, 100, 90);
	titleDeedVector.clear();

	titleDeedVector = { 14, 28, 70, 200, 550, 750, 950 };
	TitleDeed tdTennesseeAvenue(titleDeedVector, 100, 100, 90);
	titleDeedVector.clear();

	titleDeedVector = { 16, 32, 80, 220, 600, 800, 1000 };
	TitleDeed tdNewYorkAvenue(titleDeedVector, 100, 100, 100);
	titleDeedVector.clear();

	titleDeedVector = { 18, 36, 90, 250, 700, 875, 1050 };
	TitleDeed tdKentuckyAvenue(titleDeedVector, 150, 150, 110);
	titleDeedVector.clear();

	titleDeedVector = { 18, 36, 90, 250, 700, 875, 1050 };
	TitleDeed tdIndianaAvenue(titleDeedVector, 150, 150, 110);
	titleDeedVector.clear();

	titleDeedVector = { 20, 40, 100, 300, 750, 925, 1100 };
	TitleDeed tdIllinoisAvenue(titleDeedVector, 150, 150, 120);
	titleDeedVector.clear();

	titleDeedVector = { 22, 44, 110, 330, 800, 975, 1150 };
	TitleDeed tdAtlanticAvenue(titleDeedVector, 150, 150, 130);
	titleDeedVector.clear();

	titleDeedVector = { 22, 44, 110, 330, 800, 975, 1150 };
	TitleDeed tdVentnorAvenue(titleDeedVector, 150, 150, 130);
	titleDeedVector.clear();

	titleDeedVector = { 24, 48, 120, 360, 850, 1025, 1200 };
	TitleDeed tdMarvinGardens(titleDeedVector, 150, 150, 140);
	titleDeedVector.clear();

	titleDeedVector = { 26, 52, 130, 390, 900, 1100, 1275 };
	TitleDeed tdPacificAvenue(titleDeedVector, 200, 200, 150);
	titleDeedVector.clear();

	titleDeedVector = { 26, 52, 130, 390, 900, 1100, 1275 };
	TitleDeed tdNorthCarolinaAvenue(titleDeedVector, 200, 200, 150);
	titleDeedVector.clear();

	titleDeedVector = { 28, 56, 150, 450, 1000, 1200, 1400 };
	TitleDeed tdPennsylvaniaAvenue(titleDeedVector, 200, 200, 160);
	titleDeedVector.clear();

	titleDeedVector = { 35, 70, 175, 500, 1100, 1300, 1500 };
	TitleDeed tdParkPLace(titleDeedVector, 200, 200, 175);
	titleDeedVector.clear();

	titleDeedVector = { 50, 100, 200, 600, 1400, 1700, 2000 };
	TitleDeed tdBoardwalk(titleDeedVector, 200, 200, 200);

	//creates the street tiles and adds them to their own vector
	Street *mediterraneanAvenue = new Street("Mediterranean Avenue", "street", "purple", tdMediterraneanAvenue, 60);
	streets.push_back(mediterraneanAvenue);
	Street *balticAvenue = new Street("Baltic Avenue", "street", "purple", tdBalticAvenue, 60);
	streets.push_back(balticAvenue);
	Street *orientalAvenue = new Street("Oriental Avenue", "street", "light blue", tdOrientalAvenue, 100);
	streets.push_back(orientalAvenue);
	Street *vermontAvenue = new Street("Vermont Avenue", "street", "light blue", tdVermontAvenue, 100);
	streets.push_back(vermontAvenue);
	Street *connecticutAvenue = new Street("Connecticut Avenue", "street", "light blue", tdConnecticutAvenue, 120);
	streets.push_back(connecticutAvenue);
	Street *stCharlesPlace = new Street("St. Charles Place", "street", "pink", tdStCharlesPlace, 140);
	streets.push_back(stCharlesPlace);
	Street *statesAvenue = new Street("States Avenue", "street", "pink", tdStatesAvenue, 140);
	streets.push_back(statesAvenue);
	Street *virginiaAvenue = new Street("Virginia Avenue", "street", "pink", tdVirginiaAvenue, 160);
	streets.push_back(virginiaAvenue);
	Street *stJamesPlace = new Street("St James Place", "street", "orange", tdStJamesPlace, 180);
	streets.push_back(stJamesPlace);
	Street *tennesseeAvenue = new Street("Tennessee Avenue", "street", "orange", tdTennesseeAvenue, 180);
	streets.push_back(tennesseeAvenue);
	Street *newYorkAvenue = new Street("New York Avenue", "street", "orange", tdNewYorkAvenue, 200);
	streets.push_back(newYorkAvenue);
	Street *kentuckyAvenue = new Street("Kentucky Avenue", "street", "red", tdKentuckyAvenue, 220);
	streets.push_back(kentuckyAvenue);
	Street *indianaAvenue = new Street("Indiana Avenue", "street", "red", tdIndianaAvenue, 220);
	streets.push_back(indianaAvenue);
	Street *illinoisAvenue = new Street("Illinois Avenue", "street", "red", tdIllinoisAvenue, 240);
	streets.push_back(illinoisAvenue);
	Street *atlanticAvenue = new Street("Atlantic Avenue", "street", "yellow", tdAtlanticAvenue, 260);
	streets.push_back(atlanticAvenue);
	Street *ventnorAvenue = new Street("Ventnor Avenue", "street", "yellow", tdVentnorAvenue, 260);
	streets.push_back(ventnorAvenue);
	Street *marvinGardens = new Street("Marvin Gardens", "street", "yellow", tdMarvinGardens, 280);
	streets.push_back(marvinGardens);
	Street *pacificAvenue = new Street("Pacific Avenue", "street", "green", tdPacificAvenue, 300);
	streets.push_back(pacificAvenue);
	Street *northCarolinaAvenue = new Street("North Carolina Avenue", "street", "green", tdNorthCarolinaAvenue, 300);
	streets.push_back(northCarolinaAvenue);
	Street *pennsylvaniaAvenue = new Street("Pennsylvania Avenue", "street", "green", tdPennsylvaniaAvenue, 320);
	streets.push_back(pennsylvaniaAvenue);
	Street *parkPLace = new Street("Park PLace", "street", "blue", tdParkPLace, 350);
	streets.push_back(parkPLace);
	Street *boardwalk = new Street("Boardwalk", "street", "blue", tdBoardwalk, 400);
	streets.push_back(boardwalk);

	//creates the utilities tiles
	Tile *electric = new UtilitiesTile("Electric Company", "utility", "electric");
	Tile *water = new UtilitiesTile("Water Works", "utility", "water");

	//creates the tax tiles
	TaxTile *incomeTax = new TaxTile("Income Tax", "tax", 200);
	TaxTile *luxuryTax = new TaxTile("Luxury Tax", "tax", 100);

	//creates the railroad tiles
	Railroad *readingRailroad = new Railroad("Reading Railroad", "railroad");
	Railroad *pennsylvaniaRailroad = new Railroad("Pennsylvania Railroad", "railroad");
	Railroad *boRailroad = new Railroad("B & O Railroad", "railroad");
	Railroad *shortLine = new Railroad("Short Line", "railroad");

	//creates the corner tiles
	CornerTile *go = new CornerTile("Go", "corner tile");
	CornerTile *jail = new CornerTile("Jail", "corner tile");
	CornerTile *justVisisting = new CornerTile("Just Visiting", "corner tile");
	CornerTile *freeParking = new CornerTile("Free Parking", "corner tile");
	CornerTile *goToJail = new CornerTile("Go To Jail", "corner tile");

	//creates the chance cards
	MoveCard *chanceCard1 = new MoveCard("move", "Advance to \"Go\"(Collect $200).", 0);
	MoveCard *chanceCard2 = new MoveCard("move", "Advance to Illinois Ave.", 25);
	MoveCard *chanceCard3 = new MoveCard("move", "Advance to St. Charles Place.", 12);
	MoveCard *chanceCard4 = new MoveCard("move", "Advance to Electric Utility.", 13);
	MoveCard *chanceCard5 = new MoveCard("move", "Advance to Water Utility.", 29);
	MoveCard *chanceCard6 = new MoveCard("move", "Advance to Reading Railroad.", 5);
	MoveCard *chanceCard7 = new MoveCard("move", "Advance to Pennsylvania Railroad.", 16);
	MoveCard *chanceCard8 = new MoveCard("move", "Advance to B & O Railroad.", 26);
	MoveCard *chanceCard9 = new MoveCard("move", "Advance to Short Line.", 36);
	MoveCard *chanceCard15 = new MoveCard("move", "Take a walk on the boardwalk.", 40);
	SpecialCard *chanceCard10 = new SpecialCard("special card", "Get Out of Jail Free.", 0);
	SpecialCard *chanceCard13 = new SpecialCard("special card", "Go to Jail.", 1);
	SpecialCard *chanceCard14 = new SpecialCard("special card", "Pay repairs on all your property: $25 for each house and 100 for each hotel.", 2);
	AlternateMoveCard *chanceCard11 = new AlternateMoveCard("alternate move card", "Move back 3 spaces.", -3);
	AlternateMoveCard *chanceCard12 = new AlternateMoveCard("alternate move card", "Move forward 3 spaces.", 3);
	AlternateMoveCard *chanceCard17 = new AlternateMoveCard("alternate move card", "Move back 5 spaces.", -5);
	AlternateMoveCard *chanceCard18 = new AlternateMoveCard("alternate move card", "Move forward 5 spaces.", 5);
	AlternateMoveCard *chanceCard19 = new AlternateMoveCard("alternate move card", "Move back 7 spaces.", -7);
	AlternateMoveCard *chanceCard20 = new AlternateMoveCard("alternate move card", "Move forward 7 spaces.", 7);
	MoneyCard *chanceCard16 = new MoneyCard("money", "Your loan matures. Recieve $150.", 150);
	MoneyCard *chanceCard21 = new MoneyCard("money", "You find $50 on the sidewalk. Score!", 50);

	//adds the chance cards to the vector
	chance.push_back(chanceCard1);
	chance.push_back(chanceCard2);
	chance.push_back(chanceCard3);
	chance.push_back(chanceCard4);
	chance.push_back(chanceCard5);
	chance.push_back(chanceCard6);
	chance.push_back(chanceCard7);
	chance.push_back(chanceCard8);
	chance.push_back(chanceCard9);
	chance.push_back(chanceCard10);
	chance.push_back(chanceCard11);
	chance.push_back(chanceCard12);
	chance.push_back(chanceCard13);
	chance.push_back(chanceCard14);
	chance.push_back(chanceCard15);
	chance.push_back(chanceCard16);
	chance.push_back(chanceCard17);
	chance.push_back(chanceCard18);
	chance.push_back(chanceCard19);
	chance.push_back(chanceCard20);
	chance.push_back(chanceCard21);

	//creates the community chest cards
	MoveCard *chestCard1 = new MoveCard("move", "Advance to \"Go\"(Collect $200).", 0);
	MoveCard *chestCard16 = new MoveCard("move", "Advance to free parking", 21);
	MoveCard *chestCard18 = new MoveCard("move", "Advance to Electric Utility.", 13);
	MoveCard *chestCard19 = new MoveCard("move", "Advance to Water Utility.", 29);
	MoneyCard *chestCard2 = new MoneyCard("money", "Bank error in your favor. Collect $200.", 200);
	MoneyCard *chestCard3 = new MoneyCard("money", "Doctor's fee. Pay $50.", -50);
	MoneyCard *chestCard4 = new MoneyCard("money", "From sale of stock you get $50.", 50);
	MoneyCard *chestCard5 = new MoneyCard("money", "Holiday fund matures. Recieve $100.", 100);
	MoneyCard *chestCard6 = new MoneyCard("money", "Income tax refund. Collect $20.", 20);
	MoneyCard *chestCard7 = new MoneyCard("money", "Life insurance matures. Collect $100.", 100);
	MoneyCard *chestCard8 = new MoneyCard("money", "Hospital fees. Pay $200", -200);
	MoneyCard *chestCard9 = new MoneyCard("money", "School fees. Pay $50.", -50);
	MoneyCard *chestCard11 = new MoneyCard("money", "Recieve $25 consultancy fee.", 25);
	MoneyCard *chestCard14 = new MoneyCard("money", "You won second place in a beauty contest. You recieve $10.", 10);
	MoneyCard *chestCard15 = new MoneyCard("money", "You inherit $100.", 100);
	MoneyCard *chestCard17 = new MoneyCard("money", "You win it big at poker. Collect $200.", 200);
	MoneyCard *chestCard20 = new MoneyCard("money", "You had a bad night at the casino. Lose $200.", -200);
	MoneyCard *chestCard21 = new MoneyCard("money", "Those scratchers payed off. Collect $20.", 20);
	SpecialCard *chestCard10 = new SpecialCard("special card", "Get Out of Jail Free.", 0);
	SpecialCard *chestCard13 = new SpecialCard("special card", "Go to Jail.", 1);
	SpecialCard *chestCard12 = new SpecialCard("special card", "You are assessed for street repairs: pay $40 per house and $115 per hotel.", 2);

	//adds the community chess cards to the vector
	chest.push_back(chestCard1);
	chest.push_back(chestCard2);
	chest.push_back(chestCard3);
	chest.push_back(chestCard4);
	chest.push_back(chestCard5);
	chest.push_back(chestCard6);
	chest.push_back(chestCard7);
	chest.push_back(chestCard8);
	chest.push_back(chestCard9);
	chest.push_back(chestCard10);
	chest.push_back(chestCard11);
	chest.push_back(chestCard12);
	chest.push_back(chestCard13);
	chest.push_back(chestCard14);
	chest.push_back(chestCard15);
	chest.push_back(chestCard16);
	chest.push_back(chestCard17);
	chest.push_back(chestCard18);
	chest.push_back(chestCard19);
	chest.push_back(chestCard20);
	chest.push_back(chestCard21);
	
	//creates the chance and community chest tiles
	CardTile *chanceTile1 = new CardTile("Chance", "chance", true);
	CardTile *chanceTile2 = new CardTile("Chance", "chance", true);
	CardTile *chanceTile3 = new CardTile("Chance", "chance", true);
	CardTile *chestTile1 = new CardTile("Community Chest", "chest", false);
	CardTile *chestTile2 = new CardTile("Community Chest", "chest", false);
	CardTile *chestTile3 = new CardTile("Community Chest", "chest", false);

	//fills the board
	tiles.push_back(go);
	tiles.push_back(mediterraneanAvenue);
	tiles.push_back(chestTile1);
	tiles.push_back(balticAvenue);
	tiles.push_back(incomeTax);
	tiles.push_back(readingRailroad);
	tiles.push_back(orientalAvenue);
	tiles.push_back(chanceTile1);
	tiles.push_back(vermontAvenue);
	tiles.push_back(connecticutAvenue);
	tiles.push_back(justVisisting);
	tiles.push_back(jail);
	tiles.push_back(stCharlesPlace);
	tiles.push_back(electric);
	tiles.push_back(statesAvenue);
	tiles.push_back(virginiaAvenue);
	tiles.push_back(pennsylvaniaRailroad);
	tiles.push_back(stJamesPlace);
	tiles.push_back(chestTile2);
	tiles.push_back(tennesseeAvenue);
	tiles.push_back(newYorkAvenue);
	tiles.push_back(freeParking);
	tiles.push_back(kentuckyAvenue);
	tiles.push_back(chanceTile2);
	tiles.push_back(indianaAvenue);
	tiles.push_back(illinoisAvenue);
	tiles.push_back(boRailroad);
	tiles.push_back(atlanticAvenue);
	tiles.push_back(ventnorAvenue);
	tiles.push_back(water);
	tiles.push_back(marvinGardens);
	tiles.push_back(goToJail);
	tiles.push_back(pacificAvenue);
	tiles.push_back(northCarolinaAvenue);
	tiles.push_back(chestTile3);
	tiles.push_back(pennsylvaniaAvenue);
	tiles.push_back(shortLine);
	tiles.push_back(chanceTile3);
	tiles.push_back(parkPLace);
	tiles.push_back(luxuryTax);
	tiles.push_back(boardwalk);

	//char for replayability
	char playAgain{ 'y' };

	//repeats as long as the player wants to keep playing
	while (playAgain == 'y')
	{
		//int for number of players
		int numPlayers{ 0 };

		//prompts user
		cout << "How many players are playing? (2-6)" << endl;
		cin >> numPlayers;

		//vector for users
		vector<User*> users;

		//initializes the user vector
		for (int i = 1; i <= numPlayers; i++)
		{
			char userChar;
			cout << "Player " << i << " please pick a character: " << endl;
			cin >> userChar;
			User* user = new User(userChar);
			tiles[0]->addPlayerChar(userChar);
			users.push_back(user);
		}

		//bool for the while loop for the game, repeats until their is a victor
		bool win{ false };

		//while loop for the game
		while (win != true)
		{
			//displays the game board
			displayBoard(tiles);
			//for loop for each users turn
			for(User* u : users)
			{
				//checks if the user lost yet
				if(!(*u).getLost())
				{
					//while loop that repeats until a turn is done
					bool pTurn{ true };
					while(pTurn)
					{

						//prints the player symbol and their money
						cout << (char)(*u).getSymbol() << "'s turn." << endl;
						cout << "$" << (*u).getMoney() << endl;

						//if statement checking for bankruptcy and dept, if the player cant pay back their dept they lose
						if (u->getMoney() < 0)
						{
							if (hasProperty(u, tiles))
							{
								while(hasProperty(u, tiles) || u->getMoney() < 0)
								{
									bool validInput{ false };
									vector<int*> properties;
									printOwnedProperties(u, tiles, properties);
									int propertyInt;
									cin >> propertyInt;
									for (int* i : properties)
									{
										if ((*i) == propertyInt)
										{
											validInput = true;
										}
									}
									for (int* i : properties)
									{
										delete i;
									}
									if (validInput)
									{
										sellProperty(u, tiles[propertyInt]);
									}
									else
									{
										cout << "Invalid Input, Try Again." << endl;
									}
									properties.clear();
								}
							}
							else
							{
								u->setBankrupt(true);
								resetProperties(u, tiles);
							}
						}
						//checks if the player lost
						if ((*u).getBankrupt())
						{
							cout << (char)(*u).getSymbol() << " lost." << endl;
							(*u).setLost(true);
							pTurn = false;
						}
						//checks if the player is in jail, gives them options if they are
						if ((*u).getInJail())
						{
							getOutOfJail(u, tiles);
							pTurn = false;
						}
						//main part of the turn, checks if the player lost to bankruptcy or is in jail
						if (!(*u).getInJail() && u->getLost() != true)
						{
							//ints for user input
							int userInput{ 0 };
							int cheatsInput{ 0 };

							//prints the main menu and prompts for user input
							printMainMenu(u, streets);
							cin >> userInput;

							//switch case for user input
							switch (userInput)
							{
							case 1:
								//roll dice and does the corresponding action for the landed on space, sets the turn to end
								rollDice(u, tiles, users, chance, chest);
								pTurn = false;
								break;

							case 2:
								//display cheats
								printCheatsMenu();
								cin >> cheatsInput;
								break;

							case 3:
								//buy house/hotel
							{
								bool validInput{ false };
								while (!validInput)
								{
									vector<int*> properties;
									printOwnedProperties(u, tiles, properties);
									int propertyInt;
									cin >> propertyInt;
									for (int* i : properties)
									{
										if ((*i) == propertyInt)
										{
											validInput = true;
										}
									}
									for (int* i : properties)
									{
										delete i;
									}
									if (validInput)
									{
										buyHouseHotel(dynamic_cast<Street*>(tiles[propertyInt]), tiles, u);
									}
									else
									{
										cout << "Invalid Input, Try Again." << endl;
									}
									properties.clear();
								}
								break;
							}
							case 4:
								//mortgage property
							{
								bool validInput{ false };
								while (!validInput)
								{
									vector<int*> properties;
									printOwnedProperties(u, tiles, properties);
									int propertyInt;
									cin >> propertyInt;
									for (int* i : properties)
									{
										if ((*i) == propertyInt)
										{
											validInput = true;
										}
									}
									for (int* i : properties)
									{
										delete i;
									}
									if (validInput)
									{
										mortgageProperty(u, tiles[propertyInt]);
									}
									else
									{
										cout << "Invalid Input, Try Again." << endl;
									}
									properties.clear();
									cout << (*u).getMoney();
								}
								break;
							}
							case 5:
								//check owned properties
							{
								vector<int*> properties;
								printOwnedProperties(u, tiles, properties);
								for (int* i : properties)
								{
									delete i;
								}
								properties.clear();
								break;
							}

							case 6:
								//buy back mortgage
								buyBackMortgage(u, tiles);
								
								break;

							default:
								cout << "this shouldn't print";
								break;
							}

							if (userInput == 2)
							{
								//switch case for the cheats
								switch (cheatsInput)
								{
								case 1:
								{
									//gives the player a selected property
									string propertyName;
									cout << "Please enter the name of the property you would like: " << endl;
									cin >> propertyName;
									giveProperty(u, propertyName, tiles);
									break;
								}

								case 2:
								{
									//gives the player the selected color street set
									string color;
									int numColor;
									cout << "Please enter the number for the set you would like: \n1)Purple \n2)Light Blue \n3)Pink \n4)Orange \n5)Red \n6)Yellow \n7)Green \n8)Blue " << endl;
									cin >> numColor;

									switch (numColor)
									{
									case 1:
										color = "purple";
										break;
									case 2:
										color = "light blue";
										break;
									case 3:
										color = "pink";
										break;
									case 4:
										color = "orange";
										break;
									case 5:
										color = "orange";
										break;
									case 6:
										color = "red";
										break;
									case 7:
										color = "green";
										break;
									case 8:
										color = "blue";
										break;
									}

									giveColorSet(u, color, streets);
									break;
								}

								case 3:
									//gives the player all properties
									giveAllProperties(u, tiles);
									break;

								case 4:
								{
									//gives the player a house or hotel on any owned property
									//bool and vector used for input validation
									bool validInput{ false };
									vector<int*> properties;
									printOwnedStreets(u, streets, properties);
									int propertyInt;
									cin >> propertyInt;
									//checks if there is any owned property
									if (!properties.empty())
									{
										for (int* i : properties)
										{
											if ((*i) == propertyInt)
											{
												validInput = true;
											}
										}
										for (int* i : properties)
										{
											delete i;
										}
									}
									//prompts the user asking if they want houses or a hotel
									if (validInput)
									{
										int numHouses{ 0 };
										bool hotel{ false };
										char userIn;
										cout << "Would you like a num of houses or a hotel? (n for num houses, h for hotel)" << endl;
										cin >> userIn;

										if (userIn == 'n')
										{
											cout << "How many houses?(1-4)" << endl;
											cin >> numHouses;
										}
										else if (userIn == 'h')
										{
											hotel = true;
										}

										giveHouseHotel(streets, streets[propertyInt], numHouses, hotel);
									}
									else
									{
										cout << "Invalid Input, Try Again." << endl;
									}
									//clears the vector
									properties.clear();
									break;
								}
								case 5:
								{
									//gives the user a sum of money
									int money;
									cout << "How much money would you like? (0 - 50,000)" << endl;
									cin >> money;
									giveMoney(u, money);

									break;
								}

								case 6:
								{
									//allows user to move to any board space and calls corresponding action for that board space
									int tileNum;
									cout << "Please enter the boardspace you'd like to move to: (starting from go = 0 and just visiting = 10, jail = 11)" << endl;
									cin >> tileNum;
									moveToBoardspace(u, tiles, tileNum);
									doSomething(u, users, tiles, chance, chest);
									break;
								}

								case 7:
									//automatic win
									cout << (char)(*u).getSymbol() << " wins!!" << endl;
									win = true;
									users.clear();
									break;

								default:
									cout << "this shouldn't print";
									break;
								}
							}
							
						}
					}
				}

			}
			int lostCount{ 0 };
			for (User* user : users)
			{
				if (user->getLost())
				{
					lostCount++;
				}
			}

			if ((lostCount + 1) == users.size())
			{
				win = true;
			}
			

		}

		for (User* u : users)
		{
			delete u;
		}

		//prompts the user to play again
		cout << "Play Again? (y/n)" << endl;
		cin >> playAgain;
	}


}

//checks if the two utilities are owned by the same person and sets the corresponding stat accordingly
void checkUtilitiesOwnership(UtilitiesTile* water, UtilitiesTile* electric)
{
	if ((*water).getOwnerChar() == (*electric).getOwnerChar())
	{
		(*water).setSameOwner(true);
		(*electric).setSameOwner(true);
	}
}

//prints the main menu, varying depending on what the player possesses
void printMainMenu(User* user, vector<Street*> streets)
{
	string output = "Would you like to: \n1) Roll the dice. \n2)Access cheats. \n";
	
	bool hasProperty{ false };
	for(Street* s : streets)
	{

		if ((*user).getSymbol() == (*s).getOwnerChar())
		{
			hasProperty = true;
		}
	}

	if (hasProperty)
	{
		output += "3)Buy Property. \n4)Mortgage Property. \n5)Check owned properties. \n";
	}

	if (user->getHasMortgage())
	{
		output += "6)Buy back mortgage. ";
	}

	cout << output << endl;
}

//rolls the dice checking for doubles and calls the doSomething method for the landed on space
void rollDice(User* user, vector<Tile*> tiles, vector<User*> users, vector<Card*> chance, vector<Card*> chest)
{
	bool doubles{ true };
	int doublesCounter{ 0 };
	while(doubles)
	{
		cout << (*user).getMoney() << endl;
		srand(static_cast<unsigned int>(time(0)));

		int die1 = (rand() % 6) + 1;
		int die2 = (rand() % 6) + 1;
		int diceRoll = die1 + die2;
		cout << (char)((*user).getSymbol()) << " rolled a " << diceRoll << endl;

		if (die1 == die2)
		{
			doubles = true;
			doublesCounter++;
		}
		else 
		{
			doubles = false;
		}
		
		//if its a double it does the tile action and rolls again
		if(doublesCounter != 3)
		{
			Tile* tile = tiles[0];
			size_t newPos{ 0 };
			for (int i = 0; i < tiles.size(); i++)
			{
				if ((*tiles[i]).containsPlayerChar((*user).getSymbol()))
				{
					tile = tiles[i];
					newPos = i + diceRoll;
					if (i < 11 && newPos >= 11)
					{
						newPos++;
					}
				}
			}

			if (newPos >= tiles.size())
			{
				newPos -= tiles.size();
				(*user).addMoney(200);
			}
			(*tile).removePlayerChar((*user).getSymbol());
			(*tiles[newPos]).addPlayerChar((*user).getSymbol());
			doSomething(user, users, tiles, chance, chest);
		}
		else //places player in jail on a third double in a row
		{
			for (int i = 0; i < tiles.size(); i++)
			{
				if ((*tiles[i]).containsPlayerChar((*user).getSymbol()))
				{
					(*tiles[i]).removePlayerChar((*user).getSymbol());
					(*tiles[11]).addPlayerChar((*user).getSymbol());
					user->setInJail(true);
				}
			}
			doubles = false;
		}
		//displays the board
		displayBoard(tiles);
	}

}

//method controlling what the tile does
void doSomething(User* user, vector<User*> users, vector<Tile*> tiles, vector<Card*> chance, vector<Card*> chest)
{
	UtilitiesTile* ut1{};
	UtilitiesTile* ut2{};

	//checks if the utilities are owned by the same player
	for (Tile* tile : tiles)
	{
		if ((*tile).getType() == "utility")
		{
			if (dynamic_cast<UtilitiesTile*>(tile)->getUtilType() == "electric")
			{
				ut1 = dynamic_cast<UtilitiesTile*>(tile);
			}
		}
		if ((*tile).getType() == "utility")
		{
			if (dynamic_cast<UtilitiesTile*>(tile)->getUtilType() == "water")
			{
				ut2 = dynamic_cast<UtilitiesTile*>(tile);
			}
		}
	}
	checkUtilitiesOwnership(ut1, ut2);
	//runs through the vector checking what type of tile is landed on and calling the corresponding methods 
	for (int i = 0; i < tiles.size(); i++)
	{
		if ((*tiles[i]).getType() == "street" && (*tiles[i]).containsPlayerChar((*user).getSymbol()))
		{
			//if its a street it checks if the street is owned, if owned it checks for color set, houses, hotel to determine what the rent is then moves the money between players accordingly
			if (dynamic_cast<Street*>(tiles[i])->getOwnerChar() != ' ')
			{
				for (User* u : users)
				{
					if (dynamic_cast<Street*>(tiles[i])->getOwnerChar() != (*user).getSymbol())
					{
						int rentElement;

						if (checkColorSet(dynamic_cast<Street*>(tiles[i]), tiles, user))
						{
							if (dynamic_cast<Street*>(tiles[i])->getHotel())
							{
								rentElement = 6;
							}
							else 
							{
								rentElement = dynamic_cast<Street*>(tiles[i])->getNumHouses() + 1;
							}
						}
						else
						{
							rentElement = 0;
						}

						int money = dynamic_cast<Street*>(tiles[i])->getTitleDeedPtr()->getRent(rentElement);
						(*u).addMoney(money);
						(*user).removeMoney(money);
					}
				}

			}
			else //if not it calls the buy option, if the player doesnt want to buy it it calls the auction method
			{
				if (!buyProperty(user, tiles[i]))
				{
					auction(users, tiles[i]);
				}
			}

		}
		else if ((*tiles[i]).getType() == "railroad" && (*tiles[i]).containsPlayerChar((*user).getSymbol()))
		{
			//checks if the railroad is owned, if it is it determines how many railroads a player owns then calculates the rent from that and moves the money between players accordingly
			if (dynamic_cast<Railroad*>(tiles[i])->getOwner() != ' ')
			{
				for (User* u : users)
				{
					if (dynamic_cast<Railroad*>(tiles[i])->getOwner() != (*user).getSymbol())
					{
						int numRailroad = getNumOwnedRailroads(u, tiles);
						int money = dynamic_cast<Railroad*>(tiles[i])->getRentValue(numRailroad);
						(*u).addMoney(money);
						(*user).removeMoney(money);
					}
				}

			}
			else //if not owned calls the buy property method, if the player doesnt want to buy it, calls the auction method 
			{
				if (!buyProperty(user, tiles[i]))
				{
					auction(users, tiles[i]);
				}
			}
		}
		else if ((*tiles[i]).getType() == "utility" && (*tiles[i]).containsPlayerChar((*user).getSymbol()))
		{
			//checks if the utility is owned, if it is determines the rent and moves the money accordingly
			if (dynamic_cast<UtilitiesTile*>(tiles[i])->getOwnerChar() != ' ')
			{
				for (User* u : users)
				{
					if (dynamic_cast<UtilitiesTile*>(tiles[i])->getOwnerChar() != (*user).getSymbol())
					{
						int money = dynamic_cast<UtilitiesTile*>(tiles[i])->getRent();
						(*u).addMoney(money);
						(*user).removeMoney(money);
						
					}
				}

			}
			else //if unowned it calls the buy method, it the player doesnt want to purchase it it calls the auction method
			{
				if (!buyProperty(user, tiles[i]))
				{
					auction(users, tiles[i]);
				}
			}
		}
		//if its a chance tile it draws a chance card and plays it
		else if ((*tiles[i]).getType() == "chance" && (*tiles[i]).containsPlayerChar((*user).getSymbol()))
		{
			Card* chanceCard = dynamic_cast<CardTile*>(tiles[i])->drawCard(chance);

			//if a move card the player is moved to the corresponding space, checking for passing go
			if (chanceCard->getType() == "move")
			{
				if (i > dynamic_cast<MoveCard*>(chanceCard)->doSomething())
				{
					(*user).addMoney(200);
				}
				(*tiles[i]).removePlayerChar((*user).getSymbol());
				(*tiles[dynamic_cast<MoveCard*>(chanceCard)->doSomething()]).addPlayerChar((*user).getSymbol());
			}
			//if its a money card the player is given the money
			else if (dynamic_cast<MoneyCard*>(chanceCard)->getType() == "money")
			{
				(*user).addMoney(dynamic_cast<MoneyCard*>(chanceCard)->doSomething());
			}
			//if a special card 
			else if (dynamic_cast<SpecialCard*>(chanceCard)->getType() == "special card")
			{ 
				if (dynamic_cast<SpecialCard*>(chanceCard)->doSomething() == 0) //get out of jail free
				{
					(*user).setChanceGetOutOfJail(true);
				}
				else if (dynamic_cast<SpecialCard*>(chanceCard)->doSomething() == 1) //go to jail
				{
					(*tiles[i]).removePlayerChar((*user).getSymbol());
					(*tiles[11]).addPlayerChar((*user).getSymbol());
					(*user).setInJail(true);
				}
				else if (dynamic_cast<SpecialCard*>(chanceCard)->doSomething() == 2) //lose 25 for each house and 100 for each hotel
				{
					vector<int*> money;
					findNumOwnedHouseHotel(user, tiles, money, 25, 100);

					int total{ 0 };
					for (int* i : money)
					{
						total += *i;
					}
					(*user).removeMoney(total);
					for (int* i : money)
					{
						delete i;
					}
				}
			}
			//moves player num spaces instead of to a specific space
			else if (dynamic_cast<AlternateMoveCard*>(chanceCard)->getType() == "alternate move card")
			{
				size_t newPos = i + dynamic_cast<AlternateMoveCard*>(chanceCard)->doSomething();
				if (newPos > tiles.size())
				{
					(*user).addMoney(200);
					newPos -= tiles.size();
				}
				if (i < 11 && newPos >= 11)
				{
					newPos++;
				}
				if (i > 11 && newPos <= 11)
				{
					newPos--;
				}
				(*tiles[i]).removePlayerChar((*user).getSymbol());
				(*tiles[newPos]).addPlayerChar((*user).getSymbol());
			}


		}
		//chest cards the basically the same except without any alternate move cards
		else if ((*tiles[i]).getType() == "chest" && (*tiles[i]).containsPlayerChar((*user).getSymbol()))
		{
			Card* chestCard = dynamic_cast<CardTile*>(tiles[i])->drawCard(chest);

			if (dynamic_cast<MoveCard*>(chestCard)->getType() == "move")
			{
				if (i > dynamic_cast<MoveCard*>(chestCard)->doSomething())
				{
					(*user).addMoney(200);
				}
				(*tiles[i]).removePlayerChar((*user).getSymbol());
				(*tiles[dynamic_cast<MoveCard*>(chestCard)->doSomething()]).addPlayerChar((*user).getSymbol());
			}
			else if (dynamic_cast<MoneyCard*>(chestCard)->getType() == "money")
			{
				(*user).addMoney(dynamic_cast<MoneyCard*>(chestCard)->doSomething());
			}
			else if (dynamic_cast<SpecialCard*>(chestCard)->getType() == "special card")
			{
				if (dynamic_cast<SpecialCard*>(chestCard)->doSomething() == 0) //get out of jail free
				{
					(*user).setChanceGetOutOfJail(true);
				}
				else if (dynamic_cast<SpecialCard*>(chestCard)->doSomething() == 1) //go to jail
				{
					(*tiles[i]).removePlayerChar((*user).getSymbol());
					(*tiles[11]).addPlayerChar((*user).getSymbol());
					(*user).setInJail(true);
				}
				else if (dynamic_cast<SpecialCard*>(chestCard)->doSomething() == 2) //lose 40 for each house and 110 for each hotel
				{
					vector<int*> money;
					findNumOwnedHouseHotel(user, tiles, money, 40, 110);

					int total{ 0 };
					for (int* i : money)
					{
						total += *i;
					}
					(*user).removeMoney(total);
					for (int* i : money)
					{
						delete i;
					}
				}
			}

		}
		//checks if its a tax space and takes out the corresponding amount of money
		else if ((*tiles[i]).getType() == "tax" && (*tiles[i]).containsPlayerChar((*user).getSymbol()))
		{
			int money = dynamic_cast<TaxTile*>(tiles[i])->getTaxValue();
			(*user).removeMoney(money);
		}
		//checks if its a corner tile and does the corresponding action, basically just moving the player to jail
		else if ((*tiles[i]).getType() == "corner tile" && (*tiles[i]).containsPlayerChar((*user).getSymbol()))
		{
			if ((*tiles[i]).getName() == "Go To Jail")
			{
				(*tiles[i]).removePlayerChar((*user).getSymbol());
				(*tiles[11]).addPlayerChar((*user).getSymbol());
				(*user).setInJail(true);
			}
			if ((*tiles[i]).getName() == "Jail")
			{
				(*user).setInJail(true);
			}
		}
	}
}

//method controlling the player getting out of jail and their options
void getOutOfJail(User* user, vector<Tile*> tiles)
{
	cout << "You are in Jail! \nYou can either: \n1)Pay $50 \n2)Use a get out of jail free card \n3)Try to roll a double" << endl;
	int userInput;
	cin >> userInput;

	switch (userInput)
	{
	case 1:
		//removes money for getting out of jail
		(*user).removeMoney(50);
		(*user).setInJail(false);
		break;

	case 2:
		//checks for get out of jail card
		if ((*user).getChanceGetOutOfJail())
		{
			cout << "Get out of jail card used" << endl;
			(*user).setChanceGetOutOfJail(false);
			(*user).setInJail(false);
		}
		if ((*user).getChestGetOutOfJail())
		{
			cout << "Get out of jail card used" << endl;
			(*user).setChestGetOutOfJail(false);
			(*user).setInJail(false);
		}
		break;

	case 3:
	{
		//rolls checking for a double, keeping track of number of tries
		srand(static_cast<unsigned int>(time(0)));

		int die1 = (rand() % 6) + 1;
		int die2 = (rand() % 6) + 1;

		if (die1 == die2)
		{
			cout << "Congrats you got lucky!" << endl;
			(*user).setInJail(false);
			(*user).resetJailDoubleCounter();

		}
		else
		{
			if ((*user).getJailDoubleCounter() == 3)
			{
				cout << "Missed again, you lose $50 but at least you're out of jail." << endl;
				(*user).removeMoney(50);
				(*user).setInJail(false);
				(*user).resetJailDoubleCounter();
			}
			else
			{
			
				cout << "Drat you rolled poorly." << endl;
				(*user).incrementJailDoubleCounter();
			}
		}
	}
		break;

	}
}

//returns the number of owned railroads for checking rent cost
int getNumOwnedRailroads(User* user, vector<Tile*> tiles)
{
	int numRailroad{ 0 };
	for(Tile* tile : tiles)
	{
		if ((*tile).getType() == "railroad")
		{
			if (dynamic_cast<Railroad*>(tile)->getOwner() == (*user).getSymbol())
			{
				numRailroad++;
			}
		}
	}
	return numRailroad;
}

//auctions the tile if the player does not wish to buy it 
void auction(vector<User*> users, Tile* tile)
{
	cout << "Bid starts at $10" << endl;

	int bid{ 10 };
	//holds the user who bids the highest
	User* bidWinner = users[0];

	//bool for if everyone passed
	bool allPassed{ false };

	//vector keeping track of how many people passed
	vector<bool> passed;
	passed.resize(users.size(), false);

	//bool controlling the loop
	bool stillBidding{ true };

	while(stillBidding && !allPassed)
	{
		//each user bids until there is only one bidder left or everyone passes
		for (int i = 0; i < users.size(); i++)
		{
			if(passed[i] == false)
			{
				if (bid > 10)
				{
					cout << "New bid is at " << bid << endl;
				}
				char userInput;
				cout << (char)(*users[i]).getSymbol() << "'s turn." << endl;
				cout << "Increase bid or pass(b/p): " << endl;
				cin >> userInput;
				if (userInput == 'b')
				{
					bool higherBid{ false };
					while(!higherBid)
					{
						int newBid;
						cout << "Enter new bid: " << endl;
						cin >> newBid;
						if (newBid > bid)
						{
							higherBid = true;
							bid = newBid;
						}
						else
						{
							cout << "Invalid bid. Try again." << endl;
						}
						
					}
					bidWinner = users[i];
					passed[i] = false;
				}
				else
				{
					passed[i] = true;
				}
				
			}
		}
		int counter{ 0 };
		for (bool b : passed)
		{
			if (b == true)
			{
				counter++;
			}
		}
		if (counter == (users.size() - 1))
		{
			stillBidding = false;

		}
		else if (counter == users.size())
		{
			allPassed = true;
		}
	}
	//if someone wins the bid they buy the tile at that price, if everyone passed the tile remains unbought
	if(!allPassed)
	{
		cout << (char)(*bidWinner).getSymbol() << " wins the bid!" << endl;
		if ((*tile).getType() == "utility")
		{
			dynamic_cast<UtilitiesTile*>(tile)->setOwnerChar((*bidWinner).getSymbol());
			(*bidWinner).removeMoney(bid);

		}
		else if ((*tile).getType() == "street")
		{
			dynamic_cast<Street*>(tile)->setOwnerChar((*bidWinner).getSymbol());
			(*bidWinner).removeMoney(bid);
		}
		else
		{
			dynamic_cast<Railroad*>(tile)->setOwner((*bidWinner).getSymbol());
			(*bidWinner).removeMoney(bid);
		}
	}
	else
	{
		cout << "Everyone Passed" << endl;
	}
}

//method returning a bool if the player has a property, used for checking if they can mortgage any property to stay in the game
bool hasProperty(User* user, vector<Tile*> tiles)
{
	for (Tile* t : tiles)
	{
		if (t->getType() == "railroad")
		{
		if (dynamic_cast<Railroad*>(t)->getOwner() == user->getSymbol())
		{
			return true;
		}
		}
		else if (t->getType() == "utility")
		{
		if (dynamic_cast<UtilitiesTile*>(t)->getOwnerChar() == user->getSymbol())
		{
			return true;
		}
		}
		else if (t->getType() == "street")
		{
		if (dynamic_cast<Street*>(t)->getOwnerChar() == user->getSymbol())
		{
			return true;
		}
		}
	}
	return false;
}

//method returning a bool if the user buys a property, the bool is used to determine if the auction method needs to be called
bool buyProperty(User* user, Tile* tile)
{
	bool bought{ false };
	char userInput;
	
	//if statements checking what type of property the tile is then down casting the object so that the corresponding child object methods can be called
	if ((*tile).getType() == "utility")
	{
		cout << "Would you like to buy " << (*tile).getName() << " for $" << dynamic_cast<UtilitiesTile*>(tile)->getBuyValue() << "?(y/n)" << endl;
	}
	else if ((*tile).getType() == "street")
	{
		cout << "Would you like to buy " << (*tile).getName() << " for $" << dynamic_cast<Street*>(tile)->getBuyValue() << "?(y/n)" << endl;
	}
	else
	{
		cout << "Would you like to buy " << (*tile).getName() << " for $" << dynamic_cast<Railroad*>(tile)->getBuyValue() << "?(y/n)" << endl;
	}


	cin >> userInput;

	if (userInput == 'y')
	{
		//if statements checking what type of property the tile is then down casting the object so that the corresponding child object methods can be called
		if ((*tile).getType() == "utility")
		{
			(*user).removeMoney(dynamic_cast<UtilitiesTile*>(tile)->getBuyValue());
			dynamic_cast<UtilitiesTile*>(tile)->setOwnerChar((*user).getSymbol());
			bought = true;
		}
		else if ((*tile).getType() == "street")
		{
			(*user).removeMoney(dynamic_cast<Street*>(tile)->getBuyValue());
			dynamic_cast<Street*>(tile)->setOwnerChar((*user).getSymbol());
			bought = true;
		}
		else
		{
			(*user).removeMoney(dynamic_cast<Railroad*>(tile)->getBuyValue());
			dynamic_cast<Railroad*>(tile)->setOwner((*user).getSymbol());
			bought = true;
		}
		
	}

	return bought;
}

//method that sells a piece of property, either a house, hotel or mortgage
void sellProperty(User* user, Tile* tile)
{
	//if statements checking what type of property it is then its down cast to the corresponding child object so that the right methods can be called and the object changed
	if ((*tile).getType() == "utility")
	{
		dynamic_cast<UtilitiesTile*>(tile)->setMortgage(true);
		user->addMoney(dynamic_cast<UtilitiesTile*>(tile)->getMortgageValue());
		user->setHasMortgage(true);
	}
	else if ((*tile).getType() == "street")
	{
		if (dynamic_cast<Street*>(tile)->getHotel())
		{
			dynamic_cast<Street*>(tile)->setHotel(false);
			dynamic_cast<Street*>(tile)->setNumHouses(4);
			user->addMoney(dynamic_cast<Street*>(tile)->getTitleDeedPtr()->getHotelCost() / 2);
		}
		else if (dynamic_cast<Street*>(tile)->getNumHouses() > 0)
		{
			dynamic_cast<Street*>(tile)->setNumHouses(3);
			user->addMoney(dynamic_cast<Street*>(tile)->getTitleDeedPtr()->getHouseCost() / 2);
		}
		else
		{
			dynamic_cast<Street*>(tile)->setMortgage(true);
			user->addMoney(dynamic_cast<Street*>(tile)->getTitleDeedPtr()->getMortgageValue());
			user->setHasMortgage(true);
		}
	}
	else
	{
		dynamic_cast<Railroad*>(tile)->setMortgage(true);
		user->addMoney(dynamic_cast<Railroad*>(tile)->getMortgageValue());
		user->setHasMortgage(true);
	}
}

//method buying back a mortgage for a player
void buyBackMortgage(User* user, vector<Tile*> tiles)
{
	vector<int> properties;
	vector<int> mortgageValues;

	for (int i = 0; i < tiles.size(); i++)
	{
		//if statements checking what type of property it is then its down cast to the corresponding child object so that the right methods can be called and the object changed
		if ((*tiles[i]).getType() == "street")
		{
			if (dynamic_cast<Street*>(tiles[i])->getMortgage())
			{
				properties.push_back(i);
				mortgageValues.push_back(dynamic_cast<Street*>(tiles[i])->getTitleDeedPtr()->getMortgageValue() + (dynamic_cast<Street*>(tiles[i])->getTitleDeedPtr()->getMortgageValue() / 10));
			}
		}
		if ((*tiles[i]).getType() == "utility")
		{
			if (dynamic_cast<UtilitiesTile*>(tiles[i])->getMortgage())
			{
				properties.push_back(i);
				mortgageValues.push_back(dynamic_cast<UtilitiesTile*>(tiles[i])->getMortgageValue() + (dynamic_cast<UtilitiesTile*>(tiles[i])->getMortgageValue() / 10));
			}
		}
		if ((*tiles[i]).getType() == "railroad")
		{
			if (dynamic_cast<Railroad*>(tiles[i])->getMortgage())
			{
				properties.push_back(i);
				mortgageValues.push_back(dynamic_cast<Railroad*>(tiles[i])->getMortgageValue() + (dynamic_cast<Railroad*>(tiles[i])->getMortgageValue() / 10));
			}
		}
	}
	//input validation
	bool validInput{ false };
	while(!validInput)
	{

		cout << "Which mortgage would you like to buy back?" << endl;
		int userInput;
		for (int i : properties)
		{
			cout << i << tiles[i]->getName() << " $" << mortgageValues[i] << endl;
		}
		cin >> userInput;


		for (int i : properties)
		{
			if (i = userInput)
			{
				validInput = true;
			}
		}


		if (validInput)
		{
			if ((*tiles[userInput]).getType() == "street")
			{
				if (dynamic_cast<Street*>(tiles[userInput])->getMortgage())
				{
					user->removeMoney(dynamic_cast<Street*>(tiles[userInput])->getTitleDeedPtr()->getMortgageValue() + (dynamic_cast<Street*>(tiles[userInput])->getTitleDeedPtr()->getMortgageValue() / 10));
					dynamic_cast<Street*>(tiles[userInput])->setMortgage(false);
				}
			}
			if ((*tiles[userInput]).getType() == "utility")
			{
				if (dynamic_cast<UtilitiesTile*>(tiles[userInput])->getMortgage())
				{
					user->removeMoney(dynamic_cast<UtilitiesTile*>(tiles[userInput])->getMortgageValue() + (dynamic_cast<UtilitiesTile*>(tiles[userInput])->getMortgageValue() / 10));
					dynamic_cast<UtilitiesTile*>(tiles[userInput])->setMortgage(false);
				}
			}
			if ((*tiles[userInput]).getType() == "railroad")
			{
				if (dynamic_cast<Railroad*>(tiles[userInput])->getMortgage())
				{
					user->removeMoney(dynamic_cast<Railroad*>(tiles[userInput])->getMortgageValue() + (dynamic_cast<Railroad*>(tiles[userInput])->getMortgageValue() / 10));
					dynamic_cast<Railroad*>(tiles[userInput])->setMortgage(false);
				}
			}
		}
		else
		{
			cout << "Invalid Input, Try Again." << endl;
		}
		properties.clear();

	}

}

//method resetting a users owned properties when they lose
void resetProperties(User* user, vector<Tile*>tiles)
{
	for (Tile* t : tiles)
	{
		if (t->getType() == "railroad")
		{
			if (dynamic_cast<Railroad*>(t)->getOwner() == user->getSymbol())
			{
				dynamic_cast<Railroad*>(t)->setMortgage(false);
				dynamic_cast<Railroad*>(t)->setOwner(' ');

			}
		}
		else if (t->getType() == "utility")
		{
			if (dynamic_cast<UtilitiesTile*>(t)->getOwnerChar() == user->getSymbol())
			{
				dynamic_cast<UtilitiesTile*>(t)->setMortgage(false);
				dynamic_cast<UtilitiesTile*>(t)->setOwnerChar(' ');
				dynamic_cast<UtilitiesTile*>(t)->setSameOwner(false);
			}
		}
		else if (t->getType() == "street")
		{
			if (dynamic_cast<Street*>(t)->getOwnerChar() == user->getSymbol())
			{
				dynamic_cast<Street*>(t)->setMortgage(false);
				dynamic_cast<Street*>(t)->setOwnerChar(' ');
				dynamic_cast<Street*>(t)->setNumHouses(0);
				dynamic_cast<Street*>(t)->setHotel(false);
				
			}
		}
	}
}

//method checking if a player owns a color set, used in determing if they can buy a house on it and for determining rent 
bool checkColorSet(Street* street, vector<Tile*> tiles, User* user)
{
	vector<Street*> colorSet;

	bool sameOwner{ false };

	for (Tile* t : tiles)
	{
		if ((*t).getType() == "street" && dynamic_cast<Street*>(t)->getColor() == street->getColor())
		{
			colorSet.push_back(dynamic_cast<Street*>(t));
		}
	}

	size_t numStreets = colorSet.size();

	if (numStreets == 2)
	{
		if ((*colorSet[0]).getOwnerChar() == (*colorSet[1]).getOwnerChar())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if ((*colorSet[0]).getOwnerChar() == (*colorSet[1]).getOwnerChar() && (*colorSet[1]).getOwnerChar() == (*colorSet[2]).getOwnerChar())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}

//method that buys a house or hotel on a street for the user, checks that none of the streets in a color set are mortgaged and that a house or hotel can only be bought when the player has the right number of houses on other tiles in the color set
void buyHouseHotel(Street* street, vector<Tile*> tiles, User* user)
{
	vector<Street*> colorSet;

	bool withinOne{ false };
	bool allowHotel{ false };

	for (Tile* t : tiles)
	{
		if ((*t).getType() == "street" && dynamic_cast<Street*>(t)->getColor() == street->getColor())
		{
			colorSet.push_back(dynamic_cast<Street*>(t));
		}
	}
	size_t numStreets = colorSet.size();

	if (numStreets == 2)
	{
		if ((*colorSet[0]).getMortgage() == true || (*colorSet[1]).getMortgage() == true)
		{
			cout << "Unable to purchase any houses or hotels due to a mortgaged property in color set." << endl;
		}
		else
		{
			if ((*colorSet[0]).getNumHouses() == (*colorSet[1]).getNumHouses() && (*colorSet[1]).getNumHouses() != 4)
			{
				withinOne = true;
			}
			else if (((*colorSet[0]).getNumHouses() + 1) == (*colorSet[1]).getNumHouses())
			{
				withinOne = true;
			}
			else if ((*colorSet[0]).getNumHouses() == (*colorSet[1]).getNumHouses() && (*colorSet[1]).getNumHouses() == 4)
			{
				allowHotel = true;
			}
		}
	}
	else
	{
		if ((*colorSet[0]).getMortgage() == true || (*colorSet[1]).getMortgage() == true || (*colorSet[2]).getNumHouses() == true)
		{
			cout << "Unable to purchase any houses or hotels due to a mortgaged property in color set." << endl;
		}
		else
		{
			if ((*colorSet[0]).getNumHouses() == (*colorSet[1]).getNumHouses() && (*colorSet[1]).getNumHouses() == (*colorSet[2]).getNumHouses() && (*colorSet[2]).getNumHouses() != 4)
			{
				withinOne = true;
			}
			else if ((*colorSet[0]).getNumHouses() == (*colorSet[1]).getNumHouses() && (*colorSet[1]).getNumHouses() == (*colorSet[2]).getNumHouses() && (*colorSet[2]).getNumHouses() == 4)
			{
				allowHotel = true;
			}
			else if ((*colorSet[0]).getNumHouses() <= (*colorSet[1]).getNumHouses() && (*colorSet[0]).getNumHouses() <= (*colorSet[2]).getNumHouses())
			{
				withinOne = true;
			}
		}
	
	}


	if (withinOne)
	{
		(*street).incrementNumHouses();
		(*user).removeMoney((*(*street).getTitleDeedPtr()).getHouseCost());
	}

	if ((*street).getNumHouses() < 4)
	{
		
	}
	else
	{
		(*street).setNumHouses(0);
		(*street).setHotel(true);
	}
}

//method used for a chance card that finds the total number of owned houses and hotels on a players streets and sets an int pointer vector accordingly
void findNumOwnedHouseHotel(User* user, vector<Tile*> tiles, vector<int*>& money, int houseCost, int hotelCost)
{
	for (int i = 0; i < tiles.size(); i++)
	{
		if ((*tiles[i]).getType() == "street")
		{
			if (dynamic_cast<Street*>(tiles[i])->getOwnerChar() == (*user).getSymbol())
			{
				if (dynamic_cast<Street*>(tiles[i])->getHotel())
				{
					money.push_back(new int (hotelCost));
				}
				else
				{
					money.push_back(new int(dynamic_cast<Street*>(tiles[i])->getNumHouses() * houseCost));
				}

			}

		}

	}
}

//method that prints a players owned properties for later prompting, fills vector of int pointer with the owned property element values
void printOwnedProperties(User* user, vector<Tile*> tiles, vector<int*>& properties)
{
	cout << "Pick an owned property: " << endl;
	for (int i = 0; i < tiles.size(); i++)
	{
		if ((*tiles[i]).getType() == "street")
		{
			if (dynamic_cast<Street*>(tiles[i])->getOwnerChar() == (*user).getSymbol())
			{
				cout << i << " for " << tiles[i]->getName() << endl;
				properties.push_back(new int(i));
				
			}
			
		}
		else if ((*tiles[i]).getType() == "railroad")
		{
			if (dynamic_cast<Railroad*>(tiles[i])->getOwner() == (*user).getSymbol())
			{
				cout << i << " for " << tiles[i]->getName() << endl;
				properties.push_back(new int(i));
			}
		}
		else if ((*tiles[i]).getType() == "utility")
		{
			if (dynamic_cast<UtilitiesTile*>(tiles[i])->getOwnerChar() == (*user).getSymbol())
			{
				cout << i << " for " << tiles[i]->getName() << endl;
				properties.push_back(new int(i));
			}
		}
	}
}

//does the same as the print owned properties method except only for streets
void printOwnedStreets(User* user, vector<Street*> streets, vector<int*>& properties)
{
	cout << "Pick an owned street: " << endl;
	for (int i = 0; i < streets.size(); i++)
	{
		if (streets[i]->getOwnerChar() == user->getSymbol())
		{
			cout << i << " for " << streets[i]->getName() << endl;
			properties.push_back(new int(i));
		}
	}
			
}

//method that mortgages a property
void mortgageProperty(User* user, Tile *tile)
{
	if ((*tile).getType() == "street")
	{
		Street *s = dynamic_cast<Street*>(tile);
		if (s->getHotel() == false && s->getNumHouses() == 0)
		{
			s->setMortgage(true);
			(*user).addMoney(s->getTitleDeedPtr()->getMortgageValue());
			user->setHasMortgage(true);
		}
	}
	else if ((*tile).getType() == "railroad")
	{
		Railroad *r = dynamic_cast<Railroad*>(tile);
		r->setMortgage(true);
		(*user).addMoney(r->getMortgageValue());
		user->setHasMortgage(true);
	}
	else if ((*tile).getType() == "utility")
	{
		UtilitiesTile *u = dynamic_cast<UtilitiesTile*>(tile);
		u->setMortgage(true);
		(*user).addMoney(u->getMortgageValue());
		user->setHasMortgage(true);
	}
}

//method that prints the cheats menu
void printCheatsMenu()
{
	string output = "Choose a cheat: \n1)Give a property \n2)Give color set of streets \n3)Give all properties \n4)Give house or hotel \n5)Give amount of money \n6)Move to boardspace \n7)Auto Win\n";
	
	cout << output;
}

//method that gives the player a property they choose
void giveProperty(User* user, string propertyName, vector<Tile*> tiles)
{
	for (Tile* tile : tiles)
	{
		if ((*tile).getType() == "street" && (*tile).getName() == propertyName)
		{
			Street* s = dynamic_cast<Street*>(tile);
			s->setOwnerChar((*user).getSymbol());
		}
		else if ((*tile).getType() == "railroad" && (*tile).getName() == propertyName)
		{
			Railroad* r = dynamic_cast<Railroad*>(tile);
			r->setOwner((*user).getSymbol());
		}
		else if ((*tile).getType() == "utility" && (*tile).getName() == propertyName)
		{
			UtilitiesTile* u = dynamic_cast<UtilitiesTile*>(tile);
			u->setOwnerChar((*user).getSymbol());
		}
	}

}

//method that gives the player their choise of a color set
void giveColorSet(User* user, string color, vector<Street*> streets)
{
	for (Street* s : streets)
	{
		if ((*s).getColor() == color)
		{
			(*s).setOwnerChar((*user).getSymbol());
		}
	}
}

//method that gives the player any number of houses or a hotel
void giveHouseHotel(vector<Street*> streets, Street* street, int numHouses, bool hotel)
{
	for (Street* s : streets)
	{
		if (street->getColor() == s->getColor() && street->getName() != s->getName())
		{
			if (hotel)
			{
				street->setHotel(true);
				s->setNumHouses(4);
			}
			else
			{
				s->setNumHouses(numHouses);
			}
		}
	}
}

//gives the player every property
void giveAllProperties(User* user, vector<Tile*> tiles)
{
	for (Tile* tile : tiles)
	{
		if ((*tile).getType() == "street")
		{
			Street* s = dynamic_cast<Street*>(tile);
			s->setOwnerChar((*user).getSymbol());
		}
		else if ((*tile).getType() == "railroad")
		{
			Railroad* r = dynamic_cast<Railroad*>(tile);
			r->setOwner((*user).getSymbol());
		}
		else if ((*tile).getType() == "utility")
		{
			UtilitiesTile* u = dynamic_cast<UtilitiesTile*>(tile);
			u->setOwnerChar((*user).getSymbol());
		}
	}
}

//gives the player their choice of additional money
void giveMoney(User* user, int money)
{
	(*user).addMoney(money);
}

//moves the player to their choice of tile space 
void moveToBoardspace(User* user, vector<Tile*> tiles, int tileNumber)
{
	for (Tile* t : tiles)
	{
		if (t->containsPlayerChar(user->getSymbol()))
		{
			t->removePlayerChar(user->getSymbol());
		}
	}
	(*tiles[tileNumber]).addPlayerChar((*user).getSymbol());
}

//method diplaying the board, the board is printed line by line
void displayBoard(vector<Tile*> tiles)
{
	//char pointer for each tile space that hold the the "array" of player characters 
	char* freeParkingPtr = (*tiles[21]).getPlayers();
	char* kentuckyAvenuePtr = (*tiles[22]).getPlayers();
	char* chance2Ptr = (*tiles[23]).getPlayers();
	char* indianaAvenuePtr = (*tiles[24]).getPlayers();
	char* illinoisAvenuePtr = (*tiles[25]).getPlayers();
	char* boRailroadPtr = (*tiles[26]).getPlayers();
	char* atlanticAvenuePtr = (*tiles[27]).getPlayers();
	char* ventnorAvenuePtr = (*tiles[28]).getPlayers(); 
	char* waterWorksPtr = (*tiles[29]).getPlayers();
	char* marvinGardensPtr = (*tiles[30]).getPlayers();
	char* goToJailPtr = (*tiles[31]).getPlayers();
	char* newYorkAvenuePtr = (*tiles[20]).getPlayers();
	char* pacificAvenuePtr = (*tiles[32]).getPlayers();
	char* tennesseeAvenuePtr = (*tiles[19]).getPlayers(); 
	char* northCarolinaAvenuePtr = (*tiles[33]).getPlayers();
	char* communityChest2Ptr = (*tiles[18]).getPlayers(); 
	char* communityChest3Ptr = (*tiles[34]).getPlayers();
	char* stJamesAvenuePtr = (*tiles[17]).getPlayers();
	char* pennsylvaniaAvenuePtr = (*tiles[35]).getPlayers(); 
	char* pennsylvaniaRailroadPtr = (*tiles[16]).getPlayers();
	char* shortLinePtr = (*tiles[36]).getPlayers();
	char* virgniaAvenuePtr = (*tiles[15]).getPlayers();
	char* chance3Ptr = (*tiles[37]).getPlayers();
	char* statesAvenuePtr = (*tiles[14]).getPlayers();
	char* parkPlacePtr = (*tiles[38]).getPlayers();
	char* electricCompanyPtr = (*tiles[13]).getPlayers();
	char* luxuryTaxPtr = (*tiles[39]).getPlayers();
	char* stCharlesPlacePtr = (*tiles[12]).getPlayers();
	char* boardwalkPtr = (*tiles[40]).getPlayers();
	char* inJailPtr = (*tiles[11]).getPlayers();
	char* justVisitingPtr = (*tiles[10]).getPlayers();
	char* connecticutAvenuePtr = (*tiles[9]).getPlayers();
	char* vermontAvenuePtr = (*tiles[8]).getPlayers();
	char* chance1Ptr = (*tiles[7]).getPlayers();
	char* orientalAvenuePtr = (*tiles[6]).getPlayers();
	char* readingRailroadPtr = (*tiles[5]).getPlayers();
	char* incomeTaxPtr = (*tiles[4]).getPlayers();
	char* balticAvenuePtr = (*tiles[3]).getPlayers();
	char* communityChest1Ptr = (*tiles[2]).getPlayers();
	char* mediterraneanAvenuePtr = (*tiles[1]).getPlayers();
	char* goPtr = (*tiles[0]).getPlayers();

	//char's for each property tile that hold the symbol of the owner
	char kentuckyAvenueOwnerPtr = dynamic_cast<Street*>(tiles[22])->getOwnerChar();
	char indianaAvenueOwnerPtr = dynamic_cast<Street*>(tiles[24])->getOwnerChar();
	char illinoisAvenueOwnerPtr = dynamic_cast<Street*>(tiles[25])->getOwnerChar();
	char boRailroadOwnerPtr = dynamic_cast<Railroad*>(tiles[26])->getOwner();
	char atlanticAvenueOwnerPtr = dynamic_cast<Street*>(tiles[27])->getOwnerChar();
	char ventnorAvenueOwnerPtr = dynamic_cast<Street*>(tiles[28])->getOwnerChar();
	char waterWorksOwnerPtr = dynamic_cast<UtilitiesTile*>(tiles[29])->getOwnerChar();
	char marvinGardensOwnerPtr = dynamic_cast<Street*>(tiles[30])->getOwnerChar();
	char newYorkAvenueOwnerPtr = dynamic_cast<Street*>(tiles[20])->getOwnerChar();
	char pacificAvenueOwnerPtr = dynamic_cast<Street*>(tiles[32])->getOwnerChar();
	char tennesseeAvenueOwnerPtr = dynamic_cast<Street*>(tiles[19])->getOwnerChar();
	char northCarolinaAvenueOwnerPtr = dynamic_cast<Street*>(tiles[33])->getOwnerChar();
	char stJamesAvenueOwnerPtr = dynamic_cast<Street*>(tiles[17])->getOwnerChar();
	char pennsylvaniaAvenueOwnerPtr = dynamic_cast<Street*>(tiles[35])->getOwnerChar();
	char pennsylvaniaRailroadOwnerPtr = dynamic_cast<Railroad*>(tiles[16])->getOwner();
	char shortLineOwnerPtr = dynamic_cast<Railroad*>(tiles[36])->getOwner();
	char virgniaAvenueOwnerPtr = dynamic_cast<Street*>(tiles[15])->getOwnerChar();
	char statesAvenueOwnerPtr = dynamic_cast<Street*>(tiles[14])->getOwnerChar();
	char parkPlaceOwnerPtr = dynamic_cast<Street*>(tiles[38])->getOwnerChar();
	char electricCompanyOwnerPtr = dynamic_cast<UtilitiesTile*>(tiles[13])->getOwnerChar();
	char stCharlesPlaceOwnerPtr = dynamic_cast<Street*>(tiles[12])->getOwnerChar();
	char boardwalkOwnerPtr = dynamic_cast<Street*>(tiles[40])->getOwnerChar();
	char connecticutAvenueOwnerPtr = dynamic_cast<Street*>(tiles[9])->getOwnerChar();
	char vermontAvenueOwnerPtr = dynamic_cast<Street*>(tiles[8])->getOwnerChar();
	char orientalAvenueOwnerPtr = dynamic_cast<Street*>(tiles[6])->getOwnerChar();
	char readingRailroadOwnerPtr = dynamic_cast<Railroad*>(tiles[5])->getOwner();
	char balticAvenueOwnerPtr = dynamic_cast<Street*>(tiles[3])->getOwnerChar();
	char mediterraneanAvenueOwnerPtr = dynamic_cast<Street*>(tiles[1])->getOwnerChar();


	//strings for each property tile that either hold "x houses" or "has hotel"
	string kentuckyAvenueHouseHotel; 
	if (dynamic_cast<Street*>(tiles[22])->getHotel())
	{
		kentuckyAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		kentuckyAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[22])->getNumHouses()) + " house(s)";
	}
	string indianaAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[24])->getHotel())
	{
		indianaAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		indianaAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[24])->getNumHouses()) + " house(s)";
	}
	string illinoisAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[25])->getHotel())
	{
		illinoisAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		illinoisAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[25])->getNumHouses()) + " house(s)";
	}
	string atlanticAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[27])->getHotel())
	{
		atlanticAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		atlanticAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[27])->getNumHouses()) + " house(s)";
	}
	string ventnorAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[28])->getHotel())
	{
		ventnorAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		ventnorAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[28])->getNumHouses()) + " house(s)";
	}
	string marvinGardensHouseHotel;
	if(dynamic_cast<Street*>(tiles[30])->getHotel())
	{
		marvinGardensHouseHotel = "Has  Hotel";
	}
	else
	{
		marvinGardensHouseHotel = to_string(dynamic_cast<Street*>(tiles[30])->getNumHouses()) + " house(s)";
	}
	string newYorkAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[20])->getHotel())
	{
		newYorkAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		newYorkAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[20])->getNumHouses()) + " house(s)";
	}
	string pacificAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[32])->getHotel())
	{
		pacificAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		pacificAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[32])->getNumHouses()) + " house(s)";
	}
	string tennesseeAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[19])->getHotel())
	{
		tennesseeAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		tennesseeAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[19])->getNumHouses()) + " house(s)";
	}
	string northCarolinaAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[33])->getHotel())
	{
		northCarolinaAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		northCarolinaAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[33])->getNumHouses()) + " house(s)";
	}
	string stJamesAvenueHouseHotel;
	if (dynamic_cast<Street*>(tiles[17])->getHotel())
	{
		stJamesAvenueHouseHotel = "Has  Hotel";
	} 
	else
	{
		stJamesAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[17])->getNumHouses()) + " house(s)";
	}
	string pennsylvaniaAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[35])->getHotel())
	{
		pennsylvaniaAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		pennsylvaniaAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[35])->getNumHouses()) + " house(s)";
	}
	string virgniaAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[15])->getHotel())
	{
		virgniaAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		virgniaAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[15])->getNumHouses()) + " house(s)";
	}
	string statesAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[14])->getHotel())
	{
		statesAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		statesAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[14])->getNumHouses()) + " house(s)";
	}
	string parkPlaceHouseHotel;
	if(dynamic_cast<Street*>(tiles[38])->getHotel())
	{
		parkPlaceHouseHotel = "Has  Hotel";
	}
	else
	{
		parkPlaceHouseHotel = to_string(dynamic_cast<Street*>(tiles[38])->getNumHouses()) + " house(s)";
	}
	string stCharlesPlaceHouseHotel;
	if(dynamic_cast<Street*>(tiles[12])->getHotel())
	{
		stCharlesPlaceHouseHotel = "Has  Hotel";
	}
	else
	{
		stCharlesPlaceHouseHotel = to_string(dynamic_cast<Street*>(tiles[12])->getNumHouses()) + " house(s)";
	}
	string boardwalkHouseHotel;
	if(dynamic_cast<Street*>(tiles[40])->getHotel())
	{
		boardwalkHouseHotel = "Has  Hotel";
	}
	else
	{
		boardwalkHouseHotel = to_string(dynamic_cast<Street*>(tiles[40])->getNumHouses()) + " house(s)";
	}
	string connecticutAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[9])->getHotel())
	{
		connecticutAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		connecticutAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[9])->getNumHouses()) + " house(s)";
	}
	string vermontAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[8])->getHotel())
	{
		vermontAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		vermontAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[8])->getNumHouses()) + " house(s)";
	}
	string orientalAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[6])->getHotel())
	{
		orientalAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		orientalAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[6])->getNumHouses()) + " house(s)";
	}
	string balticAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[3])->getHotel())
	{
		balticAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		balticAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[3])->getNumHouses()) + " house(s)";
	}
	string mediterraneanAvenueHouseHotel;
	if(dynamic_cast<Street*>(tiles[1])->getHotel())
	{
		mediterraneanAvenueHouseHotel = "Has  Hotel";
	}
	else
	{
		mediterraneanAvenueHouseHotel = to_string(dynamic_cast<Street*>(tiles[1])->getNumHouses()) + " house(s)";
	}





	cout << endl;
	//board printed line by line with the corresponding char*, char and string
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|   Free     |  Kentucky  |   Chance   |   Indiana  |  Illinois  |   B & O    |  Atlantic  |   Ventnor  |    Water   |   Marvin   |   Go  To   |" << endl;
	cout << "|  Parking   |   Avenue   |            |   Avenue   |   Avenue   |  Railroad  |   Avenue   |   Avenue   |    Works   |  Gardens   |    Jail    |" << endl;
	cout << "|            |            |            |            |            |            |            |            |            |            |            |" << endl;
	cout << "|            | " << kentuckyAvenueHouseHotel <<" |            | " << indianaAvenueHouseHotel << " | " << illinoisAvenueHouseHotel << " |            | " << atlanticAvenueHouseHotel << " | " << ventnorAvenueHouseHotel << " |            | " << marvinGardensHouseHotel << " |            |" << endl;
	cout << "|            | Owned by: " << kentuckyAvenueOwnerPtr << "|            | Owned by: " << indianaAvenueOwnerPtr << "| Owned by: " << illinoisAvenueOwnerPtr << "| Owned by: " << boRailroadOwnerPtr << "| Owned by: " << atlanticAvenueOwnerPtr << "| Owned by: " << ventnorAvenueOwnerPtr << "| Owned by: " << waterWorksOwnerPtr << "| Owned by: " << marvinGardensOwnerPtr << "|            |" << endl;
	cout << "|   " << freeParkingPtr[0] << " " << freeParkingPtr[1] << " " << freeParkingPtr[2] << "    |   " << kentuckyAvenuePtr[0] << " " << kentuckyAvenuePtr[1] << " " << kentuckyAvenuePtr[2] << "    |   " << chance2Ptr[0] << " " << chance2Ptr[1] << " " << chance2Ptr[2] << "    |    " << indianaAvenuePtr[0] << " " << indianaAvenuePtr[1] << " " << indianaAvenuePtr[2] << "   |    " << illinoisAvenuePtr[0] << " " << illinoisAvenuePtr[1] << " " << illinoisAvenuePtr[2] << "   |    " << boRailroadPtr[0] << " " << boRailroadPtr[1] << " " << boRailroadPtr[2] << "   |   " << atlanticAvenuePtr[0] << " " << atlanticAvenuePtr[1] << " " << atlanticAvenuePtr[2] << "    |    " << ventnorAvenuePtr[0] << " " << ventnorAvenuePtr[1] << " " << ventnorAvenuePtr[2] << "   |   " << waterWorksPtr[0] << " " << waterWorksPtr[1] << " " << waterWorksPtr[2] << "    |   " << marvinGardensPtr[0] << " " << marvinGardensPtr[1] << " " << marvinGardensPtr[2] << "    |   " << goToJailPtr[0] << " " << goToJailPtr[1] << " " << goToJailPtr[2] << "    |" << endl;
	cout << "|   " << freeParkingPtr[3] << " " << freeParkingPtr[4] << " " << freeParkingPtr[5] << "    |   " << kentuckyAvenuePtr[3] << " " << kentuckyAvenuePtr[4] << " " << kentuckyAvenuePtr[5] << "    |   " << chance2Ptr[3] << " " << chance2Ptr[4] << " " << chance2Ptr[5] << "    |    " << indianaAvenuePtr[3] << " " << indianaAvenuePtr[4] << " " << indianaAvenuePtr[5] << "   |    " << illinoisAvenuePtr[3] << " " << illinoisAvenuePtr[4] << " " << illinoisAvenuePtr[5] << "   |    " << boRailroadPtr[3] << " " << boRailroadPtr[4] << " " << boRailroadPtr[5] << "   |   " << atlanticAvenuePtr[3] << " " << atlanticAvenuePtr[4] << " " << atlanticAvenuePtr[5] << "    |    " << ventnorAvenuePtr[3] << " " << ventnorAvenuePtr[4] << " " << ventnorAvenuePtr[5] << "   |   " << waterWorksPtr[3] << " " << waterWorksPtr[4] << " " << waterWorksPtr[5] << "    |   " << marvinGardensPtr[3] << " " << marvinGardensPtr[4] << " " << marvinGardensPtr[5] << "    |   " << goToJailPtr[3] << " " << goToJailPtr[4] << " " << goToJailPtr[5] << "    |" << endl;
	cout << "|            |    $220    |            |    $220    |    $240    |    $200    |    $260    |    $260    |    $150    |    $280    |            |" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|  New York  |                                                                                                                    |   Pacific  |" << endl;
	cout << "|   Avenue   |                                                                                                                    |    Avenue  |" << endl;
	cout << "|            |                                                                                                                    |            |" << endl;
	cout << "| " << newYorkAvenueHouseHotel << " |                                                                                                                    | " << pacificAvenueHouseHotel << " |" << endl;
	cout << "| Owned by: " << newYorkAvenueOwnerPtr << "|                                                                                                                    | Owned by: " << pacificAvenueOwnerPtr << "|" << endl;
	cout << "|   " << newYorkAvenuePtr[0] << " " << newYorkAvenuePtr[1] << " " << newYorkAvenuePtr[2] << "    |                                                                                                                    |    " << pacificAvenuePtr[0] << " " << pacificAvenuePtr[1] << " " << pacificAvenuePtr[2] << "   |" << endl;
	cout << "|   " << newYorkAvenuePtr[3] << " " << newYorkAvenuePtr[4] << " " << newYorkAvenuePtr[5] << "    |                                                                                                                    |    " << pacificAvenuePtr[3] << " " << pacificAvenuePtr[4] << " " << pacificAvenuePtr[5] << "   |" << endl;
	cout << "|    $200    |                                                                                                                    |    $300    |" << endl;
	cout << "--------------                                                                                                                    --------------" << endl;
	cout << "|  Tennessee |                                                                                                                    |    North   |" << endl;
	cout << "|   Avenue   |                                                                                                                    |  Carolina  |" << endl;
	cout << "|            |                                                                                                                    |   Avenue   |" << endl;
	cout << "| " << tennesseeAvenueHouseHotel << " |                                                                                                                    | " << northCarolinaAvenueHouseHotel << " |" << endl;
	cout << "| Owned by: " << tennesseeAvenueOwnerPtr << "|                                                                                                                    | Owned by: " << northCarolinaAvenueOwnerPtr << "|" << endl;
	cout << "|   " << tennesseeAvenuePtr[0] << " " << tennesseeAvenuePtr[1] << " " << tennesseeAvenuePtr[2] << "    |                                                                                                                    |   " << northCarolinaAvenuePtr[0] << " " << northCarolinaAvenuePtr[1] << " " << northCarolinaAvenuePtr[2] << "    |" << endl;
	cout << "|   " << tennesseeAvenuePtr[3] << " " << tennesseeAvenuePtr[4] << " " << tennesseeAvenuePtr[5] << "    |                                                                                                                    |   " << northCarolinaAvenuePtr[3] << " " << northCarolinaAvenuePtr[4] << " " << northCarolinaAvenuePtr[5] << "    |" << endl;
	cout << "|    $180    |                                                                                                                    |    $300    |" << endl;
	cout << "--------------                                                                                                                    --------------" << endl;
	cout << "|  Community |                                                                                                                    | Community  |" << endl;
	cout << "|   Chest    |                                                                                                                    |   Chest    |" << endl;
	cout << "|            |                                                                                                                    |            |" << endl;
	cout << "|            |                                                                                                                    |            |" << endl;
	cout << "|            |                                                                                                                    |            |" << endl;
	cout << "|   " << communityChest2Ptr[0] << " " << communityChest2Ptr[1] << " " << communityChest2Ptr[2] << "    |                                                                                                                    |   " << communityChest3Ptr[0] << " " << communityChest3Ptr[1] << " " << communityChest3Ptr[2] << "    |" << endl;
	cout << "|   " << communityChest2Ptr[3] << " " << communityChest2Ptr[4] << " " << communityChest2Ptr[5] << "    |                                                                                                                    |   " << communityChest3Ptr[3] << " " << communityChest3Ptr[4] << " " << communityChest3Ptr[5] << "    |" << endl;
	cout << "|            |                                                                                                                    |            |" << endl;
	cout << "--------------                                                                                                                    --------------" << endl;
	cout << "|  St. James |                                                                                                                    |Pennsylvania|" << endl;
	cout << "|    PLace   |                                                                                                                    |    Avenue  |" << endl;
	cout << "|            |                                                                                                                    |            |" << endl;
	cout << "| " << stJamesAvenueHouseHotel << " |                                                                                                                    | " << pennsylvaniaAvenueHouseHotel << " |" << endl;
	cout << "| Owned by: " << stJamesAvenueOwnerPtr << "|                                                                                                                    | Owned by: " << pennsylvaniaAvenueOwnerPtr << "|" << endl;
	cout << "|   " << stJamesAvenuePtr[0] << " " << stJamesAvenuePtr[1] << " " << stJamesAvenuePtr[2] << "    |                                                                                                                    |   " << pennsylvaniaAvenuePtr[0] << " " << pennsylvaniaAvenuePtr[1] << " " << pennsylvaniaAvenuePtr[2] << "    |" << endl;
	cout << "|   " << stJamesAvenuePtr[3] << " " << stJamesAvenuePtr[4] << " " << stJamesAvenuePtr[5] << "    |                                                                                                                    |   " << pennsylvaniaAvenuePtr[3] << " " << pennsylvaniaAvenuePtr[4] << " " << pennsylvaniaAvenuePtr[5] << "    |" << endl;
	cout << "|    $180    |                                                                                                                    |    $320    |" << endl;
	cout << "--------------                                                                                                                    --------------" << endl;
	cout << "|Pennsylvania|                                                                                                                    |    Short   |" << endl;
	cout << "|  Railroad  |                                                                                                                    |    Line    |" << endl;
	cout << "|            |                                                                                                                    |            |" << endl;
	cout << "|            |                                                                                                                    |            |" << endl;
	cout << "| Owned by: " << pennsylvaniaRailroadOwnerPtr << "|                                                                                                                    | Owned by: " << shortLineOwnerPtr << "|" << endl;
	cout << "|   " << pennsylvaniaRailroadPtr[0] << " " << pennsylvaniaRailroadPtr[1] << " " << pennsylvaniaRailroadPtr[2] << "    |                                                                                                                    |   " << shortLinePtr[0] << " " << shortLinePtr[1] << " " << shortLinePtr[2] << "    |" << endl;
	cout << "|   " << pennsylvaniaRailroadPtr[3] << " " << pennsylvaniaRailroadPtr[4] << " " << pennsylvaniaRailroadPtr[5] << "    |                                                                                                                    |   " << shortLinePtr[3] << " " << shortLinePtr[4] << " " << shortLinePtr[5] << "    |" << endl;
	cout << "|    $200    |                                                                                                                    |    $200    |" << endl;
	cout << "--------------                                                                                                                    --------------" << endl;
	cout << "|  Virginia  |                                                                                                                    |   Chance   |" << endl;
	cout << "|   Avenue   |                                                                                                                    |            |" << endl;
	cout << "|            |                                                                                                                    |            |" << endl;
	cout << "| " << virgniaAvenueHouseHotel << " |                                                                                                                    |            |" << endl;
	cout << "| Owned by: " << virgniaAvenueOwnerPtr << "|                                                                                                                    |            |" << endl;
	cout << "|   " << virgniaAvenuePtr[0] << " " << virgniaAvenuePtr[1] << " " << virgniaAvenuePtr[2] << "    |                                                                                                                    |   " << chance3Ptr[0] << " " << chance3Ptr[1] << " " << chance3Ptr[2] << "    |" << endl;
	cout << "|   " << virgniaAvenuePtr[3] << " " << virgniaAvenuePtr[4] << " " << virgniaAvenuePtr[5] << "    |                                                                                                                    |   " << chance3Ptr[3] << " " << chance3Ptr[4] << " " << chance3Ptr[5] << "    |" << endl;
	cout << "|    $160    |                                                                                                                    |            |" << endl;
	cout << "--------------                                                                                                                    --------------" << endl;
	cout << "|   States   |                                                                                                                    |    Park    |" << endl;
	cout << "|   Avenue   |                                                                                                                    |    Place   |" << endl;
	cout << "|            |                                                                                                                    |            |" << endl;
	cout << "| " << statesAvenueHouseHotel << " |                                                                                                                    | " << parkPlaceHouseHotel << " |" << endl;
	cout << "| Owned by: " << statesAvenueOwnerPtr << "|                                                                                                                    | Owned by: " << parkPlaceOwnerPtr << "|" << endl;
	cout << "|   " << statesAvenuePtr[0] << " " << statesAvenuePtr[1] << " " << statesAvenuePtr[2] << "    |                                                                                                                    |   " << parkPlacePtr[0] << " " << parkPlacePtr[1] << " " << parkPlacePtr[2] << "    |" << endl;
	cout << "|   " << statesAvenuePtr[3] << " " << statesAvenuePtr[4] << " " << statesAvenuePtr[5] << "    |                                                                                                                    |   " << parkPlacePtr[3] << " " << parkPlacePtr[4] << " " << parkPlacePtr[5] << "    |" << endl;
	cout << "|    $140    |                                                                                                                    |    $350    |" << endl;
	cout << "--------------                                                                                                                    --------------" << endl;
	cout << "|  Electric  |                                                                                                                    |   Luxury   |" << endl;
	cout << "|  Company   |                                                                                                                    |     Tax    |" << endl;
	cout << "|            |                                                                                                                    |            |" << endl;
	cout << "|            |                                                                                                                    |            |" << endl;
	cout << "| Owned by: " << electricCompanyOwnerPtr << "|                                                                                                                    |            |" << endl;
	cout << "|   " << electricCompanyPtr[0] << " " << electricCompanyPtr[1] << " " << electricCompanyPtr[2] << "    |                                                                                                                    |   " << luxuryTaxPtr[0] << " " << luxuryTaxPtr[1] << " " << luxuryTaxPtr[2] << "    |" << endl;
	cout << "|   " << electricCompanyPtr[3] << " " << electricCompanyPtr[4] << " " << electricCompanyPtr[5] << "    |                                                                                                                    |   " << luxuryTaxPtr[3] << " " << luxuryTaxPtr[4] << " " << luxuryTaxPtr[5] << "    |" << endl;
	cout << "|    $150    |                                                                                                                    |  Pay  $100 |" << endl;
	cout << "--------------                                                                                                                    --------------" << endl;
	cout << "|St. Charles |                                                                                                                    | Boardwalk  |" << endl;
	cout << "|   Place    |                                                                                                                    |            |" << endl;
	cout << "|            |                                                                                                                    |            |" << endl;
	cout << "| " << stCharlesPlaceHouseHotel << " |                                                                                                                    | " << boardwalkHouseHotel << " |" << endl;
	cout << "| Owned by: " << stCharlesPlaceOwnerPtr << "|                                                                                                                    | Owned by: " << boardwalkOwnerPtr << "|" << endl;
	cout << "|   " << stCharlesPlacePtr[0] << " " << stCharlesPlacePtr[1] << " " << stCharlesPlacePtr[2] << "    |                                                                                                                    |   " << boardwalkPtr[0] << " " << boardwalkPtr[1] << " " << boardwalkPtr[2] << "    |" << endl;
	cout << "|   " << stCharlesPlacePtr[3] << " " << stCharlesPlacePtr[4] << " " << stCharlesPlacePtr[5] << "    |                                                                                                                    |   " << boardwalkPtr[3] << " " << boardwalkPtr[4] << " " << boardwalkPtr[5] << "    |" << endl;
	cout << "|    $140    |                                                                                                                    |    $400    |" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|  In Jail   |Connecticut |  Vermont   |   Chance   |  Oriental  |  Reading   |   Income   |   Baltic   |  Community |  Mediter-  |  Collect   |" << endl;
	cout << "|  " << inJailPtr[0] << " " << inJailPtr[1] << " " << inJailPtr[2] << "     |   Avenue   |   Avenue   |            |   Avenue   |  Railroad  |    Tax     |   Avenue   |    Chest   |  ranean    |  $200 as   |" << endl;
	cout << "|  " << inJailPtr[3] << " " << inJailPtr[4] << " " << inJailPtr[5] << "     |            |            |            |            |            |            |            |            |  Avenue    | you pass Go| " << endl;
	cout << "|            | " << connecticutAvenueHouseHotel <<" | " << vermontAvenueHouseHotel << " |            | " << orientalAvenueHouseHotel << " |            |            | " << balticAvenueHouseHotel << " |            | " << mediterraneanAvenueHouseHotel << " |            |" << endl;
	cout << "|   Just     | Owned by: " << connecticutAvenueOwnerPtr << "| Owned by: " << vermontAvenueOwnerPtr << "|            | Owned by: " << orientalAvenueOwnerPtr << "| Owned by: " << readingRailroadOwnerPtr << "|            | Owned by: " << balticAvenueOwnerPtr << "|            | Owned by: " << mediterraneanAvenueOwnerPtr << "|            |" << endl;
	cout << "|  Visiting  |   " << connecticutAvenuePtr[0] << " " << connecticutAvenuePtr[1] << " " << connecticutAvenuePtr[2] << "    |   " << vermontAvenuePtr[0] << " " << vermontAvenuePtr[1] << " " << vermontAvenuePtr[2] << "    |   " << chance1Ptr[0] << " " << chance1Ptr[1] << " " << chance1Ptr[2] << "    |   " << orientalAvenuePtr[0] << " " << orientalAvenuePtr[1] << " " << orientalAvenuePtr[2] << "    |   " << readingRailroadPtr[0] << " " << readingRailroadPtr[1] << " " << readingRailroadPtr[2] << "    |   " << incomeTaxPtr[0] << " " << incomeTaxPtr[1] << " " << incomeTaxPtr[2] << "    |   " << balticAvenuePtr[0] << " " << balticAvenuePtr[1] << " " << balticAvenuePtr[2] << "    |    " << communityChest1Ptr[0] << " " << communityChest1Ptr[1] << " " << communityChest1Ptr[2] << "   |   " << mediterraneanAvenuePtr[0] << " " << mediterraneanAvenuePtr[1] << " " << mediterraneanAvenuePtr[2] << "    |   " << goPtr[0] << " " << goPtr[1] << " " << goPtr[2] << "    |" << endl;
	cout << "|  " << justVisitingPtr[0] << " " << justVisitingPtr[1] << " " << justVisitingPtr[2] << "     |   " << connecticutAvenuePtr[3] << " " << connecticutAvenuePtr[4] << " " << connecticutAvenuePtr[5] << "    |   " << vermontAvenuePtr[3] << " " << vermontAvenuePtr[4] << " " << vermontAvenuePtr[5] << "    |    " << chance1Ptr[3] << " " << chance1Ptr[4] << " " << chance1Ptr[5] << "   |    " << orientalAvenuePtr[3] << " " << orientalAvenuePtr[4] << " " << orientalAvenuePtr[5] << "   |    " << readingRailroadPtr[3] << " " << readingRailroadPtr[4] << " " << readingRailroadPtr[5] << "   |   " << incomeTaxPtr[3] << " " << incomeTaxPtr[4] << " " << incomeTaxPtr[5] << "    |    " << balticAvenuePtr[3] << " " << balticAvenuePtr[4] << " " << balticAvenuePtr[5] << "   |   " << communityChest1Ptr[3] << " " << communityChest1Ptr[4] << " " << communityChest1Ptr[5] << "    |   " << mediterraneanAvenuePtr[3] << " " << mediterraneanAvenuePtr[4] << " " << mediterraneanAvenuePtr[5] << "    |   " << goPtr[3] << " " << goPtr[4] << " " << goPtr[5] << "    |" << endl;
	cout << "|  " << justVisitingPtr[3] << " " << justVisitingPtr[4] << " " << justVisitingPtr[5] << "     |    $120    |    $100    |            |    $100    |    $200    |  Pay  $200 |    $60     |            |    $60     |            |" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}




