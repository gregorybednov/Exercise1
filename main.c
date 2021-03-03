#include <stdio.h>
#include <float.h>
#include <math.h>

int main() {
    float z=1;
    float t=2;
    float y=t+z;
    float x=NAN;
    if (fabs(y+t*t)>FLT_EPSILON){
        x = (8*z*z+1)/(y+t*t);
    }
    printf("x = %f",x);
    return 0;
}
