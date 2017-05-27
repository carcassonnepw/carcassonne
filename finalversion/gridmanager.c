#include <stdio.h>
#include "structures.h"
#include <string.h>
#include<stdlib.h>
#include "gridmanager.h"
int gids=1;
int grid[GRIDSIZE][GRIDSIZE];
struct roadsstruct *roads=NULL;
struct roadsstruct *newroads=NULL;

void allocatememory(int count)
{
	
     newroads = (struct roadsstruct*) realloc (roads, count * sizeof(struct roadsstruct));
     //newroads->tilers=malloc(900*sizeof(int));

     if (newroads!=NULL) {
       roads=newroads;
  
       printf("allocated successfully\n");
 
     }
     else {
       free (roads);
       puts ("Error (re)allocating memory");
       exit (1);
     }
}



//here new
int checkisempty(int x, int y)
{
	if(grid[x][y]==0)
	return 1; else return 0;
}

int placetile(int id, int x, int y)
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

		return 1;
	}
	else
	{
		printf("\n#########ERROR: Tile not available\n");
		return 0;
	}
} 
	else
	{
		printf("\n#########ERROR: Grid is already occupied\n");
		return 0;
	}
	
}

void filegrid(int grid[GRIDSIZE][GRIDSIZE], char filename[])//----------------------
{
	int i;
	int j;
	
	FILE *plik;
	plik = fopen(filename, "w");
	for (i=0; i<GRIDSIZE; i++)
	{
		for (j=0; j<GRIDSIZE; j++)
		{

			if (grid[i][j] == 0)
			{
				fprintf(plik, "00000 ");
			}
			else
			{
				fprintf(plik, "%c%c%c%c%d ", tiles[tilesongrid[grid[i][j]].ID].top, tiles[tilesongrid[grid[i][j]].ID].right, tiles[tilesongrid[grid[i][j]].ID].bottom, tiles[tilesongrid[grid[i][j]].ID].left, tiles[tilesongrid[grid[i][j]].ID].isTemple);
			}

		}
		fprintf(plik, "\n");

	}
        fprintf(plik, "POINTS: %d",roadcountersimplest());
}
void showgrid(int grid[GRIDSIZE][GRIDSIZE], int cut, int tnj)
{
	int i;
	int j;
	int k;
	 //cut = 9;
	 //tnj = 9;
	printf("xy   |");
	for(i=cut;i<GRIDSIZE-tnj;i++) printf("%-*d|",3,i);
	 printf("\n");
	 for (k = cut; k < ((GRIDSIZE + 1) * 4) - tnj * 4; k++)printf("*");
	printf("\n");
	for(i=cut;i<GRIDSIZE-tnj;i++)
	{
		printf("%*d* ",3,i);
		for(j=cut;j<GRIDSIZE-tnj;j++)
		{
			
			if (grid[i][j] == 0)
			{
				printf("|   ");
			}
			else
			{
				printf("|%-*d", 3, grid[i][j]);
			}
		
		}
		 printf("\n");
		 for (k = cut+tnj*4; k < (GRIDSIZE + 1) * 4; k++)printf("_");
		 		printf("\n");

	}
}
void showtilesongrid()
{
	int id;
	int i;
	for(i=gids-1;i>0;i--){
	id = tilesongrid[i].ID;
	printf("TILE GID:%d (%d,%d)# %c%c%c%c #\n",tilesongrid[i].GID, tilesongrid[i].x,tilesongrid[i].y,tiles[id].top, tiles[id].right,tiles[id].bottom,tiles[id].left);
}
}

//end new

//cango is a function which is checking if tile can go to some direction, not to go outside the GRID
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





//this function is returning structure neighbours 
struct neighbours checkn(int GID,int ID)
{
    struct neighbours nei;
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
int roadcountersimplest()
{
    int i=0;
    int j=0;
    int GID;
    int points=0;
    int ID;
    for (i=0;i<GRIDSIZE;i++)
    {
        for(j=0;j<GRIDSIZE;j++)
        {
           GID=grid[i][j];
           if(GID!=0)
           {
            ID=tilesongrid[GID].ID;
            if(isroad(ID)==1||isroad(ID)==4||isroad(ID)==5||isroad(ID)==6||isroad(ID)==7||isroad(ID)==8||isroad(ID)==11||isroad(ID)==12||isroad(ID)==13||isroad(ID)==14) points+=1;
            if(isroad(ID)==2||isroad(ID)==3||isroad(ID)==9||isroad(ID)==10)points+=3;
            if(isroad(ID)==15)points+=4;
           } 
        }
    }
    return points;
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


void fullroad(int GID,int RID,int i,int cont, int starter, char side)

{
    struct neighbours neigh;
   allocatememory(RID);
   
     int ID;
     char letter;
    int result=0;
    ID= tilesongrid[GID].ID;
  //  int *side;
    int currentroad= isroad(ID);
    neigh=checkn(GID,0);
    int x= tilesongrid[GID].x;
    int y=tilesongrid[GID].y;
  //  printf("checkling1");
    if(cont==0)
    {
        
            printf("c\nheckling1\n");
            //printf("\n%d",);
            printf("\n%d",currentroad);
            if(currentroad==2)
            {
                if(isroad(neigh.rid)==1||isroad(neigh.rid)==7||isroad(neigh.rid)==8)  // road will be continue
                {
                    roads[RID].RID=RID;
                    roads[RID].start=GID;
                    roads[RID].tilers[0]=GID;
                    roads[RID].points+=1;
                    tiles[ID].right='W';
                    cont=1;
                    
                }
                if(isroad(neigh.rid)==2||isroad(neigh.rid)==3||isroad(neigh.rid)==9||isroad(neigh.rid)==12||isroad(neigh.rid)==15)
                {
                    roads[RID].RID=RID;
                    roads[RID].start=GID;
                    roads[RID].tilers[0]=GID;
                    roads[RID].points+=1;
                    tiles[ID].right='W';
                    tiles[neigh.rid].left='W';
                    roads[RID].tilers[1]=givegid(neigh.rid);
                    roads[RID].points*=2;
                }
                
            }
           
        /*
       // if(tiles[ID].roadid==2||tiles[ID].roadid==3||tiles[ID].roadid==5||tiles[ID].roadid==9||tiles[ID].roadid==10||tiles[ID].roadid==11||tiles[ID].roadid==12||tiles[ID].roadid==13||tiles[ID].roadid==14||tiles[ID].roadid==15)starter=currentroad;
        if(isroad(currentroad)==2&&((isroad(neigh.rid)==1||isroad(neigh.rid)==2||isroad(neigh.rid)==3||isroad(neigh.rid)==7||isroad(neigh.rid)==8||isroad(neigh.rid)==9||isroad(neigh.rid)==12||isroad(neigh.rid)==15)) )
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
       if(isroad(currentroad)==5&&((isroad(neigh.rid)==1||isroad(neigh.rid)==2||isroad(neigh.rid)==3||isroad(neigh.rid)==7||isroad(neigh.rid)==8||isroad(neigh.rid)==9||isroad(neigh.rid)==12||isroad(neigh.rid)==15)))
        {
                     //   printf("\nSIDE: %d\n",*side);

             roads[RID].RID=RID;
            roads[RID].start=GID;
            roads[RID].tilers[0]=GID;
            roads[RID].points+=1;     
            side='r';
            
        }
        if(isroad(currentroad==5&&(isroad(neigh.did)==3||isroad(neigh.did)==4||isroad(neigh.did)==6||isroad(neigh.did)==7||isroad(neigh.did)==9||isroad(neigh.did)==10||isroad(neigh.did)==11||isroad(neigh.did)==15)))
        {
            roads[RID].RID=RID;
            roads[RID].start=GID;
            roads[RID].tilers[0]=GID;
            roads[RID].points+=1;     
            side='d';
        }
 
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
       
       */ 
    }
    else
    {
        
    }
   // if
   
   // neigh=checkn(GID,0);
    //if
    //printf("TOP: %d RIGHT:%d BOTTOM:%d LEFT:%d  ",neigh.tid,neigh.rid,neigh.did,neigh.lid);
    
    
    
    
}
