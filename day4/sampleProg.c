/*Sample c program used to test cs1713-day4-prog2.o*/
#include "common.h"

int main(void)
{
  auto int i=0;
  for(i=0; i<100; i++)
  {
    static int j=9;
    switch(j)
    {
      case 9:
      break;
      default:
       exit(0);
    }
  }
  return 0;
}
