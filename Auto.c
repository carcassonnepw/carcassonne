#include "Auto.h"

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
	int lastdex=0, n;
	struct fourpos tempos;

	placetile(1, 15, 15);
	Lplaced.x = 15;
	Lplaced.y = 15;
	for (n = 0; n < 31; n++)
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

			//getting next tile


	}

}