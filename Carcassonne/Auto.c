#include "Auto.h"
#include "structures.h"
#include "gridmanager.h"
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

void Delay(int time)
{
	const time_t start = time(NULL);

	time_t current;
	do {
		/* get current time */
		time(&current);

	} while (difftime(current, start) < dly);
}


void Placer()
{
	struct pos neigh[120], Lplaced;
	int lastdex = 0, n, dist, nextplac;
	struct fourpos tempos;
	char triangles[5];
	struct twoints ajd;
	//-----------------------------------

	placetile(1, 15, 15);
	Lplaced.x = 15;
	Lplaced.y = 15;
	for (n = 0; n < 30; n++)
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

			dist = 1000;
			for (n = 0; n < lastdex; n++)
			{
				printf("%d %d\n", neigh[n].x, neigh[n].y);
				if (dist > sqrt(neigh[n].x*neigh[n].x + neigh[n].y*neigh[n].y)) nextplac = n;
			}

			tempos=getneighb(neigh[nextplac].x, neigh[nextplac].y);

			triangles[0] = tiles[tilesongrid[grid[tempos.b.x] [tempos.b.y]].ID].left;
			triangles[1] = tiles[tilesongrid[grid[tempos.b.x] [tempos.b.y]].ID].right;
			triangles[2] = tiles[tilesongrid[grid[tempos.c.x] [tempos.c.y]].ID].bottom;
			triangles[3] = tiles[tilesongrid[grid[tempos.d.x] [tempos.d.y]].ID].top;

			ajd = FindTile(triangles);
			rotation(ajd.a, ajd.b);
			placetile(ajd.a,neigh[nextplac].x, neigh[nextplac].y);

	}
}
