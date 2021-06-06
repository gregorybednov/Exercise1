#include <stdlib.h>
#include <stdio.h>

void freeMatr (int **matr, size_t n) {
        size_t x;
        for (x=0; x<n; x++) {
            free(matr[x]);
        }
        free(matr);
}

int allocMatr(int ***matr, size_t n, size_t m){
        size_t i;
        *matr = malloc(sizeof(int*)*n);
        if (*matr==NULL) return 4;
        for (i=0; i<n; i++) {
                if (((*matr)[i] = malloc(sizeof(int)*m)) == NULL) {
                        freeMatr(*matr, i);
                        return 4;
                }
        }
        return 0;
}

int randFromXToY (int x, int y){
        return rand()%(y+1-x)+x;
}

void fillMatr(int **matr, size_t N, size_t M) {
        size_t i, j;
        for (i=0; i<N; i++) {
                for (j=0; j<M; j++) {
                        matr[i][j] = randFromXToY(-10,10);
                }
        }
}

void printMatr(int **matr, size_t N, size_t M) {
        size_t i, j;
        for (i=0; i<N; i++) {
                for (j=0; j<M; j++) {
                    printf("%4d", matr[i][j]);
                }
                printf("\n");
        }
}

int main(void) {
        int **matr;
        size_t N = 10;
        size_t M = N;
        size_t minNM;
        size_t i, j;
        long int curr, currMax;
        int res;
        if (N<M) minNM = N; else minNM = M;
        if (res = allocMatr(&matr, N, M)) return res;
        currMax = (long int)(matr[N-1][0]);
        fillMatr(matr, N, M);
        printMatr(matr, N, M);printf("\n");
        for (i=N-1; i>0; i--) {
                size_t offset = 0;
                curr = 0;
                for (j=0; (j<M)&&((i+offset)<N); j++) {
                        curr+=matr[i+offset][j];
                        offset++;
                }
                if (curr>currMax) currMax = curr;
        }
        for (j=M-1; j>0; j--) {
                size_t offset = 0;
                curr = 0;
                for (i=0; ((j+offset)<M)&&(i<N); i++) {
                        curr+=matr[i][j+offset];
                        offset++;
                }
                if (curr>currMax) currMax = curr;
        }
        curr =  0;
        for (i=0; i<minNM; i++) curr+=matr[i][i];
        if (curr>currMax) currMax = curr;
        printf("Maximum of sums of main-parallel matrix diagonals: %ld", currMax);
        freeMatr(matr, N);
        return 0;
} 