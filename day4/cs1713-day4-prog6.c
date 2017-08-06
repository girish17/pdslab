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

int uniquify(int *a, int n)
{
    int i, no_distinct_int = 0;
    for(i=0; i<n; i++)
    {
        if(a[i] != -1)
          no_distinct_int++;
        for(j=i+1; j<n; j++)
        {
            if(a[i] == a[j])
                a[j] = -1;
        }
    }
    if(no_distinct_int > 0)
        return no_distinct_int;
    else
        return -1;
}

int main(int argc, char* argv[])
{
    const int arr_size = 100 /*at most 100 elements*/
    int arr[arr_size], i=1;
    int retVal;
    char isInIncreasingOrder = 1;
    if((argc >  1) && (argc < arr_size+1))
    {
        /*check if args in increasing order*/
        while(i != (argc-1))
        {
            if(argv[i] > argv[i+1])
            {
                isInIncreasingOrder = 0;
            }
            i++;
        }
        if(isInInceasingOrder)
        {
            retVal = uniquify(arr, argc-1);
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
