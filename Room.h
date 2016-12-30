// Room.h

#include "Item.h"
#include <vector>
#include <map>

using namespace std;

enum Direction{
	North,
	East,
	South,
	West
};

class Room{
	char description[100];
	vector<Item*> items;
	map<Direction,Room*> exits;
	public:
	Room(char roomDescription[]);
	char* getDescription();
	Room* getExit(Direction dir);
	void addExit(Direction dir, Room* room);
	Item* getItem(char name[]);
	void dropItem(Item* item);
	vector<Item*> roomItems();
	map<Direction,Room*> roomExits();
};
	
