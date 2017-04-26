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
void rotation(int GID, int times)
{
	int i;
	int temp1, temp2,temp3;
	int tileid = tilesongrid[GID].ID;
	for(i=times;i>0;i--)
	{
		temp1= tiles[tileid].right;
		tiles[tileid].right=tiles[tileid].top;
		temp2=tiles[tileid].bottom;
		temp3=tiles[tileid].left;
		tiles[tileid].bottom=temp1;
		tiles[tileid].left=temp2;
		tiles[tileid].top=temp3;
	}
}
