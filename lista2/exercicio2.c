#include <stdio.h>
#include <stdlib.h>

int validate_entry(int *n){
    int i;
    
    fflush(stdin);
    if(scanf("%d", &i) != 1){
        printf("Valor invalido.\n");
        return 0;
    }
    *n = i;
    return 1;
}

void read_matrix(int (*matrix)[3], int n){
    int i, j, valid;
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            do {
                printf("Digite o valor da posicao [%d][%d]: ", i, j);
                valid = validate_entry(&matrix[i][j]);
            } while(!valid);
        }
    }
}

int main(void){
    int user_table_x[3][3], user_table_y[3][3], times_table[3][3], i, j, valid;

    printf("Digite os valores da matrix X:\n");
    read_matrix(user_table_x, 3);
    printf("Digite os valores da matrix Y:\n");
    read_matrix(user_table_y, 3);

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            times_table[i][j] = user_table_x[i][j] * user_table_y[i][j];
        }
    }

    printf("Tabela de multiplicacao: \n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if( j == 0 ){
                printf("|");
            }
            printf("%3d ", times_table[i][j]);
            if( j == 2 ){
                printf("|");
            }
        }
        printf("\n");
    }

    return 0;
}