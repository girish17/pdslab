#include "common.h"

int main(int argc, char* argv[])
{
 if(argc == 2)
 {
   FILE* fp;
   char *line = NULL;
   size_t len = 0;
   ssize_t read;
   char* token;
   char* saveptr1;
   int keywords = 0/*, i=0*/;
   const char* delim = "{\"\'=*;:()| ";
   char* keywordsInC[] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
   int i=0;
   if(NULL == (fp = fopen(argv[1],"r")))
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
        if(strcmp(token, keywordsInC[i]) == 0)
        {
          keywords++; 
        }
      }
    }
    printf("\nNo. of keywords: %d\n", keywords);
   }
 }
 else
 {
  printf("\nUsage: ./cs1713-day4-prog2.o cFile\n");
 }
 return 0;
}
