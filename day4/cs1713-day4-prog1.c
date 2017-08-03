#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h> 

typedef struct complexNum
{
  float rez;
  float imz;
}complexNum;

complexNum* rootOfQuadratic(float a, float b, float c)
{
  //printf("\nEntered values of a,b and c are  %f %f and %f", a, b, c);
  double d;
  complexNum* compNum;
  compNum = (complexNum*)malloc(sizeof(complexNum)*2);
  if(a != 0)
  {
    d = (b*b)-(4*a*c);
    printf("\nValue of discriminant: %.2lf\n", d);
    if(d < 0)
    {
      /*Imaginary roots*/
      printf("\nComplex roots exist in conjugate pairs.\n");
      compNum[0].rez = ((-1)*b/(2*a));
      compNum[1].rez = compNum[0].rez;
      compNum[0].imz = d/(2*a);
      compNum[1].imz = compNum[0].imz;
    }
    if(d == 0)
    {
      /*Real and equal roots*/
      printf("\nReal and equal roots exist.\n");
      double s = sqrt(d);
      compNum[0].rez = ((-1)*b+s)/(2*a);
      compNum[1].rez = compNum[0].rez;
      compNum[0].imz = 0;
      compNum[1].imz = 0;
    }
    else if(d > 0)
    {
      /*Real and non-equal roots*/
      printf("\nReal and non equal roots exist.\n");
      double s = sqrt(d);
      compNum[0].rez = ((-1)*b+s)/(2*a);
      compNum[1].rez = ((-1)*b-s)/(2*a);
      compNum[0].imz = 0;
      compNum[1].imz = 0;
    }
    return compNum;
  }
  else
    return 0;
}

int main(int argc, char* argv[])
{
  complexNum* compNum;
  if(argc == 4)
  {
    float a = atof(argv[1]);
    float b = atof(argv[2]);
    float c = atof(argv[3]);
    compNum = rootOfQuadratic(a, b, c);
    if(compNum != 0)
     printf("\nRoots of %.2fx^2 + %.2fx + %.2f is\n %.2f+i(%.2f) & %.2f-i(%.2f)\n", a, b, c, compNum[0].rez, compNum[0].imz, compNum[1].rez, compNum[1].imz);
    else
     printf("\nNot a quadratic equation\n");
  }
  else
  {
    printf("\nUsage: ./cs1713-day4-prog1.o a b c\n");
    return -1;
  }
  return 0;
}
