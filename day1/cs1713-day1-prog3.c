/*----------------------------------
Name: Girish M
Roll number: cs1713
Date: 25 July 2017
Program description: Sum of n integers
Acknowledgements:http://pubs.opengroup.org/onlinepubs/7908799/xsh/regcomp.html
------------------------------------*/
#include <stdio.h>
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
  int i, sum=0;
  char* pattern = "^[+-]?[0-9]+$";
  if(argc > 1)
  {
    for(i=1; i<argc; i++)
    {
     if(match(argv[i], pattern))
      sum = sum + atoi(argv[i]);
     else
      printf("\n%s is not an integer. Excluding in sum.\n", argv[i]);
    }
    printf("\nSum is %d\n", sum);
  }
  else
  {
    printf("\nUsage: ./cs1713-day1-prog3.o int1 int2 ...\n");
  }
  return 0;
}
