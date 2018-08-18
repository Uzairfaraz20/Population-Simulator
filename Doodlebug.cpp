#include "Doodlebug.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Ant.h"

Doodlebug::Doodlebug()
{
	daysStarved = 0;
	daysSinceBreeding = 0;
	alreadyMoved = false;
}

void Doodlebug::hunt(Creature*** gridArray, int r, int c, GridDisplay gd) {
	if ((c > 0) && (gridArray[r][ c - 1]->getSymbol() == 'a')) {
		gridArray[r][c - 1] = this;
		gridArray[r][c]= new Creature();
		gd.setChar(r, c - 1, getSymbol());
		gd.setChar(r, c, gridArray[r][c]->getSymbol());
		setMove(true);
		daysStarved = 0;
		return;
	}
	else if((c<19) && (gridArray[r][c + 1]->getSymbol() == 'a')) {
		gridArray[r][c + 1] = this;
		gridArray[r][c]= new Creature();
		gd.setChar(r, c + 1, getSymbol());
		gd.setChar(r, c, gridArray[r][c]->getSymbol());
		setMove(true);
		daysStarved = 0;
		return;
	} else if ((r > 0) && (gridArray[r-1][c]->getSymbol() == 'a')) {
		gridArray[r-1][c] = this;
		gridArray[r][c]= new Creature();
		gd.setChar(r - 1, c, getSymbol());
		gd.setChar(r, c, gridArray[r][c]->getSymbol());
		setMove(true);
		daysStarved = 0;
		return;
	} else if ((r <19) && (gridArray[r+1][c]->getSymbol() == 'a')) {
		gridArray[r + 1][c] = this;
		gridArray[r][c]= new Creature();
		gd.setChar(r + 1, c, getSymbol());
		gd.setChar(r, c, gridArray[r][c]->getSymbol());
		setMove(true);
		daysStarved = 0;
		return;
	}
	move(gridArray, r, c, gd);
	daysStarved++;
}

bool Doodlebug::starve() {
	if (daysStarved >= 3) {
		return true;
	} 
	return false;
}

void Doodlebug::spawn(Creature*** gridArray,int r, int c, GridDisplay gd) {
	daysSinceBreeding++;
	if (daysSinceBreeding >= 8) {
		if ((c > 0) && (gridArray[r] [c - 1]->getSymbol() == '-')) {
			daysSinceBreeding = 0;
			gridArray[r][c - 1] = new Doodlebug();
			gd.setChar(r, c - 1, gridArray[r][c - 1]->getSymbol());
			return;
		}
		else if ((c<19) && (gridArray[r][c + 1]->getSymbol() == '-')) {
			daysSinceBreeding = 0;
			gridArray[r][c + 1] = new Doodlebug();
			gd.setChar(r, c + 1, gridArray[r][c + 1]->getSymbol());
			return;
		}
		else if ((r > 0) && (gridArray[r-1][c]->getSymbol() == '-')) {
			daysSinceBreeding = 0;
			gridArray[r-1][c] = new Doodlebug();
			gd.setChar(r - 1, c, gridArray[r - 1][c]->getSymbol());
			return;
		}
		else if ((r <19) && (gridArray[r+1][c]->getSymbol() == '-')) {
			daysSinceBreeding = 0;
			gridArray[r+1][c] = new Doodlebug();
			gd.setChar(r + 1, c, gridArray[r + 1][c]->getSymbol());
			return;
		}
	}
}

char Doodlebug::getSymbol()
{
	return 'D';
}

Doodlebug::~Doodlebug()
{
}





