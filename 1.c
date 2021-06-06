#include <stdio.h>
#include <float.h>
#include <math.h>

int main(void) {
	double z = 1;
	double t = 2;
	double y = t + z;
	double x = 0;
	if (fabs(y+t*t)<=DBL_EPSILON) return 1;
	x = (8*z*z+1)/(y+t*t);
	printf("x = %f\n",x);
	return 0;
}
