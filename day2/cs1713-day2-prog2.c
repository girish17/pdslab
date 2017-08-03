#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <malloc.h>

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

typedef struct
{
 int value;
 int loser[200];
 int numLoser;
}loserList;

int main(int argc, char* argv[])
{
 int i = 1, j = 0, k=0;
 char* pattern = "^[+]?[0-9]+$";
 if(argc > 1)
 {
  loserList* l;
  l = (loserList*) malloc(sizeof(loserList)*(argc-1));
  while(argv[i] != NULL)
  {
    if(match(argv[i],pattern))
    {
      l[k].value = atoi(argv[i]);
      //l[k].loser = (int*)malloc(sizeof(int)*(argc-1));
      l[k].numLoser = 0;   
    }
    else
    {
      printf("\n%s is not a valid number. Will be considered as zero.\n", argv[i]);
    }
    i++;
    k++;
  }
  /*printf("\nEntered numbers are:\n");
  k=0;
  while(j != (argc-1))
  {
   printf("%d ", l[j].value);
   j++;
  }*/
  int indexOfMax=0, m;
  int max = l[indexOfMax].value;
  k=0;
  while(j != (argc-1))
  {
   if(l[j].value >= max)
   {
     max = l[j].value;
     indexOfMax = j;
     k=0;
   }
   else
   {
     if(indexOfMax <= j)
     {
       //check for all other elements
       for(m=0;m<(argc-1); m++)
       {
        if((l[indexOfMax].value > l[m].value) && ((m < indexOfMax)))
        {
         l[indexOfMax].numLoser++;
         l[indexOfMax].loser[k] = l[m].value;
         k++; 
        }
       }
     }
   }
   j++;
  }
  printf("\nMax element is %d\n", l[indexOfMax].value);
  printf("\nIndex of max: %d\n", indexOfMax);
  //second max element
  // traverse the losers list of max element
  printf("\nSize of losers list %d\n",l[indexOfMax].numLoser);
  printf("\nLosers list of max element\n");
  for(i=0; i<k ; i++)
  {
    printf(" %d ", l[indexOfMax].loser[i]);
  }
  printf("\n");
 }
 else
   printf("\nUsage: ./cs1713-day2-prog2.o ele1 ele2 ...\n");
 return 0;
}
