#include <stdio.h>
#include <float.h>
#include <locale.h>
#include <math.h>

int main1(void) {
    float z=1;
    float t=2;
    float y=t+z;
    float x=NAN;
    if (fabsf(y+t*t)>FLT_EPSILON){
        x = (8*z*z+1)/(y+t*t);
    } else {
        return -1;
    }
    printf("x = %f",x);
    return 0;
}

float sqrf (float x){
    return x*x;
}

int signf(float x){
    if (fabsf(x)<FLT_EPSILON){return 0;}
    if (x>0){return 1;}
    return -1;
}

int Circle(float x, float y, float xCenter, float yCenter, float Radius){
    return signf(sqrf(x-xCenter)+sqrf(y-yCenter)-sqrf(Radius));
}

int impl(int a,int b){
    if (a && !b){ return 0;}
    return 1;
}

int main2(void){
    float x,y;
    printf("Введите x: "); scanf("%f",&x);
    printf("Введите y: "); scanf("%f",&y);

    if ((fabsf(x)<=1)&&(fabsf(y)<=1)&&(signf(x*y)<=0)&&(impl(signf(x)==1,Circle(x,y,0,0,1)<=0))){
        printf("В фигуре");
    } else {
        printf("Вне фигуры");
    }
    return 0;
}

int main3(void){
    float a, x, y;
    printf("Введите a: "); scanf("%f",&a);
    printf("Введите x: "); scanf("%f",&x);

    if (a<=x){
        y = a+logf(x+a);
    } else {
        if (sinf(a*x)<0) return -2;
        y = sqrtf(sinf(a*x));
    }
    float t = 0;
    switch (signf(a-y)) {
        case 0:
            if (signf(y)){t += (a+x)/(y*y);} else {return -1;}
        case 1:
            if (signf(a-x)!=0){t+=y/(a-x);} else {return -1;}
            break;
        case -1:
            t = tanf(a*x)+cosf(2*a*y);
    }
    printf("a = %f, x = %f, y = %f, t = %f",a,x,y,t);
    return 0;
}

int main(void){
    int N = 1;
    int (*tasks[])(void) = {main1,main2,main3};
    setlocale(LC_ALL,"Russian");
    while (N){
        printf("Пожалуйста, выберите номер задания"); scanf("%d",&N);
        if (N<0 || N>3){
            printf("Некорректный номер задания");
            continue;
        }
        if (N>0){
            int result = tasks[N-1]();
            switch (result) {
                case 0: printf("Процесс успешно завершился"); break;
                case 1: printf("Ошибка 1. Введены некорректные данные - произошло деление на 0."); break;
                case 2: printf("Ошибка 2. Введены некорректные данные - произошло взятие квадратного корня из отрицательного числа."); break;
                default: printf("Произошла неизвестная ошибка %d", result);
            }
        }
    }
    return 0;
}