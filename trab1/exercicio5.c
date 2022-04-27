#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void) {
    double square_root = 0;

    for (int i = 1; i <= 1000; i++){
        square_root = sqrt(i);
        /*
        Validação para saber se o número é inteiro
        pois impár e par são classificações de números inteiros
        */

        if (square_root == (int) square_root && (int) square_root % 2 != 0){
            printf("Raiz impar de  %d ->  %.2f\n", i, square_root);
        }
    }

    return 0;
}