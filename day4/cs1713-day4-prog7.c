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

int* unionOfTwoSets(int* A, int* B, int sizeA, int sizeB)
{
  
  return 0;

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
 unsigned int A[SIZE], B[SIZE];
 unsigned int i
 
 if(argc == 3)
 {
  int sizeA = atoi(argv[1]);
  int sizeB = atoi(argv[2]);

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
  printf("\nA∩B: ");
  printf("\nA ⊆ B: ");
  printf("\nPower set of A: ");
  printf("\nPower set of B: ");
 }
 else
    printf("\nUsage: ./cs1713-day4-prog7.o sizeA sizeB\n");
 
 return 0;
}
