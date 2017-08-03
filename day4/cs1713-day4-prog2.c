#include "common.h"

int main(int argc, char* argv[])
{
 if(argc == 2)
 {
   FILE* fp;
   char *line = NULL;
   size_t len = 0;
   ssize_t read;
   char* token/*, *subtoken, *str*/;
   char* saveptr1/*, *saveptr2*/;
   int keywords = 0/*, i=0*/;
   const char* delim = " ";

   if(NULL == (fp = fopen(argv[1],"r")))
   {
     token = NULL;
     printf("\nError opening file\n");
   }
   else
   {
    while((read = getline(&line, &len, fp)) != -1)
    {
      //printf("Retrieved line of length %zu :\n", read);
      //printf("%s", line);
      token = strtok_r(line, delim, &saveptr1);
      //printf("\nTokens: \n");
 
      /*for(str=token; ;str=NULL)
      {*/
        printf(" %s ", token);
        printf("\n%zu number of tokens\n", strlen(token));
        /*subtoken = strtok_r(str, delim, &saveptr2);
        if(subtoken == NULL)
          break;
        printf(" %s ", subtoken);
      }*/
      keywords += strlen(token);
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
