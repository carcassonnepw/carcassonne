#ifndef GRIDMANAGER_H
#define GRIDMANAGER_H
#define GRIDSIZE 30
extern int grid[GRIDSIZE][GRIDSIZE];
extern int gids; 

int checkisempty(int x, int y);
int placetile(int id, int x, int y);
void showgrid(int grid[30][30], int cut, int tnj);
int roadcountersimplest();
void showtilesongrid();
void filegrid(int grid[GRIDSIZE][GRIDSIZE], char filename[]);
void fullroad(int GID,int RID,int i,int cont, int starter, char side);
int countroads();
int cango(int GID, char direction);
#endif
