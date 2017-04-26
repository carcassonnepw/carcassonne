#include <stdio.h>
#include "structures.h"

void showavailable()
{
 	int i=0;
    int sum=0;
    for(i=0;i<TILECOUNT;i++)
    {
    	if(tiles[i].availability==1)
    	{
    		 		 			        printf("\nid:%d T:%c R:%c B:%c L:%c City:%d Shield:%d CROSSROAD:%d\n",tiles[i].ID, tiles[i].top,tiles[i].right, tiles[i].bottom, tiles[i].left, tiles[i].isCity, tiles[i].isShield, tiles[i].isCrossroad);
           sum++;
		}
	}
	if(sum==TILECOUNT) printf("\n#########ERROR: No tiles left\n");
     
}