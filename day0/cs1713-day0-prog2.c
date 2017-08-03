/*-----------------------------------
Name: Girish M
Roll number: MTech CS 13
Date: 20/07/2017
Program description: Calculate area of triangle using coordinates
Acknowledgements: Hero's formula
------------------------------------*/
#include <stdio.h>
#include <math.h>

float areaTriangle(float []);
const unsigned length = 6;
int main(void)
{
	float cdn[length];
	unsigned i;
	printf("\nEnter 3 coordinates of triangle (x1,y1), (x2,y2) and (x3,y3)\n");
	for(i=0; i<length; i++)
	{
	  scanf("%f", &cdn[i]);
	}
	printf("\nThe area of triangle is: %.3f\n", areaTriangle(cdn));
	return 0;
}

/*Ar. triangle = 1/2 * (x1(y2-y3)-y1(x2-x3)+(x2*y3-y2*x3))*/

float areaTriangle(float cdn[])
{
	return fabs((0.5*(cdn[0]*(cdn[3]-cdn[5])-(cdn[1]*(cdn[2]-cdn[4]))+(cdn[2]*cdn[5]-cdn[3]*cdn[4]))));
}

