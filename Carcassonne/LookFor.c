#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"


struct twoints FindTile(char criterium [5]) {
	char tmp;
	struct twoints result;
	//m,n,o - loops
	int n, m, o, bool = 1;
	//scanf("%s", criterium);
	result.a = -1;
	result.b = -1;
	//adjusting criterium--------------------------------------------
	for (m = 0; m < 4; m++)
	{
		if (criterium[m] == 'R' || criterium[m] == 'P' || criterium[m] == 'C' || criterium[m] == 'S')
		{
			//do nothing
		}
		else
		{
			criterium[m] = 33;
		}
	}
	criterium[4] = 0;
	//---------------------------------------------------------------

	for (n = 0; n < 30; n++)
	{
		//--------------------------------------------
		for (o = 0; o<4; o++)//checking 4 angles
		{
			//-------------
			bool = 1;

				if ((criterium[0] == tiles[n].top || criterium[0] == 33)&& (criterium[1] == tiles[n].right || criterium[1] == 33) && (criterium[2] == tiles[n].bottom || criterium[2] == 33) && (criterium[3] == tiles[n].left || criterium[3] == 33) && tiles[n].availability==1)   //checking if tile fits criterium, or if there is no criterium
				{
					bool = bool;  //match, or no criterium
		
				}
				else
				{
	//		printf("\n________%c%c%c%c\n", tiles[o].top, tiles[o].right, tiles[o].bottom, tiles[o].left);
					bool = 0;	//false
				}
			if (bool == 0)
			{
				//nothing
			}
			else
			{
			//	printf("found index: %d\n", n);
			//	printf("rotation: %d deg left\n", o * 90);
				result.a = n;
				result.b = o;
				return (result); //succesful end of search
			}
			//end of checking one angle
			tmp = criterium[0];				//rotating criterium
			criterium[0] = criterium[1];	//90 degrees
			criterium[1] = criterium[2];
			criterium[2] = criterium[3];
			criterium[3] = tmp;
		}
	}
	return (result);//failed to find

}