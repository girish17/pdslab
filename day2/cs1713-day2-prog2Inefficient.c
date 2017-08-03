/*-----------------------------------
Name: Girish M
Roll number: cs1713
Date: 25 July 2017
Program description: Write a program to find the highest and second highest value in an array of n integers using less than 2n − 3 comparisons.
Acknowledgements:
------------------------------------*/
#include <stdio.h>

int main()
{
  int a[]={3, 2, 56, 2, 8, 5, 3, 2, 0, 4, 1, 43, 21};
  int i=0, max, loc;
  int secondMax;
/*  typedef struct loserList{


  } *l;*/
  max = a[0];
  while( i != 13 )
  {
    if(a[i] >= max)
    {
      max = a[i];
      loc = i;
    }
    i++;
  }
  printf("\nMax element: %d\n", max);
  a[loc] = -1;
  i = 0;
  secondMax = a[0];
  while( i != 12 )
  {
    if(a[i] != -1 && a[i] >= secondMax)
    {
      secondMax = a[i];
    }
     i++;
  }
  printf("\n2nd Max element: %d\n", secondMax);
  return 0;
}

