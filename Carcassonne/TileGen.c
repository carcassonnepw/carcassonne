#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tilegen(int numberoftiles)
{
  char tileset[3] = {'C','P','R'};//set of tileparts to use
  char special[10] = {'0','T','0','0','0','0','0','0','0','0'};//assuming that 1 out of 10 tiles will be temple
  int i=0,k;//counters
  srand(time(NULL));//random
  char tiles[numberoftiles][4];//intialise array after knowing how many tiles in array
  FILE *f;

   f = fopen("input.txt", "w");
   if(f == NULL)
   {
      printf("Error!");
      exit(1);
   }
  for(i;i<numberoftiles;i++){
  for(k=0;k<4;k++){
         tiles[numberoftiles][k]=tileset[rand()%3];
   fprintf(f,"%c",tiles[numberoftiles][k]);
    }
    fprintf(f,"%c",special[rand()%10]);//add special notation at very end
    fprintf(f,"\n");
    }
   fclose(f);
}

