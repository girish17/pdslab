#include "common.h"

int main(int argc, char* argv[])
{
  if(argc == 3)
  {
    FILE* fptr;
    int c, num_bytes = 0;
    if((fptr = fopen(argv[2], "r")))
    {
      while((c = fgetc(fptr)) != -1)
      {
        num_bytes++;
        if((num_bytes % atoi(argv[1])) == 0)
        {
           printf("\n");
        }
        else
          printf("%.2X ", c);
      }
      printf("\n");
      fclose(fptr);
    }
    else
        printf("\nCould not open %s\n", argv[2]); 
  } 
  else
      printf("\nUsage: ./cs1713-test1-bonus.o num_bytes fileName\n");
  return 0;
}
