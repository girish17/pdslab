/*-----------------------------------
Name: Girish M
Roll number: MTech CS 13
Date: 20/07/2017
Program description: Find max, min and avg of list of integers
Acknowledgements:
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
 int num, max=0, min=0, sum=0, count=0;
 float avg=0.0;
 while(1)
 {
   printf("\nEnter number (To exit enter -1)\n");
   scanf("%d",&num);
   if(num == -1)
   {
	exit(0);
   }
   if(count == 0)
   {
	//initialize max, min and avg
        max = num;
        min = num;
        avg = num;
   }
   else 
   {
    if(num > max)
    {
	max = num;
    }
    if(num < min)
    {
 	min = num;
    }
   }
   sum += num;
   count++;
   avg = (float) sum / (float) count;
   printf("\nMax: %d Min: %d Avg: %.3f\n", max, min, avg); 
 }
 return 0;
}
