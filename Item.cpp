// Item.cpp
// implementation of the item class, creates new items and gets names of existing

#include "Item.h"
#include <string.h>

// create new item with given name
Item::Item(char itemName[]){
	strcpy(name, itemName);
};

// get name of an item
char* Item::getName(){
	return name;
}; 
