// Item.cpp

#include "Item.h"
#include <string.h>

Item::Item(char itemName[]){
	strcpy(name, itemName);
};

char* Item::getName(){
	return name;
}; 
