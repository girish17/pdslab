/*------------------------------------------------------------------------------------------------------------
Name : Girish M
Roll : CS1713
Date : 13 Aug 2017
Desc : In a list of n elements, an element x is called the majority element if it appears more than n/2 times.
Write a C program that takes as input from the user a list (or string) of characters,
and finds the majority element in the list, if any. If there is no majority element, output NA.
Acks :
-------------------------------------------------------------------------------------------------------------*/
#include "common.h"

char* findMajority(char* str1)
{
  int i = 0;
  char alpha = 'a';
  static int charFreq1[26];
  
  while(*(str1+i) != '\0')
  {
       charFreq1[*(str1+i)-alpha]++;
       i++;
  }

  unsigned maxOccur = ceil((double)strlen(str1)/2);
   
  for(i=0; i<26; i++)
  {
    if(charFreq1[i] >= maxOccur)
    {
      char* ch;
      ch = (char*)malloc(sizeof(char));
      *ch = alpha+i;
      return ch;
    }  
  }
   
  return "NA";
}

int main(int argc, char* argv[])
{
  if(argc == 2)
  {
      printf("%s\n", findMajority(argv[1]));
  }
  else
      printf("\nUsage: ./cs1713-test1-prog2.o str1\n");
  return 0;
}
