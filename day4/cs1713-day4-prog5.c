/*---------------------------------------------------------------------------
Name: Girish M
Roll number: cs1713
Date: 1 August 2017
Program description: Let s and t be strings containing at most 100 characters.
Implement the following functions in C:
(a) strlen(s): returns the length of s, i.e., the number of characters
present in s;
(b) strcmp(s, t): returns 1 if s and t are identical, 0 otherwise;
(c) diffByOne(s, t): returns 1 if s and t are of the same length, and
differ in exactly one position, 0 otherwise.
Acknowledgements:
---------------------------------------------------------------------------*/

#include <stdio.h>

int strlength(char* str)
{
  int len=0;
  while(*str++ != '\0')
    len++;
  return len;
}
int strcompare(char* s, char* t)
{
  while(*s != '\0')
  {
    if(*s != *t)
    {
      return 0;
    }
    s++;
    t++;
  }
  return 1;
}
int diffByOne(char* s, char* t)
{
 int numDiff=0;
 if(strlength(s) == strlength(t))
 {
   while(*s != '\0')
   {
     if(*s != *t)
     {
       numDiff++;
     }
     s++;
     t++;
   }
  if(numDiff == 1)
    return 1;
  else
    return 0;
 }
 else 
   return 0;
}

int main(int argc, char* argv[])
{
 //const int size_str = 100;
 if(argc == 3)
 {
    printf("\nstrlen(%s) is %d\n", argv[1], strlength(argv[1]));
    printf("\nstrlen(%s) is %d\n", argv[2], strlength(argv[2]));
    printf("\nstrcmp(%s, %s): %d\n", argv[1], argv[2], strcompare(argv[1], argv[2]));
    printf("\ndiffByOne(%s, %s): %d\n", argv[1], argv[2], diffByOne(argv[1], argv[2]));
 }
 else
    printf("\nUsage: ./cs1713-day3-prog1.o str1 str2\n");
 return 0;
}
