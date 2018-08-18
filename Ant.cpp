#include "Ant.h"
#include "Creature.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


Ant::Ant()
{
	daysSinceBreeding = 0;
	alreadyMoved = false;
}

void Ant::spawn(Creature*** gridArray, int r, int c, GridDisplay gd) {
	daysSinceBreeding++;

	if (daysSinceBreeding == 3) {
		daysSinceBreeding = 0;
		if ((c > 0) && (gridArray[r][c - 1]->getSymbol() == '-')) {
			
			gridArray[r][c-1] = new Ant();
			gd.setChar(r, c - 1, gridArray[r][c - 1]->getSymbol());
			return;
		}
		else if ((c<19) && (gridArray[r][c + 1]->getSymbol() == '-')) {
			
			gridArray[r][c + 1] = new Ant();
			gd.setChar(r, c + 1, gridArray[r][c + 1]->getSymbol());
			return;
		}
		else if ((r > 0) && (gridArray[r-1][c]->getSymbol() == '-')) {
			
			gridArray[r-1][c] = new Ant();
			gd.setChar(r - 1, c, gridArray[r - 1][c]->getSymbol());
			return;
		}
		else if ((r <19) && (gridArray[r+1][c]->getSymbol() == '-')) {
			
			gridArray[r+1][c] = new Ant();
			gd.setChar(r + 1, c, gridArray[r + 1][c]->getSymbol());
			return;
		}
	}
}

void Ant :: move() {

}

char Ant::getSymbol()
{
	return 'a';
}

Ant::~Ant()
{
}



