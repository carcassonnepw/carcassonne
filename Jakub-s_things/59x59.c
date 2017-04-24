
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct tile
{
	int ID;
	char top, right, bottom, left;
	int isShield;
	int isTemple;
	int isCity;
	int isCrossroad;


};

int NextFree(int *table)
{
	int n;
	for (n = 0; n < 62; n++)
	{
		if (table+n >0)
		{

		}
		else
		{
			return n;
		}
	}
}



int main() {
	char input[30][5] = { "RPRP0","PPRR0","PRRR0","PCCP0","CPPP0","CRRP0","RCPR0","RCRR0","RRRR0","PCPC0","RCRP0","CSCC0","PPRPT","PPPPT","RPRP0","PPRR0","PRRR0","PCP?0","CPPP0","CRRP0","RCPR0","RCRR0","RRRR0","PCPC0","RCRP0","CSCC0","PPRPT","PPPPT","RCRP0","CSCC0" };
	int neighbours[62];
	char temp[6];
	int n, m, rng=0, now, index, MaIn;
	char board[3481][5] = { 0 };
	for (m = 0; m < 5; m++)
	{
		board[1681][m] = input[1][m];
	}
	now = 1681;

	for (n = 1; n < 30; n++)
	{
		index = (NextFree (&neighbours[0]));
		neighbours[index] = now + 59;
		index = (NextFree(&neighbours[0]));
		neighbours[index] = now + 1;
		index = (NextFree(&neighbours[0]));
		neighbours[index] = now - 59;
		index = (NextFree(&neighbours[0]));
		neighbours[index] = now - 1;
		MaIn = index;
		for (m = 0; m < 5; m++)
		{
			board[rng][m] = input[n][m];
		}
	}



	//-----------------------------printing
	m = 0;
	for (n = 0; n < 3481; n++)

	{
		if (m == 59)
		{
			printf("\n\n");
			m = 0;
		}
		else
		{

		}
		if (board[n][0] =='R'|| board[n][0] == 'P' || board[n][0] == 'C' )
			{
				printf("%s", &board[n]);
			}
		else
			{
				if (m == 59)
				{
					printf("-----");
				}
				else
				{
					printf("----_");
				}
			}
		m++;
	}
	printf("\n");
}
