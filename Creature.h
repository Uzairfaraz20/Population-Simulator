#ifndef CREATURE_H
#define CREATURE_H
#include "GridDisplay.h"

class Creature
{

protected:
	//int x,y; //position
	bool alreadyMoved; //did it move already?
	int daysSinceBreeding; // number of days since breeding;
	
public:
    Creature();
    ~Creature();
	 virtual void spawn(Creature*** gridArray, int r, int c, GridDisplay gd);
	 
	 virtual char getSymbol();
	 bool hasMoved();
	 void setMove(bool val);
	 virtual void hunt(Creature*** gridArray, int r, int c, GridDisplay gd);
	 void move(Creature*** gridArray, int r, int c, GridDisplay gd);
	 virtual bool starve();

};

#endif // CREATURE_H


