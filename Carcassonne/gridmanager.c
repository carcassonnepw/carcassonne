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

int placetile(int id, int x, int y)
{

	void filegrid(int grid[GRIDSIZE][GRIDSIZE], int cut, int tnj)//----------------------
{
	int i;
	int j;
	int k;
	//int cut = 0;
	//int tnj = 0;
	FILE *plik;
	plik = fopen("output.txt", "w");
	fprintf(plik, "xy   |");
	for (i = cut; i<GRIDSIZE - tnj; i++) fprintf(plik, "%-*d|", 3, i);
	fprintf(plik, "\n");
	for (k = cut; k < ((GRIDSIZE + 1) * 4) - tnj * 4; k++)fprintf(plik, "*");
	fprintf(plik, "\n");
	for (i = cut; i<GRIDSIZE - tnj; i++)
	{
		fprintf(plik, "%*d* ", 3, i);
		for (j = cut; j<GRIDSIZE - tnj; j++)
		{

			if (grid[i][j] == 0)
			{
				fprintf(plik, "|   ");
			}
			else
			{
				fprintf(plik, "|%-*d", 3, grid[i][j]);
			}

		}
		fprintf(plik, "\n");
		for (k = cut + tnj * 4; k < (GRIDSIZE + 1) * 4; k++)fprintf(plik, "_");
		fprintf(plik, "\n");

	}
}
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
	return 1;
	}
	else
	{
		printf("\n#########ERROR: Tile not available\n");
		return 0;
	}
} 
	else
	{
		printf("\n#########ERROR: Grid is already occupied\n");
		return 0;
	}
	
}

void showgrid(int grid[GRIDSIZE][GRIDSIZE])
{
	int i;
	int j;
	int k;
	int cut = 9;
	int tnj = 9;
	printf("xy   |");
	for(i=cut;i<GRIDSIZE-tnj;i++) printf("%-*d|",3,i);
	 printf("\n");
	 for (k = cut; k < ((GRIDSIZE + 1) * 4) - tnj * 4; k++)printf("*");
	printf("\n");
	for(i=cut;i<GRIDSIZE-tnj;i++)
	{
		printf("%*d* ",3,i);
		for(j=cut;j<GRIDSIZE-tnj;j++)
		{
			
			if (grid[i][j] == 0)
			{
				printf("|   ");
			}
			else
			{
				printf("|%-*d", 3, grid[i][j]);
			}
		
		}
		 printf("\n");
		 for (k = cut+tnj*4; k < (GRIDSIZE + 1) * 4; k++)printf("_");
		 		printf("\n");

	}
}
void showtilesongrid()
{
	int id;
	int i;
	for(i=gids-1;i>0;i--){
	id = tilesongrid[i].ID;
	printf("TILE GID:%d (%d,%d)# %c%c%c%c #\n",tilesongrid[i].GID, tilesongrid[i].x,tilesongrid[i].y,tiles[id].top, tiles[id].right,tiles[id].bottom,tiles[id].left);
}
}
