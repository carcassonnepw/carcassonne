#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "iomanage.h"
#include "tilemanager.h"
#include "gridmanager.h"
#include "TileGen.h"
#include "Auto.h"
//extern int grid[GRIDSIZE][GRIDSIZE];

void fillrand() {
    int i;
    for (i = 0; i < TILECOUNT; i++) {
        placetile(i, randomator(), randomator());
    }

}

void manualmode() {
    int id;
    int x;
    int y;
    int rotate;
    printf("ID of tile would you like to place:\n");
    scanf("%d", &id);
    printf("X-coordinate of tile would you like to place:\n");
    scanf("%d", &x);
    printf("Y-coordinate of tile would you like to place:\n");
    scanf("%d", &y);
    printf("Rotation of tile would you like to place:\n");
    scanf("%d", &rotate);
    placetile(id, x, y);
    //   rotation(givegid(id),rotate);
}

void counttest() {
    placetile(1, 0, 0);
    placetile(2, 1, 0);
    placetile(3, 2, 0);
    placetile(4, 2, 1);
    placetile(5, 1, 1);
    placetile(6, 0, 1);
}

int randomator() {

    int result;
    result = rand() % (GRIDSIZE + 1) + 0;
    return result;
}

int main(int argc, const char * argv[]) {

    char filename[255];
    int i = 0;
    
    int command;
    int stop = 0;
    int from = 0;
    int count=0;
    int to = 30;
    // scanf("%s",filename);
    //printf("%d \n",argc);
    if (argc!=3)
    {
        printf("Insufficient arguments");
    }
    else 
    {
    readInput(argv[1]);
    int ix, yg, jd, an; // manual placing variables
    int cut = 0, tnj = 0;
    // showavailable();
    // placetile(0,0,0);
    //    placetile(2,2,3);
    // placetile(0,0,0);
    //  placetile(1,1,0);
    //placetile(2,1,1);
    // placetile(5,3,8);

    // printf("IDD%d\n",givegid(2));
    printf("COMMANDS FOR CARCASSONNE:\n 1: SHOW TILES AVAILABLE\n 2: SHOW GRID \n 3: RANDOM FILL GRID\n 4: SHOW PLACED tILES\n 5: SAVE TO FILE\n 6: COUNT ROADS:\n 10:ROTATE\n 7: Place One Tile \n 8: Generate Tileset\n 99: EXIT\n");

    while (stop == 0) {
        scanf("%d", &command);

        printf("COMMANDS FOR CARCASSONNE:\n 1: SHOW TILES AVAILABLE\n 2: SHOW GRID \n 3: RANDOM FILL GRID\n 4: SHOW PLACED tILES\n 5: SAVE TO FILE\n 6: COUNT ROADS:\n 10:ROTATE\n 7: Place One Tile\n 8: Generate Tileset\n 99: EXIT\n");

        switch (command) {
            case 1:
                showavailable();
                break;
            case 2:
                printf("Enter range of showing(how much to cut from below and from above) seperated by space Ex. '3 5' will result from 3 to 24\n ");
                scanf("%d %d", &from, &to);
                showgrid(grid, from, to);


                break;
            case 3:
                fillrand();
                break;
            case 4:
                showtilesongrid();

                break;
            case 5:
                //counttest();
                filegrid(grid,argv[2]);
                //	manualmode();
                break;
            case 6:
                printf("ROAD POINTS:%d", roadcountersimplest());
                //testers();

                //fullroad(1,1);
                //                                fullroad(1,1,0,0, 0);
                break;
            case 7:
                manualmode();
                break;
            case 8:
                printf("Write numbers of tile to generate and filename\n ");
                scanf ("%d %s",&count, filename);
                tilegen(count,filename);
                break;
            case 9:
                        Placer();
			//showgrid(grid,0,0);
			showtilesongrid();
                        break;
                
                
            case 10:
                printf("\ninput id and angle:\n");
                scanf("%d %d", &jd, &an);
                rotation(jd, an);
                break;
            


            case 99:
                stop = 1;
                break;


        }
    }




    // showavailable();

    getchar();
    return 0;
    }

}
