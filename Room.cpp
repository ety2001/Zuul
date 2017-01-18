// Room.cpp
// creates rooms, each with a description and possible exits
// can also pick up/drop items into a room

#include "Room.h"
#include <string.h>

// create new room with description
Room::Room(char roomDescription[]){
	strcpy(description, roomDescription);
};

// gets description of a room
char* Room::getDescription(){
	return description;
};

// gets destination of possible exits from a room
Room* Room::getExit(Direction dir){
	if(exits.count(dir)>0){
		return exits[dir];
	}
	else{
		return NULL;
	}
};

// initialize exits from a room
void Room::addExit(Direction dir, Room* room){
	exits[dir] = room;
};

// takes away an item from a room
Item* Room::getItem(char name[]){
	int i;
	for (i=0; i<items.size(); i++){
		if (strcmp(name, items[i]->getName())==0){
			break;
		}
	}
	if(i == items.size()){
		return NULL;
	}
	Item* item = items[i];
	items.erase(items.begin()+i);
	return item;
};

// drops/adds an item to a room
void Room::dropItem(Item* item){
	items.push_back(item);
};

// gets items in a room
vector<Item*> Room::roomItems(){
	return items;
};

// gets directions of exits from a roomm
map<Direction,Room*> Room::roomExits(){
	return exits;
};
