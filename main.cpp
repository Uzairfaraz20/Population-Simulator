#include "GridDisplay.h"
#include <stdlib.h>
#include <stdio.h>
#include<sstream>
#include <string.h>
#include "Creature.h"
#include "Doodlebug.h"
#include "Ant.h"
#include <time.h>
#include <math.h>



int getRow(int n) {
	int Num = floor(n / 20.00);
	return Num;
}

int getCol(int n) {
	int row = getRow(n) + 1;

	return 20 - ((row * 20) - n);
}

void markUnvisited(Creature*** gridArray)
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			gridArray[i][j]->setMove(false);
		}
	}
}

void DoodlebugsHunt(Creature*** gridArray, GridDisplay gd)
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (gridArray[i][j]->getSymbol() == 'D') {
				if (gridArray[i][j]->hasMoved() == false) {
					gridArray[i][j]->hunt(gridArray, i, j, gd);
				}
			}
		}
	}
}

void AntsSpawn(Creature*** gridArray, GridDisplay gd)
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (gridArray[i][j]->getSymbol() == 'a') {
				if (gridArray[i][j]->hasMoved() == true) {
					gridArray[i][j]->spawn(gridArray, i, j, gd);
				}
			}
		}
	}
}

void DoodlebugsSpawn(Creature*** gridArray, GridDisplay gd)
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (gridArray[i][j]->getSymbol() == 'D') {
				if (gridArray[i][j]->hasMoved() == true) {
					gridArray[i][j]->spawn(gridArray, i, j, gd);
				}
			}
		}
	}
}


void AntsMove(Creature*** gridArray, GridDisplay gd)
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (gridArray[i][j]->getSymbol() == 'a') {
				if (gridArray[i][j]->hasMoved() == false) {
					gridArray[i][j]->move(gridArray, i, j, gd);
				}
			}

		}
	}
}

void populateAnts(Creature*** gridArray,GridDisplay gd)
{
	for (int y = 0; y < 100; y++) {
		while (true) {
			int aIndex = rand() % 400;
			int row = getRow(aIndex);
			int column = getCol(aIndex);
			if (gridArray[row][column]->getSymbol() == '-') {
				gridArray[row][column] = new Ant();
				gd.setChar(row, column, gridArray[row][column]->getSymbol());
				break;
			}
		}
	}
}

void populateDoodlebugs(Creature*** gridArray, GridDisplay gd)
{

	for (int x = 0; x < 5; x++) {
		while (true) {
			int dIndex = rand() % 400;
			int row = getRow(dIndex);
			int column = getCol(dIndex);
			if (gridArray[row][column]->getSymbol() == '-') {
				gridArray[row][column] = new Doodlebug();
				gd.setChar(row, column, gridArray[row][column]->getSymbol());
				break;
			}
		}
	}

}

void DoodlebugsStarve(Creature*** gridArray, GridDisplay gd)
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {

			if (gridArray[i][j]->getSymbol() == 'D') {
				if (gridArray[i][j]->starve() == true) {
					gridArray[i][j] = new Creature();
					gd.setChar(i, j, gridArray[i][j]->getSymbol());

				}
			}
		}
	}
}


void initialize(Creature*** gridArray, GridDisplay gd)
{
	for (int r = 0; r < 20; r++) {
		for (int c = 0; c < 20; c++) {
			gridArray[r][c] = new Creature();
			gd.setChar(r, c, gridArray[r][c]->getSymbol());
		}
	}
	srand(time(NULL));
	populateAnts(gridArray,gd);
	populateDoodlebugs(gridArray,gd);
}

void dayAcivityAtAntHill(Creature*** gridArray, GridDisplay gd)
{
	markUnvisited(gridArray);
	DoodlebugsHunt(gridArray, gd);
	AntsMove(gridArray, gd);
	DoodlebugsStarve(gridArray, gd);
	DoodlebugsSpawn(gridArray, gd);
	AntsSpawn(gridArray, gd);

	gd.showGrid();
}



void sleepTimeAtAnHill(int ms,GridDisplay gd)
{
	gd.mySleep(ms);
}



int main(int argc, char** argv)
{

	int sleepMS = 1000;
	GridDisplay gd;

	Creature ***grid = new Creature**[20];
	for (int r = 0; r < 20; r++) {
		grid[r] = new Creature*[20];
	}

	if (argc == 2 || argc > 3) {
		printf("Invalid Number of Arguments.\n Valid Syntax:\n No Arguments\n <-d> <MilliSeconds>\n %s",argv[1]);
		return 1;
	}
	if (argc == 3) {
		if (strcmp(argv[1], "-d") != 0) {
			printf("Invalid value, expected -d as 1st argument.\n Valid Syntax:\n No Arguments\n <-d> <MilliSeconds>\n");
			return 1;

		}
		else {
			
				if (! isdigit(*argv[2])) {
					
					printf("Expected Number. Invalid input: %s\n Valid Syntax:\n No Arguments\n <-d> <MilliSeconds>\n", argv[2]);
					return 1;
				}
				sleepMS = atoi(argv[2]);
			
		}
	}
	
	initialize(grid,gd);
	gd.showGrid();
	sleepTimeAtAnHill(sleepMS, gd);

	while (true){
	dayAcivityAtAntHill(grid, gd);
	sleepTimeAtAnHill(sleepMS,gd);
}

	for (int r = 0; r < 20; r++) {
		delete grid[r];
	}
	delete grid;

 return 1;
}


    