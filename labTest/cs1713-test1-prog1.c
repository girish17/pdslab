#include "common.h"

typedef struct STUDENT{
  char rollNo[6];
  unsigned int atd_per;
  float agg_per;
  char fname[100];
  char lname[100];
} STUDENT;

int initStudentRecord(char* txtFile, STUDENT* st)
{
   FILE* fp;
   char *line = NULL;
   size_t len = 80;
   size_t read;
   char* saveptr1, *saveptr2;
   int count = 0;
   const char* delim = " ";

   float highest_agg = 0.0;
   float lowest_agg = 100.0;
   char fnameHighest[100];
   char lnameHighest[100];
   char fnameLowest[100];
   char lnameLowest[100];


   if(NULL == (fp = fopen(txtFile,"r")))
   {
     printf("\nError opening file\n");
   }
   else
   {
    while((read = getline(&line, &len, fp)) != -1) 
    {
       strcpy(st[count].rollNo, strtok(line, delim));
       st[count].atd_per = atoi(strtok(NULL, delim));
       st[count].agg_per = atof(strtok(NULL, delim));
       strcpy(st[count].fname,strtok(NULL, delim));
       strcpy(st[count].lname,strtok(NULL, delim));
       if(st[count].agg_per > highest_agg)
       {
         strcpy(fnameHighest, st[count].fname);
         strcpy(lnameHighest, st[count].lname);
         highest_agg = st[count].agg_per;
       }
       else if(st[count].agg_per <= lowest_agg)
       {
         strcpy(fnameLowest, st[count].fname);
         strcpy(lnameLowest, st[count].lname);
         lowest_agg = st[count].agg_per;
       }
       count++;
    }
    printf("\nStudent with highest aggregate percentage score: %s %s\n", fnameHighest, lnameHighest);
    printf("\nStudent with lowest aggregate percentage score: %s %s\n", fnameLowest, lnameLowest);

   }
   fclose(fp);
   return count;
}

int main(int argc, char* argv[])
{
 if(argc == 2)
 {
      STUDENT st[30];
      if(initStudentRecord(argv[1], st) == 30)
      {

      }
      else
          printf("%s not in correct format", argv[1]);
 }
 else
 {
  printf("\nUsage: ./cs1713-test1-prog1.o file.txt\n");
 }
 return 0;
}
