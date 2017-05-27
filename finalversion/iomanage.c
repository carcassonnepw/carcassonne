#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

void readInput(char filename[])
{
    

    //int isCrossroad;
    char string[950];
    char line[256];
    size_t len = 0;
    int i=1;
    ssize_t read;
    FILE *inputfile;
    
    
    
    
    if ((inputfile = fopen(filename, "r")) == NULL)
    {
        printf("error while opening file ");
        
        
        puts(filename);
        //return 0;
    } else
    {
        while (fgets(line, sizeof(line), inputfile)) {
            strcpy(string,line);
       // printf("%s", line); 
		            
            tiles[i].ID= i;
            tiles[i].availability = 1;
            tiles[i].top = string[0];
            tiles[i].right=string[1];
            tiles[i].bottom=string[2];
            tiles[i].left =string[3];
            if(string[4]=='S')
            {
                tiles[i].isShield = 1;
                tiles[i].isTemple =0;
            } else if(string[4] =='T')
            {
                tiles[i].isShield = 0;
                tiles[i].isTemple = 1;
            }
            if(tiles[i].top=='C' && tiles[i].right=='C' && tiles[i].bottom=='C' && tiles[i].left=='C') tiles[i].isCity =1; else tiles[i].isCity = 0;
            if(tiles[i].top=='R' && tiles[i].right=='R' && tiles[i].bottom=='R' && tiles[i].left=='R') tiles[i].isCrossroad =1; else tiles[i].isCrossroad = 0;
           // printf("ID:  %d\n",i);
        
            i++;
            
        }
    }
}
