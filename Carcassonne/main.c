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
    
    
} ;


struct tile tiles [30];


int CheckIfTileIsAlreadyInStack(int type)
{
    return 0;
}
void readInput(char filename[])
{
    
    
    //int isCrossroad;
    char string[950];
    char *line = NULL;
    size_t len = 0;
    int i=0;
    ssize_t read;
    FILE *inputfile;
    
    if ((inputfile = fopen(filename, "r")) == NULL)
    {
        printf("error while opening file ");
        
        
        puts(filename);
        //return 0;
    } else
    {
        while ((read = getline(&line, &len, inputfile)) != -1) {
            strcpy(string,line);
            
            
            tiles[i].ID= i;
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
            printf("ID:  %d\n",i);
            i++;
            
        }
    }
}

int main(int argc, const char * argv[]) {
    
    char filename[255];
    scanf("%s",filename);
    
    readInput(filename);
    for (int i=0;i<30;i++)
    {
        
        printf("\nid:%d T:%c R:%c B:%c L:%c City:%d Shield:%d CROSSROAD:%d\n",tiles[i].ID, tiles[i].top,tiles[i].right, tiles[i].bottom, tiles[i].left, tiles[i].isCity, tiles[i].isShield, tiles[i].isCrossroad);
    }
    getchar();
    return 0;
    
}
