/*---------------------------------------------------------------------------------------------
Name : Girish M
Roll : CS1713
Date : 13 Aug 2017
Desc : Write a C program that takes as input a positive integer ’n’ and generates a matrix of
size 2^nx2^n using pointer to pointer. Fill the matrix in a row major order with integers in 
the range [1,2^2n]. Print the matrix in a spiral fashion.
Acks :
---------------------------------------------------------------------------------------------*/
#include "common.h"

/*Initialize an nxn matrix using dynamic memory allocation*/
int** initMatrix(int** M, int r)
{
   int i, j;
   M = (int**) malloc(sizeof(int)*r*r);
   for(i=0; i<r; i++)
   {
     M[i] = (int*) malloc(sizeof(int)*r);
   }
   //Initialize to zero
   for(i=0; i<r; i++)
   {
     for(j=0; j<r; j++)
     {
       M[i][j] = 0.0;
     }
   }
   return M;
}

void printSpiral(int** M, int n)
{
  int k, j;
  /*if n is odd*/
  printf("\nSpiral order:\n");
  if(n%2 != 0)
  {
   /*printf("\nOdd order matrix\n");*/
   for(k=0; k<ceil((double)n/2); k++)
   {
     if(k != (ceil((double)n/2)-1))
     {
      /*printf("\n1st side right\n");*/
      for(j=k; j<(n-k); j++)
      {
       printf("%d ", M[k][j]);
      }
      /*printf("\n2nd side down\n");*/
      for(j=(k+1); j<=(n-k-1); j++)
      {
       printf("%d ", M[j][n-k-1]);
      }
      /*printf("\n3rd side left\n");*/
      for(j=(n-k-2); j>=k; j--)
      {
       printf("%d ", M[n-k-1][j]);
      }
      /*printf("\n4th side up\n");*/
      for(j=(n-k-2); j>k; j--)
      {
       printf("%d ", M[j][k]);
      }
     }
     else
     {
       /*printf("\nCenter element\n");*/
       printf("%d ", M[k][k]);
     }
   }
  }
  else
  {
    /*printf("\nEven order matrix\n");*/
    /*if n is even*/
    for(k=0; k<ceil(n/2); k++)
    {
      /*printf("\n1st side right\n");*/
      for(j=k; j<(n-k); j++)
      {
       printf("%d ", M[k][j]);
      }
      /*printf("\n2nd side down\n");*/
      for(j=(k+1); j<=(n-k-1); j++)
      {
       printf("%d ", M[j][n-k-1]);
      }
      /*printf("\n3rd side left\n");*/
      for(j=(n-k-2); j>=k; j--)
      {
       printf("%d ", M[n-k-1][j]);
      }
      /*printf("\n4th side up\n");*/
      for(j=(n-k-2); j>k; j--)
      {
       printf("%d ", M[j][k]);
      }
    }
  }
  printf("\n");
}

int main(int argc, char* argv[])
{
  int** a = NULL;
  int i, j, k;
  if(argc == 2)
  {
    k = atoi(argv[1]);
    a = initMatrix(a, k);
    printf("Enter the elements of %d X %d Matrix : \n", k, k);
    for (i = 0;i < k; i++)
    {
     for (j = 0;j < k; j++)
     {
        scanf("%5d", &a[i][j]);
     }
    }
    printf("\nEntered matrix: \n");
    for(i=0 ; i<k; i++)
    {
     for(j=0; j<k; j++)
     {
       printf("%d ", a[i][j]);
     }
     printf("\n");
    }
    printSpiral(a, k);
    free(a);
  }
  else
      printf("\nUsage: ./prob2.o positiveInt\n");

  return 0;
}

