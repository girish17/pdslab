#include "common.h"

int* countKeywordOccurances(const char* keywords[], char* cFile)
{
   FILE* fp;
   char *line = NULL;
   size_t len = 0;
   ssize_t read;
   char* token;
   char* saveptr1;
   const char* delim = "{\"\'=*;:()| ";
   int i;
   static int count[32];

   if(NULL == (fp = fopen(cFile,"r")))
   {
     token = NULL;
     printf("\nError opening file\n");
   }
   else
   {
    while((read = getline(&line, &len, fp)) != -1)
    {
      token = strtok_r(line, delim, &saveptr1);
      for(i=0; i<32; i++)
      {
        if(strcmp(token, keywords[i]) == 0)
        {
          count[i]++; 
        }
      }
     }
   }
   fclose(fp);
   return count;
}

int main(int argc, char* argv[])
{
 const char* keywordsInC[] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
 
 if(argc == 2)
 {
   int i=0, totalKeywords=0;
   static int* countOfKeywords;
   countOfKeywords = countKeywordOccurances(keywordsInC, argv[1]);
   printf("\n**************************************************************************\n");
   for(i=0; i<32; i++)
   {
     if(countOfKeywords[i] > 0)
     {
       printf("\nNo.of times %s keyword occurs: %d\n", keywordsInC[i], countOfKeywords[i]);
       totalKeywords = totalKeywords + countOfKeywords[i];
     }
   }
   printf("\nTotal no. of occurrances of keywords in %s: %d\n", argv[1], totalKeywords);
   printf("\n***************************************************************************\n");
 }
 else
 {
  printf("\nUsage: ./cs1713-day4-prog2.o cFile\n");
 }
 return 0;
}
