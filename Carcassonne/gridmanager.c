#include <stdio.h>
#include "structures.h"
#include "gridmanager.h"
int gids=1;
int grid[GRIDSIZE][GRIDSIZE];
int checkisempty(int x, int y)
{
	if(grid[x][y]==0)
	return 1; else return 0;
}
void placetile(int id, int x, int y)
{
	
	if(checkisempty(x,y)==1)
	{
	
	if(tiles[id].availability==1)
	{
	
	tilesongrid[gids].GID = gids;
	tilesongrid[gids].ID =id;
	tilesongrid[gids].x = x;
	tilesongrid[gids].y =y;
	tiles[id].availability =0;
	grid[x][y]=gids;
	gids++;
    } else printf("\n#########ERROR: Tile not available\n");
} else  printf("\n#########ERROR: Grid is already occupied\n");
	
}
void showgrid(int grid[GRIDSIZE][GRIDSIZE])
{
	int i;
	int j;
	int k;
	printf("xy|   ");
	for(i=0;i<GRIDSIZE;i++) printf("%-*d|",3,i);
	 printf("\n");
		 		for(k=0;k<(GRIDSIZE+1)*4;k++)printf("*");
	printf("\n");
	for(i=0;i<GRIDSIZE;i++)
	{
		printf("%*d* ",3,i);
		for(j=0;j<GRIDSIZE;j++)
		{
			
						
			printf("|%-*d",3,grid[i][j]);
		
		}
		 printf("\n");
		 		for(k=0;k<(GRIDSIZE+2)*4;k++)printf("_");
		 		printf("\n");

	}
}