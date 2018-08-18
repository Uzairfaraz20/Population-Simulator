#ifndef ANT_H
#define ANT_H
#include "Creature.h"

class Ant : public Creature
{
public:
    Ant();
    ~Ant();
	void spawn(Creature*** gridArray, int r, int c, GridDisplay gd);// override;
	 void move();
	 char getSymbol();// override;

};

#endif // ANT_H


