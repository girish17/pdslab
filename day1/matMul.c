#include <stdio.h>
#include <malloc.h>

int main(void)
{
 unsigned int m, n, i, j, k=1;
 int* a;
 printf("\nEnter the size of matrix:\n");
 printf("\nNo. of rows:\n");
 scanf("%u", &m);
 printf("\nNo. of cols:\n");
 scanf("%u", &n);
 a = (int*) malloc(sizeof(int)*m*n);
 if(NULL != a)
 {
   for(i=0; i<m; i++)
  {
   for(j=0; j<n; j++)
   {
     printf("\nEnter element a[%d][%d]: \n", i+1, j+1);
     printf("\nloc: %d\n", i+j+k);
     scanf("%d", &a[i+j+k]);
   }
   k=k+n-1;
  }
  printf("\nEntered array:\n");
  k=1;
  for(i=0; i<m; i++)
  {
   for(j=0; j<n; j++)
   {
     printf("%d ", a[i+j+k]);
   }
   printf("\n");
   k=k+n-1;
  }
  free(a);
 }
 return 0;
}
