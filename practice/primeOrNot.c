#include <stdio.h>
#include <stdlib.h>
char primeOrNot(int num)
{
 int numOfFactors = 2, i;
 if(num > 2)
 {
  for(i=1; i<=num-1; i++)
  {
    if(num%i == 0)
     numOfFactors++;
  }
  if(numOfFactors > 2)
     return '\0' ;
  else
     return 'a';
 }
 else 
    return '\0';
}

int main(int argc, char* argv[])
{
 if(argc == 2)
 {
  if(primeOrNot(atoi(argv[1])))
  {
    printf("\nPrime\n");
  }
  else
    printf("\nNot Prime\n");
 }
 else
   printf("\nUsage: ./primeOrNot.o num\n");
 return 0;
}