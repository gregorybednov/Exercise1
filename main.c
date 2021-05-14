#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <locale.h>
#include <math.h>
#include <time.h>

int main1(void) {
    float z=1;
    float t=2;
    float y=t+z;
    float x=0;
    if (fabsf(y+t*t)>FLT_EPSILON){
        x = (8*z*z+1)/(y+t*t);
    } else {
        return 1;
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
    float a, x, y, t;
    printf("Введите a: "); scanf("%f",&a);
    printf("Введите x: "); scanf("%f",&x);

    if (a<=x){
        if ((x+a)<0){return 3;}
        y = a+logf(x+a);
    } else {
        if (sinf(a*x)<0) return 2;
        y = sqrtf(sinf(a*x));
    }
    t = 0;
    switch (signf(a-y)) {
        case 0:
            if (signf(y)){t += (a+x)/(y*y);} else {return 1;}
        case 1:
            if (signf(a-x)!=0){t+=y/(a-x);} else {return 1;}
            break;
        case -1:
            t = tanf(a*x)+cosf(2*a*y);
    }
    printf("a = %f, x = %f, y = %f, t = %f",a,x,y,t);
    return 0;
}

void free_matr (int **matr, size_t N) {
        size_t x;
        for (x=0; x<N; x++) free(matr[x]);
        free(matr);
}

int alloc_matr(int ***p_mem, size_t n, size_t m){
        size_t i;
        *p_mem = malloc(sizeof(int*)*n);
        if (*p_mem==NULL) { return 4; }
        for (i=0; i<n; i++)
                if (((*p_mem)[i] = malloc(sizeof(int)*m)) == NULL) {
                        free_matr(*p_mem,i); return 4;
                }
        return 0;
}

int rand_frAtoB (int A, int B){
        return rand()%(B+1-A)+A;
}

void fill_matr(int **matr, size_t N, size_t M) {
        size_t i, j;
        for (i=0; i<N; i++)
                for (j=0; j<M; j++)
                        matr[i][j] = rand_frAtoB(-10,10);
}

void print_matr(int **matr, size_t N, size_t M) {
        size_t i, j;
        for (i=0; i<N; i++){
                for (j=0; j<M; j++) printf("%4d", matr[i][j]);
                printf("\n");
        }
}

int main4(void){
        int **matr;
        size_t N = 10;
        size_t M = N;
        size_t minNM;
        size_t i, j;
        long int curr, currMax;
        int res;
        if (N<M) minNM = N; else minNM = M;
        if (res = alloc_matr(&matr, N, M)) return res;
        currMax = (long int)(matr[N-1][0]);
        fill_matr(matr, N, M);
        print_matr(matr, N, M);printf("\n");
        for (i=N-1; i>0; i--){
                size_t offset = 0;
                curr = 0;
                for (j=0; (j<M)&&((i+offset)<N); j++){
                        curr+=matr[i+offset][j];
                        offset++;
                }
                if (curr>currMax) currMax = curr;
        }
        for (j=M-1; j>0; j--){
                size_t offset = 0;
                curr = 0;
                for (i=0; ((j+offset)<M)&&(i<N); i++){
                        curr+=matr[i][j+offset];
                        offset++;
                }
                if (curr>currMax) currMax = curr;
        }
        curr =  0;
        for (i=0; i<minNM; i++) curr+=matr[i][i];
        if (curr>currMax) currMax = curr;
        printf("Максимум из диагоналей, параллелльных главной: %ld", currMax);
        free_matr(matr, N);
        return 0;
}

int main5(void) {
    printf("Сейчас решение задачи 5 пусто :( ");
}

int main6(void) {
    printf("Пожалуйста, посмотрите файлы 6.c, 61.c, 62.c");
}

int main(void){
    int N = 1;
    int (*tasks[])(void) = {main1,main2,main3,main4,main5,main6};
    setlocale(LC_ALL,"Russian");
    srand(time(NULL));
    while (N){
        printf("\n\nПожалуйста, выберите номер задания (0 для выхода): "); scanf("%d",&N);
        if (N<0 || N>6){
            printf("Некорректный номер задания");
            continue;
        }
        if (N>0){
            int result = tasks[N-1]();
            if (result){
                printf("\nОшибка %d. Введены некорректные данные - произошло ",result);
            } else {
                printf("\nЗадача %d успешно завершена",N);
            }
            switch (result) {
                case 0: break;
                case 1: printf("деление на 0."); break;
                case 2: printf("взятие квадратного корня из отрицательного числа."); break;
                case 3: printf("взятие логарифма из отрицательного числа."); break;
                default: printf("нечто неизвестное (неизвестная ошибка %d)", result);
            }
        }
    }
    return 0;
}

