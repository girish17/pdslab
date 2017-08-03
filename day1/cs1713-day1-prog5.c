/*-----------------------------------
Name: Girish M
Roll number: cs1713
Date: 25 July 2017
Program description:Take positive integers x,n from the user, and compute x to the power of n. How long does it take with naive multiplications? Can you do any better?
Acknowledgements:http://pubs.opengroup.org/onlinepubs/7908799/xsh/regcomp.html
------------------------------------*/

#include <stdio.h>
#include <regex.h>
#include <stdlib.h>

int match(const char *string, char *pattern)
{
    int    status;
    regex_t    re;

    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
        return(0);      /* report error */
    }
    status = regexec(&re, string, (size_t) 0, NULL, 0);
    regfree(&re);
    if (status != 0) {
        return(0);      /* report error */
    }
    return(1);
}

/* Extended version of power function that can work
 for float x and negative y*/ 
/*float power(float x, int y)
{
    float temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);       
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}*/ 

/* Function to calculate x raised to the power y in O(logn)*/
long int power(long int x, long int y)
{
    long int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
    {
      if(y > 0)
         return x*temp*temp;
      else
         return (temp*temp)/x;
    }
}

int main(int argc, char* argv[])
{
  long int x, n, prod=1;
  char* pattern = "^[+-]?[0-9]+$";
  if(argc == 3)
  {
   if(match(argv[1],pattern) && match(argv[2],pattern))
   {
     x = atoi(argv[1]);
     n = atoi(argv[2]);
    if(n >= 0)
    {
    /* Iterative logic
      while(n != 0)
     {
       prod = x*prod;
       n--;
     }*/
     printf("\n %s to the power of %s is %ld\n", argv[1], argv[2], power(x,n));
    }
    else
     printf("\nUsage: ./cs1713-day1-prog5.o int positiveInt\n");
   }
   else
    printf("\nUsage: ./cs1713-day1-prog5.o int positiveInt\n");
  }
  else
    printf("\nUsage: ./cs1713-day1-prog5.o int positiveInt\n");
  
  return 0;
}
