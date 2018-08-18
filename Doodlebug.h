#ifndef DOODLEBUG_H
#define DOODLEBUG_H
#include "Creature.h"



class Doodlebug : public Creature
{
protected:
	int daysStarved; //Number of days without eating
	

public:
    Doodlebug();
    ~Doodlebug();
	void hunt(Creature*** gridArray, int r, int c, GridDisplay gd);// override;
	bool starve(); //override;
	 
	void spawn(Creature*** gridArray, int r, int c, GridDisplay gd);// override;
	char getSymbol(); //override;
	

};

#endif // DOODLEBUG_H


