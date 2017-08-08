/*------------------------------------------------------------------------------------------------------------------
 Name: Girish M
 Roll number: cs1713
 Date: 1 August 2017
 Program description: Write a function uniquify that
 (a) takes two arguments: an array 'a' containing at most 100 non-negative integers, and 'n', the number of integer
     contained in the array, and
 (b) stores in 'a' a list of the distinct integers contained in 'a' if the integers in 'a' are sorted in increasing order, and returns the number of distinct integers in 'a';
 (c) returns -1 otherwise.
 Acknowledgements:
 ------------------------------------------------------------------------------------------------------------------*/

#include "common.h"
#include <regex.h>

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

int uniquify(int *a, int n)
{
    int i;
    int no_distinct_int = 1;
    /*printf("\nNo. of non-negative integers: %d, starting with %d and ending with %d\n",n, a[1], a[n-1]);*/
    for(i=1; i<n-1; i++)
    {
            if(a[i] != a[i+1])
            {
	      no_distinct_int++; 
              /*printf(" %d %d : %d ",a[i], a[i+1], n);*/
            }
    }
    if(no_distinct_int > 0)
        return no_distinct_int;
    else if(no_distinct_int == 1)
        return 1;
    else
        return -1;
}

int main(int argc, char* argv[])
{
    const int arr_size = 100; /*at most 100 elements*/
    int arr[arr_size], i=1;
    int retVal, num1, num2;
    char isInIncreasingOrder = 1;
    char* pattern = "^[+]?[0-9]+$";

    if((argc >  1) && (argc < arr_size+1))
    {
        /*check if args in increasing order*/
        while(i != (argc-1))
        {
          if(match(argv[i],pattern))
          {
            if(match(argv[i+1],pattern))
            {
               num1 = atoi(argv[i]);
               num2 = atoi(argv[i+1]);
               if(num1 > num2)
               {
                 isInIncreasingOrder = 0;
               }
               else
               {
                 arr[i] = num1;
                 arr[i+1] = num2;
               }
            }
            else
               printf("\n%s is not a valid number. Will be considered as zero.\n", argv[i+1]);
          }
          else
          {
            printf("\n%s is not a valid number. Will be considered as zero.\n", argv[i]);
          }
          i++;
        }
        if(isInIncreasingOrder)
        {
            /*printf("\nFollowing numbers are in increasing order:\n");
            for(i=1; i<argc; i++)
              printf(" %d ", arr[i]);*/
            retVal = uniquify(arr, argc);
            if(retVal != -1)
            {
                printf("\nNo. of distinct integers %d\n", retVal);
            }
            else
                printf("\nNo distinct integers\n");
        }
        else
            printf("\nPositive integer arguments not in increasing order.\n");
    }
    else
        printf("\nUsage: ./cs1713-day3-prog1.o positiveInt1 ... positiveInt100\n");
    return 0;
}
