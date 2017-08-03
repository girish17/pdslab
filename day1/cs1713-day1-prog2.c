/*-----------------------------------
Name: Girish M
Roll number: cs1713
Date: 25 July 2017
Program description: Swap the values of two variables. How many ways of swapping do
you know? For each method of swap, determine the pros and cons.
Acknowledgements:http://pubs.opengroup.org/onlinepubs/7908799/xsh/regcomp.html
------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <regex.h>

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

int main(int argc, char* argv[])
{
  int num1, num2;
  char* pattern = "^[+-]?[0-9]+$";
  /*check whether number or not*/
  if(argc == 3)
  {
    if(match(argv[1], pattern) && match(argv[2], pattern))
    {
     num1 = atoi(argv[1]);
     num2 = atoi(argv[2]);
     printf("\nBefore swapping integer1: %d integer2: %d\n", num1, num2);
     /*swap w/o temporary variable*/
     num1 = num1 + num2;
     num2 = num1 - num2;
     num1 = num1 - num2;
     printf("\nAfter swapping integer1: %d integer2: %d\n", num1, num2);
    }
    else
    {
      printf("\n./cs1713-day1-prog2.c integer1 integer2\n");
    }
  }
  else
  {
    printf("\n./cs1713-day1-prog2.c integer1 integer2\n");
  }
  return 0;
}
