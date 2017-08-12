/*----------------------------------------------------------------------------------
Name : Girish M
Roll : CS1713
Date : 12 August 2017
Desc : A program to calculate inverse of a matrix (if it exists) of a square matrix.
Acks : http://www.sanfoundry.com/c-program-find-inverse-matrix/
-----------------------------------------------------------------------------------*/
#include "common.h"


/*Initialize an nxn matrix using dynamic memory allocation*/
float** initMatrix(float** M, float r)
{
   int i, j;
   M = (float**) malloc(sizeof(float)*r*r);
   for(i=0; i<r; i++)
   {
     M[i] = (float*) malloc(sizeof(float)*r);
   }
   //Initialize to zero
   for(i=0; i<r; i++)
   {
     for(j=0; j<r; j++)
     {
       M[i][j] = 0.0;
     }
   }
   return M;
}

char checkForIdentity(float** A, float** InverseA, float n)
{
 int i, j, k;
 char isIdentity = 0;
 float** Id = NULL;
 Id = initMatrix(Id, n);
 for(i=0; i<n; i++)
 {
   for(j=0; j<n; j++)
   {
     for(k=0; k<n; k++)
     {
      Id[i][j] = Id[i][j] + (A[i][k] * InverseA[k][j]);
     }
     printf("%d ", abs((int)Id[i][j]));
   }
   printf("\n");
 }

 //check if identity matrix
 for(i=0; i<n; i++)
 {
   for(j=0; j<n; j++)
   {
      if((Id[i][j] == 1) && (i==j))
      {
        isIdentity = 1;
      }
      else if(abs((int)Id[i][j]) == 0)
      {
        isIdentity  = 1;
      }
      else
      {
        return 0;
      }
   }
 } 
 return isIdentity;
}


/*For calculating Determinant of the Matrix */
float determinant(float** a, float k)
{
  float s = 1, det = 0;
  float** b = NULL;
  int i, j, m, n, c;
  b = initMatrix(b, k);
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    }
    free(b);
    return (det);
}

/*Finding transpose of matrix*/ 
void transpose(float** num, float** fac, float r)
{
  int i, j;
  float**b=NULL, **inverse=NULL, d;
  b = initMatrix(b, r);
  inverse = initMatrix(inverse, r);
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         b[i][j] = fac[j][i];
        }
    }
  d = determinant(num, r);
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
        inverse[i][j] = b[i][j] / d;
        }
    }
   printf("\n\n\nThe inverse of matrix is : \n");
 
   for (i = 0;i < r; i++)
   {
      for (j = 0;j < r; j++)
      {
        printf("%6.2f", inverse[i][j]);
      }
      printf("\n");
   }

   printf("\nMultiplying A and A inverse...\n");
   if(checkForIdentity(num, inverse, r))
     printf("\nResult is identity matrix.\n");
   else
     printf("\nResult is not identity matrix.\n");
   free(b);
   free(inverse);
}

 
void cofactor(float** num, float f)
{
 float** b = NULL, **fac = NULL;
 int p, q, m, n, i, j;
 b = initMatrix(b, f);
 fac = initMatrix(fac, f);
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpose(num, fac, f);
}

int main(int argc, char* argv[])
{
  float** a = NULL, k, d;
  int i, j;
  if(argc == 2)
  {
    k = atoi(argv[1]);
    a = initMatrix(a, k);
    printf("Enter the elements of %.0f X %.0f Matrix : \n", k, k);
    for (i = 0;i < k; i++)
    {
     for (j = 0;j < k; j++)
     {
        scanf("%f", &a[i][j]);
     }
    }
    d = determinant(a, k);
    if (d == 0)
      printf("\nInverse of Entered Matrix is not possible\n");
    else
      cofactor(a, k);
    free(a);
  }
  else
      printf("\nUsage: ./prob2.o positiveInt\n");
   
  return 0;
}

