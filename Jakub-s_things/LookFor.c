#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main (){
	//test input
	char input[30][5] = { "RPRP0","PPRR0","PRRR0","PCCP0","CPPP0","CRRP0","RCPR0","RCRR0","RRRR0","PCPC0","RCRP0","CSCC0","PPRPT","PPPPT","RPRP0","PPRR0","PRRR0","PCP0","CPPP0","CRRP0","RCPR0","RCRR0","RRRR0","PCPC0","RCRP0","CSCC0","PPRPT","PPPPT","RCRP0","CSCC0" };
	char criterium[5], tmp;
	//m,n,o - loops
	int n, m,o, bool=1;
	scanf("%s", criterium);
	
	//adjusting criterium--------------------------------------------
	for (m = 0; m < 4; m++)
	{
		if (criterium[m] =='R' || criterium[m] =='P' || criterium[m] =='C' || criterium[m] == 'S')
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

	printf("adjusted:%s\n", criterium);
		for (n = 0; n < 30;n++)
		{
			printf("---%d\n", n);
			//--------------------------------------------
			for(o=0;o<4;o++)//checking 4 angles
			{
			//-------------
				bool = 1;
				for (m = 0; m < 4; m++) //comparing criterium with input [n][m]
				{

						if (criterium[m] == input[n][m]||criterium[m]==33)   //checking if tile fits criterium, or if there is no criterium
						{
							bool = bool;  //match, or no criterium
						}
						else
						{

							bool = 0;	//false
						}
						//printf("%c=%c\n", criterium[m], input[n][m]);
				}
				if (bool == 0)
				{
					//nothing
				}
				else
				{
					printf("found index: %d\n",n);
					printf("rotation: %d deg left\n", o*90);
					return (n); //succesful end of search
					//break;	//match found
				}
				//end of checking one angle
				printf("		%s", criterium);
				tmp = criterium[0];				//rotating criterium
				criterium[0] = criterium[1];	//90 degrees
				criterium[1] = criterium[2];
				criterium[2] = criterium[3];
				criterium[3] = tmp;
				printf("---->%s\n", criterium);
				}
			}
		printf("no match found\n");
		return (31);//failed to find
		}
		

