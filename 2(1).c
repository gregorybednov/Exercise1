#include <stdio.h>
#include <float.h>
#include <math.h>

double sqr (double x) {
	return x*x;
}

int sign (double x) {
	if (fabs(x)<DBL_EPSILON) return 0;
	if (x>0) return 1;
	return -1;
}

int inCircle (double x, double y, double xCenter, double yCenter, double r) {
	return sign(sqr(x-xCenter)+sqr(y-yCenter)-sqr(r));
}

int impl (int a,int b) {
	if (a && !b){ return 0;}
	return 1;
}

int main(void) {
	double x,y;
	printf("x := "); scanf("%lf",&x);
	printf("y := "); scanf("%lf",&y);
	if ((fabs(x)<=1)&&
	(fabs(y)<=1)&&
	(sign(x*y)<=0)&&
	(impl(sign(x)==1,inCircle(x,y,0,0,1)<=0))) {
		printf("in figure\n");
	} else {
		printf("out of figure\n");
	}
	return 0;
}
