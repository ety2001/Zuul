// main.cpp
// Program by Elaine Yang 12/29
// Pokemon themed Zuul game

#include <iostream>
#include <vector>
#include <string.h>
#include "Room.h"

using namespace std;

int main() {
	vector<Room*> rooms;
	vector<Item*> bag;
	Room* room;
	Item* item;
	// create rooms
	room = new Room("Twin Leaf Town: a small town with the fresh scent of new leaves in the air. Your own home and your best friend's house are located here.");
	rooms.push_back(room);
	room = new Room("Canalave City: a port city with a distinctly exotic air of foreign culture. Home to Steel Type Gym Leader Byron.");
	rooms.push_back(room);
	room = new Room("Sandgem Town: a sandy town that is located right next to a beach. It is redolent with the salty scent of the sea.");
	rooms.push_back(room);
	room = new Room("Jubilife City: the most modernized city in the Sinnoh region. It is bustling with people on the go.");
	rooms.push_back(room);
	room = new Room("Floaroma Town: a town of flower lovers, always perfumed with the sweet scent of flowers.");
	rooms.push_back(room);
	room = new Room("Oreburgh City: a vibrant and energetic mining town that is blessed with a precious natural resource. Home to Rock Type Gym Leader Roark.");
	rooms.push_back(room);
	room = new Room("Eterna City: an old city that shows fading and almost-forgotten vestiges of ancient history. Home to Grass Type Gym Leader Gardenia.");
	rooms.push_back(room);
	room = new Room("Snowpoint City: a winter wonderland of a city where trees and buildings are blanketed in thick snow. Home to Ice Type Gym Leader Candice.");
	rooms.push_back(room);
	room = new Room("Hearthome City: this friendly city started as a place where people and Pokémon gathered. Home to Ghost Type Gym Leader Fantina.");
	rooms.push_back(room);
	room = new Room("Celestic Town: a tiny town that preserves the history of Sinnoh and the old ways of life.");
	rooms.push_back(room);
	room = new Room("Pastoria City: this city was originally founded to protect the Great Marsh. Home to Water Type Gym Leader Crasher Wake.");
	rooms.push_back(room);
	room = new Room("Solaceon City: the temperate climate makes this town a relaxed and casual place for people and Pokémon to live in.");
	rooms.push_back(room);
	room = new Room("Veilstone City: this city was made by carving out steep, rocky mountains. Home to Fighting Type Gym Leader Maylene");
	rooms.push_back(room);
	room = new Room("Sunyshore City: a port city that was built around the bay portion of the cape. Home to Electric Type Gym Leader Volkner.");
	rooms.push_back(room);
	room = new Room("Pokemon League: trainers seeking to be the best arrive here after a long and grueling journey. Home to the Elite 4.");
	rooms.push_back(room);
	//add exits
	rooms[0]->addExit(North,rooms[1]);
	rooms[0]->addExit(East,rooms[2]);

	rooms[1]->addExit(South,rooms[0]);
	rooms[1]->addExit(East,rooms[3]);

	rooms[2]->addExit(North,rooms[3]);	
	rooms[2]->addExit(West,rooms[0]);

	rooms[3]->addExit(North,rooms[4]);
	rooms[3]->addExit(East,rooms[5]);
	rooms[3]->addExit(South,rooms[2]);
	rooms[3]->addExit(West,rooms[1]);

	rooms[4]->addExit(East,rooms[6]);
	rooms[4]->addExit(South,rooms[3]);

	rooms[5]->addExit(North,rooms[6]);
	rooms[5]->addExit(East,rooms[8]);
	rooms[5]->addExit(West,rooms[3]);
	
	rooms[6]->addExit(North,rooms[7]);
	rooms[6]->addExit(East,rooms[9]);
	rooms[6]->addExit(South,rooms[5]);
	rooms[6]->addExit(West,rooms[4]);
	
	rooms[7]->addExit(South,rooms[6]);
	
	rooms[8]->addExit(North,rooms[9]);
	rooms[8]->addExit(East,rooms[11]);
	rooms[8]->addExit(West,rooms[5]);
	
	rooms[9]->addExit(South,rooms[8]);
	rooms[9]->addExit(West,rooms[6]);
	
	rooms[10]->addExit(North,rooms[11]);
	
	rooms[11]->addExit(East,rooms[12]);
	rooms[11]->addExit(South,rooms[10]);
	rooms[11]->addExit(West,rooms[8]);
	
	rooms[12]->addExit(East,rooms[13]);
	rooms[12]->addExit(West,rooms[11]);
	
	rooms[13]->addExit(North,rooms[14]);
	rooms[13]->addExit(West,rooms[12]);
	
	rooms[14]->addExit(South,rooms[13]);
	
	//add items
	item = new Item("Pokedex");
	rooms[0]->dropItem(item);
	
	item = new Item("Mine Badge");
	rooms[1]->dropItem(item);
	
	item = new Item("Coal Badge");
	rooms[5]->dropItem(item);
	
	item = new Item("Forest Badge");
	rooms[6]->dropItem(item);
	
	item = new Item("Icicle Badge");
	rooms[7]->dropItem(item);
	
	item = new Item("Relic Badge");
	rooms[8]->dropItem(item);
	
	item = new Item("Fen Badge");
	rooms[10]->dropItem(item);
	
	item = new Item("Cobble Badge");
	rooms[12]->dropItem(item);
	
	item = new Item("Beacon Badge");
	rooms[13]->dropItem(item);

	Room* curRoom = rooms[0];	
	char input[50];

	while(1){
		// print current room info
		cout << "You arrive at " << curRoom->getDescription() << endl;
		// print exits
		cout << "There are exits:" << endl;
		map<Direction,Room*> roomExits = curRoom->roomExits();
		for (map<Direction,Room*>::iterator it = roomExits.begin(); it!= roomExits.end(); it++){
			if(it->first == North){
				cout << "NORTH ";
			}
			else if(it->first == East){
				cout << "EAST ";
			}
			else if(it->first == South){
				cout << "SOUTH ";
			}
			else{
				cout << "WEST ";
			}
		}
		cout << endl;
		// check for win lose conditions
		if(curRoom == rooms[14]){
			if(bag.size() == 9){
				cout << "You beat the Elite 4! Congratulations League Champion!" << endl;
			}
			else{
				cout << "All your pokemon fainted. Feels bad man." << endl;
			}
			break;
		}
		// print item(s)
		cout << "There are item(s):" << endl;
		vector<Item*> roomItems = curRoom->roomItems();
		for (int i = 0; i < roomItems.size(); i++){
			cout << roomItems[i]->getName() << " ";
		}
		cout << endl << "You can choose to [DROP] an item, [GRAB] an item, or pick a [DIRECTION] to travel." << endl;
		// take in user input
		cin.getline(input,50);
		// drop an item
		if(strcmp(input, "DROP")==0){
			cout << "You currently have:";
			for (int i = 0; i < bag.size(); i++){
				cout << " " << bag[i]->getName();
			}
			cout << endl << "What item would you like to drop?" << endl;
			cin.getline(input,50);
			int i;
			for (i = 0; i < bag.size(); i++){
				if(strcmp(bag[i]->getName(),input)==0){
					curRoom->dropItem(bag[i]);
					cout << input << " dropped." << endl;
					break;
				}
			}
			if(i == bag.size()){
				cout << "Item is invalid." << endl;
			}
			else{
				bag.erase(bag.begin()+i);
			}
		}
		// grab an item
		else if(strcmp(input, "GRAB")==0){
			cout << "What item would you like to grab?" << endl;
			cin.getline(input,50);
			Item* grabbedItem = curRoom->getItem(input);
			if(grabbedItem == NULL){
				cout << "Item is invalid." << endl;
			}
			else{
				bag.push_back(grabbedItem);
				cout << input << " grabbed." << endl;
			}
		}
		// go north
		else if(strcmp(input, "NORTH")==0){
			Room* destination = curRoom->getExit(North);
			if(destination == NULL){
				cout << "There is no path NORTH." << endl;
			}
			else{
				curRoom = destination;
			}
		}
		// go east
		else if(strcmp(input, "EAST")==0){
			Room* destination = curRoom->getExit(East);
			if(destination == NULL){
				cout << "There is no path EAST." << endl;
			}
			else{
				curRoom = destination;
			}
		}
		// go south
		else if(strcmp(input, "SOUTH")==0){
			Room* destination = curRoom->getExit(South);
			if(destination == NULL){
				cout << "There is no path SOUTH." << endl;
			}
			else{
				curRoom = destination;
			}
		}
		//go west
		else if(strcmp(input, "WEST")==0){
			Room* destination = curRoom->getExit(West);
			if(destination == NULL){
				cout << "There is no path WEST." << endl;
			}
			else{
				curRoom = destination;
			}
		}
		else{
			cout << "Command invalid." << endl;
		}
	}		
}
