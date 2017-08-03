/*-----------------------------------
Name:Girish M
Roll number:cs1713
Date:20 July 2017
Program description: Given two positive integers, find their greatest common divisor (gcd).
Acknowledgements: Euclid's algorithm to compute gcd of two numbers
-----------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int gcd(int num1, int num2)
{
  if(num2 == 0)
    return num1;
  else
    return gcd(num2, num1%num2);
}

int main(int argc, char* argv[])
{
  if(argc == 3)
  {
     int num1 = atoi(argv[1]);
     int num2 = atoi(argv[2]);
     if((num1 >= 0) && (num2 >= 0))
     {
      if(num1 >= num2)
	printf("\nGCD of %d and %d is: %d\n", num1, num2, gcd(num1,num2));
      else
        printf("\nGCD of %d and %d is: %d\n", num1, num2, gcd(num2,num1));
     }
  }
  else
  {
    printf("\nUsage: ./cs1713-day0-prog1.o num1 num2\n");
  }
  return 0; 
}
