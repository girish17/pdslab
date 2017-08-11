#include "common.h"

int *A, N;

int isConnected (int x, int y) {
    return (A[x] == A[y]);
}

void createUnion (int x, int y) {
    int xid = A[x];
    int yid = A[y];
    int i;

    for (i = 0; i < N; i++) {
        if (A[i] == xid)
            A[i] = yid;
    }
}

int main (int argc, char **argv) {

    FILE *fp;
    int i, x, y;

    /* sanity check of command line arguments */
    if (argc < 2) 
        ERR_MESG ("Usage: ./unionFind networkFileName");

    /* Read data from network.txt */
    if (NULL == (fp = fopen (argv[1], "r")))
        ERR_MESG ("Error Opening file");

    fscanf (fp, "%d", &N);

    /* initialise the arrays */
    if (NULL == (A = Malloc (N, int)))
        ERR_MESG("main: out of memory\n");

    for (i = 0; i < N; i++)
        A[i] = i;

    for (i = 0; i < N; i++)
        printf ("%d ", A[i]);
    printf ("\n");
    
    /* Read and build the network */
    while (1) {
        int retCount = fscanf (fp, "%d %d", &x , &y);

        /* this will break out of the while loop at the last line */
        if (retCount != 2) break;

        printf ("%d %d\n", x, y);

        /* Check if already connected */
        if (!isConnected (x, y)) {
            /* Create their union */
            createUnion(x, y);

            for (i = 0; i < N; i++)
                printf ("%d ", A[i]);
            printf ("\n");
        }
    }

    fclose (fp);
    return 0;
}
