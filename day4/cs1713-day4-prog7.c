/*------------------------------------------------------------------------------------------------------------------
 Name: Girish M
 Roll number: cs1713
 Date: 1 August 2017
 Program description: Suppose that we choose to represent sets by arrays of non-negative integers, containing at most 100 elements each. Let A and B be 2 such sets of integers. Implement the following set operations:
 (a) A∪B; 
 (b) A∩B;
 (c) A ⊆ B (returns 1 if A is a subset of B, 0 otherwise);
 (d) prints the power set of A on the screen.
 Acknowledgements:
 ------------------------------------------------------------------------------------------------------------------*/
#include "common.h"

char isAlreadyPresent(int a, int* arr, int size)
{
  int i;
  for(i=0; i<size; i++)
  {
    if(arr[i] == a)
     return 1;
  }
  return 0;
}

int* unionOfTwoSets(int* A, int* B, int sizeA, int sizeB)
{
  int* C = (int*) malloc(sizeof(sizeA+sizeB));
  int i, j, k=0;

  for(i=0; i<sizeA; i++)
     C[i]=A[i];
  for(j=i; j<(sizeA+sizeB); j++)
  {
    if(isAlreadyPresent(B[k], A, sizeA))
    {
     C[j]=B[k];
     k++;
    }
  }
  return C;

}

int* intersectionOfTwoSets(int* A, int* B, int sizeA, int sizeB)
{
  return 0;
}

int* subsetOfTwoSets(int* A, int* B, int sizeA, int sizeB)
{

  return 0;
}

void powerSet(int* A, int sizeA)
{

  

}

int main(int argc, char* argv[])
{
 const int SIZE=100;
 int A[SIZE], B[SIZE];
 unsigned int i, sizeA, sizeB;
 
 if(argc == 3)
 {
  sizeA = atoi(argv[1]);
  sizeB = atoi(argv[2]);

  printf("\nEnter elements of set A:\n");
  for(i=0; i<sizeA; i++)
  { 
    printf("\nEnter element %d: ", i+1);
    scanf("%d",&A[i]);
  }
  printf("\nEnter elements of set B:\n");
  for(i=0; i<sizeB; i++)
  {
    printf("\nEnter element %d: ", i+1);
    scanf("%d",&B[i]);
  }

  printf("\nA∪B: ");
  int* unionArray = unionOfTwoSets(A, B, sizeA, sizeB);
  
  for(i=0; i<(sizeA+sizeB); i++)
  
  printf("\nA∩B: ");
  printf("\nA ⊆ B: ");
  printf("\nPower set of A: ");
  printf("\nPower set of B: ");
 }
 else
    printf("\nUsage: ./cs1713-day4-prog7.o sizeA sizeB\n");
 
 return 0;
}
