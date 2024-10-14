#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n) {
    return (n==0) ? m : gcd(n, m%n) ;
}

int gcd1(int m, int n) {
    return (n==0) ? m : ((m >= n) ? gcd1(m-n, n) : gcd1(n, m));
}

int gcd_iter(int m, int n) {
    while( n != 0 ) {
      if(m >= n) {
         m = m-n;
      } else {
         m = m ^ n;
	 n = m ^ n;
	 m = m ^ n;
      }
    }
    return m;
}

int main(int argc, char** argv) {
    int num1, num2;
    if(argc == 3) {
       num1 = atoi(argv[1]);
       num2 = atoi(argv[2]);
       if(num1 >= 0 && num2 >= 0) {
          printf("GCD of %s and %s is %d \n", argv[1], argv[2], gcd_iter(num1, num2));
       } else {
          printf("Both the integers must be non-negative.\n");
       }
    } else {
       printf("Invalid input. Usage: ./gcd.o num1 num2\n");
    }
    return 0;
}
