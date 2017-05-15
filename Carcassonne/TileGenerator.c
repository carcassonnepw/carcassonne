#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
  int numberoftiles;//how many tiles you want to generate
  //char up,right,down,left;
  char tileset[3] = {'C','P','R'};//set of tileparts to use
  char special[10] = {'0','T','0','0','0','0','0','0','0','0'};//assuming that 1 out of 10 tiles will be temple
  int i=0,k;//counters
  srand(time(NULL));//random
  
  printf("How many tiles?\n");
  scanf("%d",&numberoftiles);//self explanatory
  char tiles[numberoftiles][4];//intialise array after knowing how many tiles in array
  for(i;i<numberoftiles;i++){//keep doing loop until you reach numberoftiles
  for(k=0;k<4;k++){//keep doing loop for four triangles until reaching end of loop
  tiles[numberoftiles][k]=tileset[rand()%3];
   //printf("%c",tileset[rand()%3]);//randomly generate tiles
   printf("%c",tiles[numberoftiles][k]);
    }
    printf("%c",special[rand()%10]);//add special notation at very end
    printf("\n");
    }
  //  for(i;i<numberoftiles;i++){
  //for(k=0;k<4;k++){
  //  if(tiles[numberoftiles][k]=='C'){
  //    tiles[numberoftiles][2]=='S';
  //  }
  //printf()
  
  
  return 0;
}

//to do list
/*somehow add S to the output*/
/*write to input file*/
//check if tile can be valid or not
//check if tileset can have valid outcome or not how the hell

//FILE *f = fopen("file.txt", "w");
//if (f == NULL)
//{
//    printf("Error opening file!\n");
//    exit(1);
//}

// print some text 