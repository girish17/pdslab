/*-----------------------------------
Name: Girish M
Roll number: cs1713
Date: 25 July 2017
Program description:Take a positive integer x from the user, and compute the value of x!.
How long does it take with naive multiplications? Can you do any
better? Can you compute for arbitrary sized inputs?
Acknowledgements:http://pubs.opengroup.org/onlinepubs/7908799/xsh/regcomp.html
------------------------------------*/

#include <stdio.h>

/*
	Dynamic Programming Approach
	Funtion to calculate up to N Factorials
*/
long int factorialDP(int n)
{
	long int a[n+1],i,j; // factorials array
	a[0]=1;
	
	for(i=1;i<=n;i++) 
	{
		a[i] = i * a[i-1];
	}
	
	return a[n];
}

int main(void)
{
  int n, i;
  long int factorial = 1;
  printf("\nEnter a number\n");
  scanf("%d", &n);
  if(n >= 0 && n < 21)
  {
    /*Iterative logic
    for( i=1 ; i<=n; i++)
    {
      factorial = factorial * i;
    }*/
    printf("\nFactorial of %d is %ld.\n", n, factorialDP(n));
  }
  else
  {
    printf("\nFactorial can be computed for number from 0 to 20\n");
  }
  return 0;
}
