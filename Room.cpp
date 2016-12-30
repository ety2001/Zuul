// Room.cpp

#include "Room.h"
#include <string.h>

Room::Room(char roomDescription[]){
	strcpy(description, roomDescription);
};

char* Room::getDescription(){
	return description;
};

Room* Room::getExit(Direction dir){
	if(exits.count(dir)>0){
		return exits[dir];
	}
	else{
		return NULL;
	}
};

void Room::addExit(Direction dir, Room* room){
	exits[dir] = room;
};

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

void Room::dropItem(Item* item){
	items.push_back(item);
};

vector<Item*> Room::roomItems(){
	return items;
};

map<Direction,Room*> Room::roomExits(){
	return exits;
};
