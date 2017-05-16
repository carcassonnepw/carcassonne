#include "Auto.h"
#include "structures.h"
#include "gridmanager.h"
#include "tilemanager.h"
#include "LookFor.h"
#include <math.h>
#include <time.h>

struct pos {
	int x;
	int y;
};
struct fourpos {
	struct pos a;
	struct pos b;
	struct pos c;
	struct pos d;
};

struct fourpos getneighb(int x, int y)
{
	struct fourpos solution = { 0 };
	if (tiles[tilesongrid[grid[x][y+1]].ID].availability == 0)
	{
		solution.d.x = x;
		solution.d.y = y + 1;
	}
	if (tiles[tilesongrid[grid[x][y - 1]].ID].availability == 0)
	{
		solution.b.x = x;
		solution.b.y = y - 1;
	}
	if (tiles[tilesongrid[grid[x + 1][y]].ID].availability == 0)
	{
		solution.a.x = x + 1;
		solution.a.y = y;
	}
	if (tiles[tilesongrid[grid[x - 1][y]].ID].availability == 0)
	{
		solution.c.x = x - 1;
		solution.c.y = y;
	}
	return solution;
}


void Placer()
{
	srand((int)time(NULL));
	struct pos neigh[120], Lplaced, closest[30];
	int lastdex = 0, n, nextplac = 1, m, skip = 0, index=0, random, zaje=0, debug, numpl=0;
	struct fourpos tempos;
	char triangles[5];
	struct twoints ajd;
	float dist, mini=0.9;
	//-----------------------------------

	placetile(0, 15, 15);
	Lplaced.x = 15;
	Lplaced.y = 15;
	for (m = 0; m < 30; m++)
	{
		printf("____________________________________________________________________________\n");
		if (skip == 0)
		{
			tempos = getneighb(Lplaced.x, Lplaced.y);
			neigh[lastdex] = tempos.a;
			lastdex++;
			neigh[lastdex] = tempos.b;
			lastdex++;
			neigh[lastdex] = tempos.c;
			lastdex++;
			neigh[lastdex] = tempos.d;
			lastdex++;
		}


		index = 0;
		dist = 30000.0;
			for (n = 0; n < lastdex; n++)
			{
				if (numpl > 4+mini)
				{
					mini += 0.5;
					numpl = 0;
				}
				printf("neigh:_%d.%d_", neigh[n].x, neigh[n].y);
				if ((dist > (sqrt(pow(abs(15-neigh[n].x), 2)+pow(abs(15-neigh[n].y), 2))))&& (mini < (sqrt(pow(abs(15 - neigh[n].x), 2) + pow(abs(15 - neigh[n].y), 2)))) && (tilesongrid[grid[neigh[n].x][neigh[n].y]].ID <1))
				{
					dist = (float)(sqrt(pow(abs(15 - neigh[n].x), 2) + pow(abs(15 - neigh[n].y), 2)));
					debug = n;
				}
				else
				{
					
				}
			}
			printf("\ndist:%lf\nclosest:",dist);
			//looking for all closest
			for (n = 0; n < lastdex; n++)
			{
				if ((dist+0.2 >(sqrt(pow(15 - neigh[n].x, 2) + pow(15 - neigh[n].y, 2))))&&(grid[neigh[n].x][neigh[n].y])<1)
				{
					printf("_%d.%d_", closest[index].x, closest[index].y);
					closest[index].x = neigh[n].x;
					closest[index].y = neigh[n].y;
					index++;

				}
				else
				{
					
				}
			}
			printf("\ndist:%lf___%d\n", (sqrt(pow(abs(15 - neigh[debug].x), 2) + pow(abs(15 - neigh[debug].y), 2))), neigh[debug].x);
			if (index == 0) return (0);
			if (index == 1)
			{
				nextplac = 0;
				printf("\n");
			}
			else
			{
				random = rand() % (index);
				nextplac = random;
			}
			printf("rand:%d,%d------\n", random, index);
			//--------------------------------------------end of chosing next

			if (nextplac > lastdex+1)
			{
			//	return 0;
			}
			else
			{

			}
			tempos=getneighb(closest[nextplac].x, closest[nextplac].y);
			
			
			if (grid[tempos.a.x][tempos.a.y] != 0) triangles[0] = tiles[tilesongrid[grid[tempos.a.x][tempos.a.y]].ID].right;
			else triangles[0] = 'z';
			if (grid[tempos.b.x][tempos.b.y] != 0) triangles[1] = tiles[tilesongrid[grid[tempos.b.x][tempos.b.y]].ID].left;
			else triangles[1] = 'z';
			if (grid[tempos.c.x][tempos.c.y] != 0) triangles[2] = tiles[tilesongrid[grid[tempos.c.x][tempos.c.y]].ID].bottom;
			else triangles[2] = 'z';
			if (grid[tempos.d.x][tempos.d.y] != 0) triangles[3] = tiles[tilesongrid[grid[tempos.d.x][tempos.d.y]].ID].top;	
			else triangles[3] = 'z';

			printf("triangl:%s\n", triangles);

			ajd = FindTile(triangles);

			printf("placed:%c%c%c%c%d%d\n", tiles[ajd.a].top, tiles[ajd.a].right, tiles[ajd.a].bottom, tiles[ajd.a].left, closest[nextplac].x, closest[nextplac].y);
			if (tiles[ajd.a].availability == 1)
			{
				//printf ()
				if (1 == placetile(ajd.a, closest[nextplac].x, closest[nextplac].y))
				{
					printf("placed!\n");
					Lplaced = closest[nextplac];
					skip = 0;
					numpl++;
					rotation(ajd.a, ajd.b+2);
				//	printf("---%c%c%c%c\n", tiles[ajd.a].top, tiles[ajd.a].right, tiles[ajd.a].bottom, tiles[ajd.a].left);
				}
				else
				{


					for (n = 0; n < (lastdex); n++)
					{
					printf("%d_",n);
						if ((neigh[n].x == closest[nextplac].x)&& (neigh[n].y == closest[nextplac].y))
						{
							printf("remove:%d\n", n);
							neigh[n].x = 9999;
						}
					}
					skip = 1;
					zaje++;
					//m--;

				}
			}
			else printf("unavailable");

	}
	//round 2..............................fight
	if (showavailable > 0) printf("jeszcze");
	printf("\n");
}
