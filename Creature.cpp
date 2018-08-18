#include "Creature.h"


#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Creature::Creature()
{
}

void Creature::spawn(Creature*** gridArray, int r, int c, GridDisplay gd) {
	
}

void Creature::move(Creature*** gridArray, int r, int c, GridDisplay gd) {
	srand(time(NULL));
	int pos = rand() % 4;

	if (pos == 0) {
		if ((c > 0) && (gridArray[r][c - 1]->getSymbol() == '-')) {
			gridArray[r][c - 1] = this;
			gridArray[r][c]= new Creature();
			gd.setChar(r, c-1, getSymbol());
			gd.setChar(r, c, gridArray[r][c]->getSymbol());
			setMove(true);
			return;
		}
	}
	else if (pos == 1) {
		if ((c<19) && (gridArray[r][c + 1]->getSymbol() == '-')) {
			gridArray[r][c + 1] = this;
			gridArray[r][c]= new Creature();
			gd.setChar(r, c + 1, getSymbol());
			gd.setChar(r, c, gridArray[r][c]->getSymbol());
			setMove(true);
			return;
		}
	}
	else if (pos == 2) {
		if ((r > 0) && (gridArray[r-1][c]->getSymbol() == '-')) {
			gridArray[r-1][c] = this;
			gridArray[r][c]= new Creature();
			gd.setChar(r-1, c, getSymbol());
			gd.setChar(r, c, gridArray[r][c]->getSymbol());
			setMove(true);
			return;
		}
	}
	else {
		if ((r < 19) && (gridArray[r+1][c]->getSymbol() == '-')) {
			gridArray[r+1][c] = this;
			gridArray[r][c]= new Creature();
			gd.setChar(r+1, c, getSymbol());
			gd.setChar(r, c, gridArray[r][c]->getSymbol());
			setMove(true);
			return;
		}

	}

}

char Creature ::  getSymbol() {
	return '-';
}

bool Creature::hasMoved()
{
	return alreadyMoved;
}


void Creature::setMove(bool val) {
	alreadyMoved = val;
}

void Creature::hunt(Creature*** gridArray, int r, int c, GridDisplay gd)
{
}



bool Creature::starve() {
	return false;
}





Creature::~Creature()
{
}



