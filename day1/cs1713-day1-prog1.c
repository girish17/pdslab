/*-----------------------------------
Name: Girish M
Roll number: cs1713
Date: 25 July 2017
Program description: Write a program to determine the ranges of the generic C data types:
char,int,float,double – both for unsigned and signed cases.Consider short and long data types too, wherever appropriate
Acknowledgements:
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <inttypes.h>
#include <stdint.h>

int main(void)
{
  printf("---------------------------------------------------");
  printf("\nSize of int is %ld, float is %ld, char is %ld, double is %ld bytes.\n", sizeof(int), sizeof(float), sizeof(char), sizeof(double));
  printf("\nSize of long is %ld bytes.\n", sizeof(long));
  printf("\nSize of short is %ld bytes.\n", sizeof(short));
  printf("\nSize of unsigned is %ld bytes.\n", sizeof(unsigned));
  printf("---------------------------------------------------");
  printf("\nRange of int is from %d to %d\n", INT_MIN, INT_MAX);
  printf("\nRange of float is from %e to %e\n", FLT_MIN, FLT_MAX);
  printf("\nRange of char is from %d to %d\n", CHAR_MIN, CHAR_MAX);
  printf("\nRange of double is from %e to %e\n", DBL_MIN, DBL_MAX);
  printf("\nRange of unsigned int is from %d to %u\n", 0, UINT_MAX);
  printf("\nRange of short is from %d to %d\n", SHRT_MIN, SHRT_MAX);
  printf("\nRange of long is from %ld to %ld\n", LONG_MIN, LONG_MAX);
  printf("---------------------------------------------------\n");
  return 0;
}
