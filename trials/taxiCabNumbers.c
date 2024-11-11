/*
 * Taxi cab number generator : Hardy - Ramanujan numbers
 * /


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void taxiCabNumbers(const int*);
int checkNotEq(int,int,int,int);

int main(void)
{
    int num = 0;
    printf("Enter the number upto which taxi cab numbers have to be generated: ");
    scanf("%d",&num);
    taxiCabNumbers(&num);
    return 0;
}

void taxiCabNumbers(const int* num)
{
   int limit = *num;
   int a, b, c, d, acube, bcube, ccube, dcube;
    int* numArray = (int*) malloc(limit*sizeof(int));
   int count = 0;
   for(a=0 ; a<limit; a++)
   {
     if(numArray[a] != 1)
     {
	for(b=0 ; b<limit; b++)
     	{
		if(numArray[b] != 1)
		{
			for(c=0 ; c<limit; c++)
			{
	   			if(numArray[c] != 1)
				{
					for(d=0 ; d<limit; d++)
	   				{
	        				if(numArray[d] != 1)
						{
							if(checkNotEq(a,b,c,d))
	   						{
								acube = pow(a,3);
								bcube = pow(b,3);
								ccube = pow(c,3);
								dcube = pow(d,3);
		   						if((acube+bcube) == (ccube+dcube))
								{
									printf("(%d,%d,%d,%d):%d\n",a,b,c,d,(acube+bcube));
									numArray[a] = 1;
									numArray[b] = 1;
									numArray[c] = 1;
									numArray[d] = 1;
									count++;				 
								}
                    					
	   						}	

						}
	 			
	   				}
				
				}
			}
		  
     		}
     	}     
     }
   }
   printf("Total number of taxi cab numbers between 1 and %d: %d\n",limit, count);
}

int checkNotEq(int a, int b, int c, int d)
{
  if((a!=b) && (b!=c) && (c!=d) && (d!=a) && (a!=c) && (b!=d))
     return 1;
  else
     return 0;
}
