#include <stdio.h>
#include <stdlib.h>

int main(void){
    int number = 1, i;

    do {
        if( number < 1 || number > 10 ){
            printf("O numero deve estar entre 1 e 10\n");	
        }

        printf("Digite um numero: ");
        scanf("%d", &number);
    } while (number < 1 || number > 10);

    printf("Tabuada do %d\n", number);
    for(i = 1; i <= 10; i++){
        printf("%d x %d = %d\n", number, i, number*i);
    }
    return 0;
}