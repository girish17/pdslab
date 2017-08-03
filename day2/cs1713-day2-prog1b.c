/*-----------------------------------
Name: Girish M
Roll number: cs1713
Date: 25 July 2017
Program description: Write a program to find whether the multisets corresponding to A and B are equal.
Acknowledgements:
------------------------------------*/
#include <stdio.h>
#include <malloc.h>

int max(int arr[], int len)
{
  int i, max;
  max = arr[0];
  for(i=0; i<len; i++)
  {
    if(arr[i] >= len)
      max = arr[i];
  }
  return max;
}

int main()
{
 int A[]={1, 2, 2};
 int B[]={1, 2, 2};
 int mulSet=0;

 int i, j, k;

 int maxA, maxB;

 maxA = max(A, 5);
 maxB = max(B, 3);

 if(maxA != maxB)
 {
   printf("\nNo. of multisets of A and B are not equal.\n");
 }
 else
 {
   int* countA = (int*) malloc(sizeof(int)*maxA);
   int* countB = (int*) malloc(sizeof(int)*maxB);
   for(i=0; i<maxA; i++)
   {
     countA[i] = 0;
     countB[i] = 0;
   }
   //calc set A elements frequency
   for(i=0; i<5; i++)
   {
    countA[A[i]-1]++;
   }
   //calc set B elements frequency
   for(j=0; j<3; j++)
   {
    countB[B[j]-1]++;
   }

   for(k=0; k<maxA; k++)
   {
     if(countA[k] == countB[k])
     {
       mulSet++;
     }
     else
     {
        printf("\nNo. of multisets of A and B are not equal.\n");
        break;
     }
   }
   free(countA);
   free(countB);
 }
 return 0;
}
