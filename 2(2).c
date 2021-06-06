#include <stdio.h>
#include <float.h>
#include <math.h>

#define LOG_ARG_LT_0 1
#define SQRT_ARG_LT_0 2
#define DENUM_EQ_0 3

int sign (float x) {
	if (fabs(x)<DBL_EPSILON) return 0;
	if (x>0) return 1;
	return -1;
}

int error (int errid) {
	switch (errid) {
		case LOG_ARG_LT_0:
			fprintf(stderr, "Log argument is less than 0");
			break;
		case SQRT_ARG_LT_0:
			fprintf(stderr, "Sqrt argument is less than 0");
			break;
		case DENUM_EQ_0:
			fprintf(stderr, "Dividing on zero");
			break;
	}
	return errid;
}


int main(void){
	double a, x, y, t;
		
	printf("a := "); scanf("%lf",&a);
	printf("x := "); scanf("%lf",&x);
	if (a<=x){
		if ((x+a)<0) return error(LOG_ARG_LT_0);
		y = a+log(x+a);
	} else {
		if (sin(a*x)<0) return error(SQRT_ARG_LT_0);
		y = sqrt(sin(a*x));
	}
	t = 0;
	printf("y = %f", y);
	switch (sign(a-y)) {
		case 0:
			if (sign(y) == 0) return error(DENUM_EQ_0);
			t += (a+x)/(y*y);
			[[fallthrough]];
		case 1:
			if (sign(a-x) == 0) return error(DENUM_EQ_0);
			t += y/(a-x);
			break;
		case -1:
			t = tan(a*x)+cos(2*a*y);
	}
	printf("a = %f, x = %f, y = %f, t = %f\n", a, x, y, t);
	return 0;
}
