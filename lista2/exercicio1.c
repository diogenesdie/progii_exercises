#include <stdio.h>
#include <stdlib.h>

int main(void){
    int times_table[10][10];
    int i, j, search = 1;

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            times_table[i][j] = (i+1) * (j+1);
        }
    }

    do {
        if( search < 1 || search > 10){
            printf("\nInforme uma numero entre 1 e 10.");
        }

        printf("\nDigite um numero para ver a tabuada: ");
        fflush(stdin);
        if( scanf("%d", &search) != 1){
            search = -1; 
        }
    } while(search < 1 || search > 10);

    for(i = 0; i < 10; i++){
        if( i == search - 1 ){
            for(j = 0; j < 10; j++){
                printf("%d x %d = %d ", i+1, j+1, times_table[i][j]);
                printf("\n");
            }

            break;
        }
    }

    return 0;
}