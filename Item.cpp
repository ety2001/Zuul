// Item.cpp

#include "Item.h"
Item::Item(Char itemName){
	strcpy(name, itemName);
};

char Item::getName(){
	return name;
}; 
