#include "Auto.h"
#include "structures.h"
#include "gridmanager.h"
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
	struct fourpos solution;
	solution.a.x = x;
	solution.a.y = y+1;
	solution.b.x = x;
	solution.b.y = y-1;
	solution.c.x = x+1;
	solution.c.y = y;
	solution.d.x = x-1;
	solution.d.y = y;
	return solution;
}


void Placer()
{
	struct pos neigh[120], Lplaced;
	int lastdex = 0, n, nextplac=1, m;
	struct fourpos tempos;
	char triangles[5];
	struct twoints ajd;
	long dist;
	//-----------------------------------

	placetile(0, 15, 15);
	Lplaced.x = 15;
	Lplaced.y = 15;
	for (m = 0; m < 15; m++)
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

			dist = 300000;
			for (n = 0; n < lastdex-1; n++);
			{
				if (dist > sqrt(pow(abs(15-neigh[n].x), 2)+pow(abs(15-neigh[n].y), 2)))
				{
					nextplac = n;
					dist = sqrt(pow(abs(15 - neigh[n].x), 2) + pow(abs(15 - neigh[n].y), 2));
				}
				else
				{
					
				}
			}
			if (nextplac > lastdex+1)
			{
				return 0;
			}
			else
			{

			}
			tempos=getneighb(neigh[nextplac+1].x, neigh[nextplac+1].y);

			triangles[0] = tiles[tilesongrid[grid[tempos.a.x] [tempos.a.y]].ID].left;
			triangles[1] = tiles[tilesongrid[grid[tempos.b.x] [tempos.b.y]].ID].right;
			triangles[2] = tiles[tilesongrid[grid[tempos.c.x] [tempos.c.y]].ID].bottom;
			triangles[3] = tiles[tilesongrid[grid[tempos.d.x] [tempos.d.y]].ID].top;

			printf("triangl:%s %d %d %d\n", triangles, tempos.d.x, tempos.d.y, tempos.b.x);

			ajd = FindTile(triangles);
			rotation(ajd.a, ajd.b);
			if (tiles[ajd.a].availability == 1)
			{
				//printf ()
				placetile(ajd.a, neigh[nextplac].x, neigh[nextplac].y);
			}
			else
			{
			//	printf("%d", ajd.a);
			//	printf("___%s\n", tiles[ajd.a]);
			}

	}
}