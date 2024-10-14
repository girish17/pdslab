#include <stdio.h>
#include <stdlib.h>

int oddEven(int num) {
  int odd, even;
  static int functionCalls;
  functionCalls++;
  if(num == 2) {
    printf("f(%d) = 1.\n", num);
  } else if(num%2 == 0) {
    even = num/2;
    printf("f(%d) = %d, \n", num, even);
    oddEven(even);
  } else {
    odd = 3*num + 1;	  
    printf("f(%d) = %d, \n", num, odd);
    oddEven(odd);
  }
  return functionCalls;
}

int main(int argc, char** argv) {
  int num, functionCalls;
  if(argc > 1) {
    num = atoi(argv[1]);
    functionCalls = oddEven(num);
    printf("\n %d\nf", functionCalls);
    while(functionCalls != 0) {
      printf(" ");
      functionCalls /= 10;
    }
    printf("(%d) = 1\n",  num);
  } else {
    printf("./oddEven.o <num>\n");
  }
  return 0;
}
