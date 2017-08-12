/*-----------------------------------
Name: Girish M
Roll number: cs1713
Date: 25 July 2017
Program description: Take three positive integers x,n, and m from the user and compute (x power n) mod m.
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
 int x, n, m;
 /*long int prod = 1;*/
 char* pattern = "^[+-]?[0-9]+$";
 if(argc == 4)
 {
  if(match(argv[1], pattern) && match(argv[2], pattern) && match(argv[3], pattern))
  {
   x = atoi(argv[1]);
   n = atoi(argv[2]);
   m = atoi(argv[3]);
   if(n >= 0 && m > 0)
   {
    /* Iterative logic
    while(n != 0)
    {
      prod = prod * x;
      n--;
    }*/
    printf("\n (%s to the power of %s) mod %s is: %ld\n", argv[1], argv[2], argv[3], power(x,n)%m);
   }
   else
    printf("\nUsage: ./cs1713-day1-prog6.o int1 positiveInt1 positiveInt2\n");
  }
  else
  {
    printf("\nUsage: ./cs1713-day1-prog6.o int1 positiveInt1 positiveInt2\n");
  }
 }
 else
 {
    printf("\nUsage: ./cs1713-day1-prog6.o int1 positiveInt1 positiveInt2\n");
 }
 return 0;
}
