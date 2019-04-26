#pragma once
using namespace std;

class entity
{
	//This is the class for all entities in the game
public:
	int x, y; //The x and y coordinates of the entity
	int px, py; //The PREVIOUS x and y coordinates of the entity
	//These variables are public since they are changed constantly
};

//end.