#include <stdio.h>
#include <stdlib.h>

int main(void){
   int number=1, i;

    do {
        if( number < 0 ){
            printf("O numero precisa ser positivo.\n");
        }

        printf("Digite um numero: ");

        fflush(stdin);
        if( scanf("%d", &number) != 1 ){
            printf("Erro na leitura. Por favor digite um numero inteiro maior que 0.\n");
            number = -1;
        }
        
    } while (number < 0);
    
    printf("Numeros impares entre 1 e %d (intervalo fechado):\n", number);
    for(i = 1; i <= number; i++){
        if( i % 2 != 0){
            printf("%d\n", i);
        }
    } 

    return 0;
}