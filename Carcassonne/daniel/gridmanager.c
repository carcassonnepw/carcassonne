#include <stdio.h>
#include "structures.h"
#include <string.h>
#include<stdlib.h>
#include "gridmanager.h"
int gids=1;
int grid[GRIDSIZE][GRIDSIZE];
struct roadsstruct *roads=NULL;
struct roadsstruct *newroads=NULL;

int allocatememory(int count)
{
	
     newroads = (struct roadsstruct*) realloc (roads, count * sizeof(struct roadsstruct));
     //newroads->tilers=malloc(900*sizeof(int));

     if (newroads!=NULL) {
       roads=newroads;
       //numbers[count-1]=input;
       printf("allocated successfully\n");
       //memset(roads[count].tilers, 0, 15);
     }
     else {
       free (roads);
       puts ("Error (re)allocating memory");
       exit (1);
     }
}
int checkisempty(int x, int y)
{
	if(grid[x][y]==0)
	return 1; else return 0;
}
void placetile(int id, int x, int y)
{
	
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
    } else printf("\n#########ERROR: Tile not available\n");
} else  printf("\n#########ERROR: Grid is already occupied\n");
	
}
void showgrid(int grid[GRIDSIZE][GRIDSIZE])
{
	int i;
	int j;
	int k;
	printf("xy|   ");
	for(i=0;i<GRIDSIZE;i++) printf("%-*d|",3,i);
	 printf("\n");
		 		for(k=0;k<(GRIDSIZE+1)*4;k++)printf("*");
	printf("\n");
	for(i=0;i<GRIDSIZE;i++)
	{
		printf("%*d* ",3,i);
		for(j=0;j<GRIDSIZE;j++)
		{
			
						
			printf("|%-*d",3,grid[j][i]);
		
		}
		 printf("\n");
		 		for(k=0;k<(GRIDSIZE+2)*4;k++)printf("_");
		 		printf("\n");

	}
}
void showtilesongrid()
{
	int id;
	int i; 
	for(i=gids;i>0;--i){
	id = tilesongrid[i].ID;
	if (id==0);
	else 
	{
	
	printf("%d: TILE GID:%d (%d,%d)# %c%c%c%c # ID:%d #\n",i,tilesongrid[i].GID, tilesongrid[i].x,tilesongrid[i].y,tiles[id].top, tiles[id].right,tiles[id].bottom,tiles[id].left,id);
	}
}
}
struct sasiedzi checkn(int GID,int ID)
{
    struct sasiedzi nei;
    int x=tilesongrid[GID].x;
    int y=tilesongrid[GID].y;
    
   
    
    
    
    if(x==0) 
    {
        nei.tid=-1;
    } else nei.tid=tilesongrid[grid[x][y-1]].ID;
        
    if(x==GRIDSIZE-1)
    {
       nei.rid=-1;
    } else  nei.rid=tilesongrid[grid[x+1][y]].ID;
    if(y==0) 
    {
        nei.lid=-1;
    } else nei.lid=tilesongrid[grid[x-1][y]].ID;
    
    if(y==GRIDSIZE-1) 
    {
        nei.did=-1;
    } else nei.did=tilesongrid[grid[x][y+1]].ID;
    
    
    return nei;
}
struct neighbors checkneigh(int GID)
{
  
  struct neighbors neigh;
  int i;
  char empty[5]="00000";

  int a=0;
  int b=0;
  int c=0;
  int d=0;
  int x= tilesongrid[GID].x;
  int y= tilesongrid[GID].y;
  int topid = tilesongrid[grid[x][y-1]].ID;
  int botid = tilesongrid[grid[x][y+1]].ID;
  int legid =tilesongrid[grid[x-1][y]].ID;
  int rigid =tilesongrid[grid[x+1][y]].ID; 
  
    //adding down series
//*******************************************************************************
  if(botid==0)  
  {
  strcpy(neigh.down,empty);
  neigh.dgid=-1;
  }
  else
  {
  	printf("cos innego\n");
  	neigh.rgid=tilesongrid[grid[x][y+1]].GID;
  neigh.down[0] = tiles[botid].top;
  neigh.down[1] = tiles[botid].right;
  neigh.down[2] =tiles[botid].bottom;
  neigh.down[3] =tiles[botid].left;
  if(tiles[botid].isTemple==1) neigh.down[4] = 'T';
  else
  if(tiles[botid].isShield==1) neigh.down[4] = 'S';
  else neigh.down[4]=0;
  
  }
  //end down
 //adding up series
 //*****************************************************************************

  if(topid==0)  
  {
  	neigh.tgid= -1;
  b=1;
  }
  else
  {
  	neigh.tgid= tilesongrid[grid[x][y-1]].GID;
  neigh.up[0] = tiles[topid].top;
  neigh.up[1] = tiles[topid].right;
  neigh.up[2] =tiles[topid].bottom;
  neigh.up[3] =tiles[topid].left;
  if(tiles[topid].isTemple==1) neigh.up[4] = 'T';
  else
  if(tiles[topid].isShield==1) neigh.up[4] = 'S';
  else neigh.up[4]=0;
  }
  //end up
  
   //adding left series

  if(legid==0)
  {
  	neigh.lgid=-1;
  	
	  strcpy(neigh.left,empty);
}
  else
  {
  neigh.lgid=tilesongrid[grid[x-1][y]].GID;
  neigh.left[0] = tiles[legid].top;
  neigh.left[1] = tiles[legid].right;
  neigh.left[2] =tiles[legid].bottom;
  neigh.left[3] =tiles[legid].left;
  if(tiles[legid].isTemple==1) neigh.left[4] = 'T';
  else
  if(tiles[legid].isShield==1) neigh.left[4] = 'S';
  else neigh.left[4]=0;
  }
  //end left
  
  //adding right series

  if(rigid==0)  
  {
  strcpy(neigh.right,empty);
  neigh.rgid=-1;
  }
  else
  {
  	neigh.rgid=tilesongrid[grid[x+1][y]].GID; 
  neigh.right[0] = tiles[rigid].top;
  neigh.right[1] = tiles[rigid].right;
  neigh.right[2] =tiles[rigid].bottom;
  neigh.right[3] =tiles[rigid].left;
  if(tiles[rigid].isTemple==1) neigh.right[4] = 'T';
  else
  if(tiles[rigid].isShield==1) neigh.right[4] = 'S';
  else neigh.right[4]=0;
  }
  //end right
  
  //return neigbords
  	  //printf("test left:%s\n",neigh.left);
  // if(a==1) strcpy(neigh.down,empty);
  // if(b==1) strcpy(neigh.up,empty);
   return neigh;
  
  
}

void  test(int GID)
{
	struct neighbors neigh = checkneigh(GID);
	int i; 
		printf("ID: %d DOWN: %s\n",neigh.dgid,neigh.down);
		printf("ID: %d TOP: %s\n",neigh.tgid,neigh.up);
		printf("ID: %d RIGHT: %s\n",neigh.rgid,neigh.right);
		printf("ID: %d LEFT: %s\n",neigh.lgid,neigh.left);
	
}
int isroad (int ID)
{
	int result=0;
	//horizontally going
	if(tiles[ID].left=='R'&&tiles[ID].right=='R')  result=1;//poziomo -horizontally
	if(tiles[ID].left=='R'&&tiles[ID].bottom=='R'&tiles[ID].right=='R') result=2; //skrzyzowanie poziome z dolem -crossroad horizontally with bottom 
	if(tiles[ID].left=='R'&&tiles[ID].top=='R'&&tiles[ID].right=='R')   result=3; //skrzyzowanie poziome z gora  -crossroad horizontally with top
	if(tiles[ID].top=='R'&&tiles[ID].right=='R')   result=4;//z gÛry na prawo - from top to right
	if(tiles[ID].bottom=='R'&&tiles[ID].right=='R')result=5;//z do≥u na prawo - from bottom to right
	
	//pionowo
	if(tiles[ID].top=='R'&&tiles[ID].bottom=='R')  result=6;//pionowo-perpendicularly
	if(tiles[ID].left=='R'&&tiles[ID].top=='R')    result=7;//z lewej do gÛry - from left to top
	if(tiles[ID].left=='R'&&tiles[ID].bottom=='R') result=8;//z lewej w dÛ≥   - from left to bottom
	if(tiles[ID].top=='R'&&tiles[ID].left=='R'&&tiles[ID].bottom=='R')  result=9; //skrzyzowanie pionoe z lewo   -crossroad perpendicular with left
	if(tiles[ID].top=='R'&&tiles[ID].right=='R'&&tiles[ID].bottom=='R') result=10;//skrzyzowanie pionowe z prawo -crossroad perpendicular with right


	if(tiles[ID].top=='R'&&tiles[ID].right!='R'&&tiles[ID].bottom!='R'&&tiles[ID].left!='R') result=11;//droga z do≥u   -start of road from bottom
	if(tiles[ID].top!='R'&&tiles[ID].right!='R'&&tiles[ID].bottom!='R'&&tiles[ID].left=='R') result=12;//droga z prawej -start of road from right
	if(tiles[ID].top!='R'&&tiles[ID].right!='R'&&tiles[ID].bottom=='R'&&tiles[ID].left!='R') result=13;//droga z gÛry   -start of road from top
	if(tiles[ID].top!='R'&&tiles[ID].right=='R'&&tiles[ID].bottom!='R'&&tiles[ID].left!='R') result=14;//droga z lewej  -start of road from left
	
	//both
	if(tiles[ID].isCrossroad==1) result = 15;
	return result;
}
void testers()
{
	int i;
	for(i=1;i<90;i++)
	{
		printf("%d is type %d\n",i,isroad(i));
	}
}
int countroads()
{
	allocatememory(1);
	//allocatememory(2);

	 //roadsstruct *roads2=NULL;
	int idr=0;
	//roads[2].tilers[5]=5;
	int i;
	int gid;
	int id;
	
	int count=0;
	int roadid=0;
	int con = 1;
	int j=0;
	int tileid=0;
	int flag=0;
	if(flag==0)
	{
	
	for(i=0;i<GRIDSIZE;i++)
	{
		gid=grid[i][j];
		id= tilesongrid[gid].ID;
		printf("TYPES ROADS: %d\n",isroad(id));
		
		
		if(con==1)
		{
			if(isroad(id)>0&&isroad(id)<=5) 
			{
				if(cango(gid,'r')==1)
				
				{	
				roads[roadid].RID=roadid;
				roads[roadid].tilers[tileid]=gid;
				roads[roadid].points+=1;
			//	printf("test :%d\n",gid);
			    tileid++;
				}
			
			}
			if(isroad(id)>5&&isroad(id)<11)
			{
				if(cango(gid,'d')==1&&(isroad(id)==8||isroad(id)==9||isroad(id)==10))
				{
					roads[roadid].RID=roadid;
					roads[roadid].tilers[tileid]=gid;
					roads[roadid].points+=1;
					tileid++;
					--i;
					j++;
							
				}
				else
				if(cango(gid,'l')==1)
				{
					roads[roadid].RID=roadid;
					roads[roadid].tilers[tileid]=gid;
					roads[roadid].points+=1;
					tileid++;
					flag=1;
				//	--i;
				}
			}
			if(isroad(id)==0) con=0;
		}
	}
	if(flag==1)
	{
		for(i=0;i<GRIDSIZE;i++)
		{
			
		}
	}
		/*
		
	///	while(con==1)
	//	{
		
		if(tiles[id].right=='R'&&(cango(gid,'r')==1)) 
		{
			count++;
			printf("ilosc:%d\n",count);
			roads[roadid].RID=roadid;
			roads[roadid].tilers[i]=gid;
			printf("GIDs%d\n",roads[roadid].tilers[i]);
	
	   // }
	} else if(tiles[id].left=='R'&&(cango(gid,'r')==1))
	{
		count++;
		roads[roadid].RID=roadid;
		roads[roadid].tilers[i]=gid;
		
	} else if (tiles[id].bottom=='R'&&(cango(gid,'b')==1))
	{
	    count++;
	    printf("goind down\n");
		roads[roadid].RID=roadid;
		roads[roadid].tilers[i]=gid;	
	}
		*/
		
	}
	for(i=0;i<15;i++)
	printf("\nGIDS of roads: %d\n",roads[roadid].tilers[i]);
	return 1;
}
int assignside(int *side,char where)
{
    if(where=='t') *side=1;
    if(where =='r') *side=2;
    if(where=='b')*side=3;
    if(where=='l')*side=4;
    return 1;
}

int fullroad(int GID,int RID,int i,int cont, int starter)

{
    struct sasiedzi neigh;
   allocatememory(RID);
    
     int ID;
     char letter;
    int result=0;
    ID= tilesongrid[GID].ID;
    int *side;
    int currentroad= isroad(ID);
    int x= tilesongrid[GID].x;
    int y=tilesongrid[GID].y;
    
    if(cont==0)
    {
        if(isroad(currentroad)==2||isroad(currentroad)==3||isroad(currentroad)==5||isroad(currentroad)==9||isroad(currentroad)==10||isroad(currentroad)==11||isroad(currentroad)==12||isroad(currentroad)==13||isroad(currentroad)==14||isroad(currentroad)==15)starter=currentroad;
        if(isroad(currentroad)==2&&((isroad(neigh.rid)==1||isroad(neigh.rid)==2||isroad(neigh.rid)==3||isroad(neigh.rid)==7||isroad(neigh.rid)==8||isroad(neigh.rid)==9||isroad(neigh.rid)==12||isroad(neigh.rid)==15)||(assignside(*side,'d'))||(assignside(*side,'d')))) 
        {
        roads[RID].RID=RID;
        roads[RID].start=GID;
        roads[RID].tilers[0]=GID;
        roads[RID].points+=1;
      //  fullroad();
     //   tiles[ID].right='W';//need to change
        }
        if(isroad(currentroad)==3&&((isroad(neigh.lid)==1||isroad(neigh.lid)==5) || (isroad(neigh.rid)==1||isroad(neigh.rid)==2||isroad(neigh.rid)==3||isroad(neigh.rid)==7||isroad(neigh.rid)==8||isroad(neigh.rid)==9||isroad(neigh.rid)==12||isroad(neigh.rid)==15)))
        {
            roads[RID].RID=RID;
            roads[RID].start=GID;
            roads[RID].tilers[0]=GID;
            roads[RID].points+=1;
           // tiles[ID].left='W';//need to change
        }
/*        if(isroad(currentroad)==5&&((isroad(neigh.rid)==1||isroad(neigh.rid)==2||isroad(neigh.rid)==3||isroad(neigh.rid)==7||isroad(neigh.rid)==8||isroad(neigh.rid)==9||isroad(neigh.rid)==12||isroad(neigh.rid)==15&&assignside(*side,'r'))||(isroad(neigh.did)==3||isroad(neigh.did)==4||isroad(neigh.did)==6||isroad(neigh.did)==7||isroad(neigh.did)==9||isroad(neigh.did)==10||isroad(neigh.did)==11||isroad(neigh.did)==15&&assignside(*side,'d'))))
        {
                        printf("\nSIDE: %d\n",*side);

             roads[RID].RID=RID;
            roads[RID].start=GID;
            roads[RID].tilers[0]=GID;
            roads[RID].points+=1;     
        }
 */
        if(isroad(currentroad)==9&&((isroad(neigh.tid)==5||isroad(neigh.tid)==6||isroad(neigh.tid)==8) ||(isroad(neigh.lid)==1||isroad(neigh.lid)==4||isroad(neigh.lid)==5)||(isroad(neigh.did)==3||isroad(neigh.did)==4||isroad(neigh.did)==6||isroad(neigh.did)==7||isroad(neigh.did)==9||isroad(neigh.did)==10||isroad(neigh.did)==11||isroad(neigh.did)==15)))
        {
            roads[RID].RID=RID;
            roads[RID].start=GID;
            roads[RID].tilers[0]=GID;
            roads[RID].points+=1;
           // tiles[ID].
        }
        if(isroad(currentroad)==10&&((isroad(neigh.tid)==5||isroad(neigh.tid)==6||isroad(neigh.tid)==8)||(isroad(neigh.rid)==1||isroad(neigh.rid)==2||isroad(neigh.rid)==3||isroad(neigh.rid)==7||isroad(neigh.rid)==8||isroad(neigh.rid)==9||isroad(neigh.rid)==12||isroad(neigh.rid)==15)||(isroad(neigh.did)==3||isroad(neigh.did)==4||isroad(neigh.did)==6||isroad(neigh.did)==7||isroad(neigh.did)==9||isroad(neigh.did)==10||isroad(neigh.did)==11||isroad(neigh.did)==15)))
        {
            roads[RID].RID=RID;
            roads[RID].start=GID;
            roads[RID].tilers[0]=GID;
            roads[RID].points+=1;
        }
        if(isroad(currentroad)==11&&(isroad(neigh.tid)==2||isroad(neigh.tid)==5||isroad(neigh.tid)==6||isroad(neigh.tid)==8||isroad(neigh.tid)==9||isroad(neigh.tid)==10||isroad(neigh.tid)==13||isroad(neigh.tid)==15))
        {
          roads[RID].RID=RID;
          roads[RID].start=GID;
          roads[RID].tilers[0]=GID;
          roads[RID].points+=1;
        }
        if(isroad(currentroad)==12&&(isroad(neigh.lid)==1||isroad(neigh.lid)==2||isroad(neigh.lid)==3||isroad(neigh.lid)==4||isroad(neigh.lid)==5||isroad(neigh.lid)==10||isroad(neigh.lid)==14||isroad(neigh.lid)==15))
        {
          roads[RID].RID=RID;
          roads[RID].start=GID;
          roads[RID].tilers[0]=GID;
          roads[RID].points+=1;
        }
        if(isroad(currentroad)==13&&(isroad(neigh.did)==3||isroad(neigh.did)==4||isroad(neigh.did)==6||isroad(neigh.did)==7||isroad(neigh.did)==9||isroad(neigh.did)==10||isroad(neigh.did)==11||isroad(neigh.did)==15))
        {       
          roads[RID].RID=RID;
          roads[RID].start=GID;
          roads[RID].tilers[0]=GID;
          roads[RID].points+=1;
            
        }
        if(isroad(currentroad)==14&&(isroad(neigh.rid)==1||isroad(neigh.did)==2||isroad(neigh.did)==3||isroad(neigh.did)==7||isroad(neigh.did)==8||isroad(neigh.did)==9||isroad(neigh.did)==12||isroad(neigh.did)==15))
        {
          roads[RID].RID=RID;
          roads[RID].start=GID;
          roads[RID].tilers[0]=GID;
          roads[RID].points+=1;            
        }
        if(isroad(currentroad)==15&&((isroad(neigh.tid)==2||isroad(neigh.tid)==5||isroad(neigh.tid)==6||isroad(neigh.tid)==8||isroad(neigh.tid)==9||isroad(neigh.tid)==10||isroad(neigh.tid)==3||isroad(neigh.tid)==15)  ||(isroad(neigh.rid)==1||isroad(neigh.rid)==2||isroad(neigh.rid)==3||isroad(neigh.rid)==7||isroad(neigh.rid)==8||isroad(neigh.rid)==9||isroad(neigh.rid)==12||isroad(neigh.rid)==15)||(isroad(neigh.did)==3||isroad(neigh.did)==4||isroad(neigh.did)==6||isroad(neigh.did)==7||isroad(neigh.did)==9||isroad(neigh.did)==10||isroad(neigh.did)==11||isroad(neigh.did)==15)||(isroad(neigh.lid)==1||isroad(neigh.lid)==2||isroad(neigh.lid)==3||isroad(neigh.lid)==4||isroad(neigh.lid)==5||isroad(neigh.lid)==10||isroad(neigh.lid)==12||isroad(neigh.lid)==15))  )
        {
          roads[RID].RID=RID;
          roads[RID].start=GID;
          roads[RID].tilers[0]=GID;
          roads[RID].points+=1; 
          
        }
       
        
    }
    else
    {
        
    }
   // if
   
    neigh=checkn(GID,0);
    //if
    printf("TOP: %d RIGHT:%d BOTTOM:%d LEFT:%d  ",neigh.tid,neigh.rid,neigh.did,neigh.lid);
    
    
    
    
}
int cango(int GID, char direction)
{
	
	int x;
	int y;
	if(direction=='l')
	{
	x= tilesongrid[GID].x;
	if(x-1>0) return 1; else return 0;
	} else
	if(direction=='r')
	{
	x= tilesongrid[GID].x;
	if(x+1<=30) return 1; else return 0;
	} else
	if(direction=='t')
	{
		y=tilesongrid[GID].y;
		if(y-1>0) return 1; else return 0;
	} else
	if(direction=='d') 
	{
		y=tilesongrid[GID].y;
		if(y+1<=30) return 1; else return 0;
	}
	else return 0;
}

