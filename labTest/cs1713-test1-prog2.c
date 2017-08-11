#include "common.h"

char isPermutation(char* str1, char* str2)
{
  int i = 0, j = 0;
  char alpha = 'a';
  static int charFreq1[26], charFreq2[26];
  if(strlen(str1) == strlen(str2))
  {
     while((*(str1+i) != '\0') && (*(str2+i) != '\0'))
     {
       charFreq1[*(str1+i)-alpha]++;
       charFreq2[*(str2+i)-alpha]++;
       i++;
     }
     for(j=0; j<strlen(str1); j++)
     {
       if(charFreq1[j] != charFreq2[j])
       {
         return 0;
       }
     }
     return 1;
  }
  else
     return 0;
}

int main(int argc, char* argv[])
{
  if(argc == 3)
  {
    if(isPermutation(argv[1], argv[2]))
      printf("YES\n");
    else
      printf("NO\n");
  }
  else
      printf("\nUsage: ./cs1713-test1-prog2.o str1 str2\n");
  return 0;
}
