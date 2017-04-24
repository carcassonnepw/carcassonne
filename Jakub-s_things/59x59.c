
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





int main() {
	char input[30][5] = { "RPRP0","PPRR0","PRRR0","PCCP0","CPPP0","CRRP0","RCPR0","RCRR0","RRRR0","PCPC0","RCRP0","CSCC0","PPRPT","PPPPT","RPRP0","PPRR0","PRRR0","PCP?0","CPPP0","CRRP0","RCPR0","RCRR0","RRRR0","PCPC0","RCRP0","CSCC0","PPRPT","PPPPT","RCRP0","CSCC0" };
	char temp[6];
	int n, m, rng=0;
	char board[3481][5] = { 0 };
	for (n = 0; n < 30; n++)
	{
		//temp = { tiles[n].top, tiles[n].right,  tiles[n].bottom,  tiles[n].left,  tiles[n].temple, }

		temp[0] = input[n][0];
		temp[1] = input[n][1];
		temp[2] = input[n][2];
		temp[3] = input[n][3];
		temp[4] = input[n][4];

		rng = rand() % 3481;
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
