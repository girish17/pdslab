#include "common.h"

int main(int argc, char* argv[])
{
 if(argc == 2)
 {
   FILE* fp;
   char *line = NULL;
   size_t len = 0;
   ssize_t read/*, readKey*/;
   char* token/*, *subtoken, *str*/;
   char* saveptr1/*, *saveptr2*/;
   int keywords = 0/*, i=0*/;
   const char* delim = " ";
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
      while(i != 32)
      {
        printf("\nchecking for %s\n", keywordsInC[i]);
        if(strstr(token, keywordsInC[i]))
         keywords++;
        i++;  
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
