/*-----------------------------------
Name: Girish M
Roll number: cs1713
Date: 25 July 2017
Program description:Write a program to find the number of (possibly overlapping)
occurrences of the sequence B in A.
Acknowledgements:
------------------------------------*/
#include <stdio.h>

int main()
{
 int arr1[] = {1, 2, 2, 2, 2, 1,  2, 3, 3, 4, 3, 1, 2, 3, 1, 2, 3, 2, 1, 1};
 int arr2[] = {2, 2, 2};
 int i=0, j=0, k=0, match=0;
 while(j != 20)
 {
  if(arr1[k] == arr2[i])
  {
    i++;
    k++;
  }
  else
  {
    i=0;
  }
  if(i == 3)
  {
    match++;
    i=0;
  }
  k=j;
  j++;
 }
 printf("\nNo. of matches %d\n", match);
 return 0;
}
