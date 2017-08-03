#include <stdio.h>

int main(void)
{
  int i;
  for(i=0; i<10; i++)
  printf("abcdefghijklmnop\n"+i);\
  char *t;
  t="hello";
  while(*t++) {
  putchar(*t);
  }
}
