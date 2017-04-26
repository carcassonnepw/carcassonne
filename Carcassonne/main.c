#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "iomanage.h"
#include "tilemanager.h"
#include "gridmanager.h"
//extern int grid[GRIDSIZE][GRIDSIZE];
 void fillrand()
 {
 	int i;
 	for(i=0;i<TILECOUNT;i++)
    {
    	placetile(i,randomator(),randomator());
	}

 }
 int randomator()
{

	int result;
	result = rand() % (GRIDSIZE +1) +0;
	return result;
}

 


int main(int argc, const char * argv[]) {
    char filename[255];
    int i=0;
    int command;
    int stop=0;
   // scanf("%s",filename);
    
    readInput("input.txt");
   // showavailable();
   placetile(0,3,5);
        placetile(2,2,3);
    	    printf("COMMANDS FOR CARCASSONNE:\n 1: SHOW TILES AVAILABLE\n 2: SHOW GRID \n 3: RANDOM FILL GRID\n 99: EXIT\n");
    while(stop==0)
    {
    	   scanf("%d",&command);

    	    printf("COMMANDS FOR CARCASSONNE:\n 1: SHOW TILES AVAILABLE\n 2: SHOW GRID \n 3: RANDOM FILL GRID\n 99: EXIT\n");
      switch(command)
      	{
      		case 1:
      			showavailable();
      			break;
      		case 2:
      			showgrid(grid);
      			rotation(1,2);

      			break;
      		case 3:
			  	fillrand();
			  	break;
			  	case 4:
			  	showtilesongrid();
			  	break;
			case 99:
				stop=1;
				break;
				

		  }
	}
    
    
        

        showavailable();

    getchar();
    return 0;
    
}
