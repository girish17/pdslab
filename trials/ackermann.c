/*
 * Ackermann's function is defined recursively by
 * a(i,n) = if i=0 then n+1
 *          else if n=0 then a(i-1,1)
 *          else a(i-1, a(i,n-1))
 */

#include <stdio.h>
#include <stdlib.h>

int A1(int m, int n) {
  return ((m==0) ? n+1 : ((n==0) ? A1(m-1, 1) : A1(m-1, A1(m, n-1))));
}

int A(int m, int n) {
  printf("\nCalculating A(%d,%d)", m, n);
  if(m==0)
    return n+1;
  if(n==0)
    return A(m-1,1);
  else
    return A(m-1, A(m, n-1));
}

int main(int argc, char** argv) {
  int m, n;
  if(argc == 3) {
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    
    if(m >= 0 && n >= 0) {
      printf("\nA(%d, %d) is %d\n", m, n, A(m,n));
      //printf("\nA1(%d, %d) is %d\n", m, n, A1(m,n));
    }
    else {
      printf("m and n should non-negative\n");
    }
  } else {
    printf("Invalid input. Try ./ackermann.out <non-negative integer> <non-negative integer>\n");
  }
  return 0;
}
