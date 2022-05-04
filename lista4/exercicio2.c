#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int soma(double *a, double *b) {
    return (int) (*a + *b);
}

int subtracao(double *a, double *b) {
    return (int) (*a - *b);
}

int multiplicacao(double *a, double *b) {
    return (int) (*a * *b);
}

double divisao(double *a, double *b) {
    if( *b == 0 ) {
        printf("Nao e possivel dividir por zero!\n");
        return 0;
    }

    return *a / *b;
}

int resto(double *a, double *b) {
    return (int) *a % (int) *b;
}

int potencia(double *a, double *b) {
    return (int) pow(*a, *b);
}

int main(void) {
    double a, b, resultado;
    int opcao, continuar = 1, valido = 0;
    char acao[7];

    while (continuar) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("Digite o primeiro numero: ");
        scanf("%lf", &a);

        printf("Digite o segundo numero: ");
        scanf("%lf", &b);

        printf("Digite a operacao desejada: \n");
        printf("1 - Soma\n");
        printf("2 - Subtracao\n");
        printf("3 - Multiplicacao\n");
        printf("4 - Divisao\n");
        printf("5 - Resto\n");
        printf("6 - Potencia\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("%lf + %lf ~= %d\n", a, b, soma(&a, &b));
                break;
            case 2:
                printf("%lf - %lf ~= %d\n", a, b, subtracao(&a, &b));
                break;
            case 3:
                printf("%lf * %lf ~= %d\n", a, b, multiplicacao(&a, &b));
                break;
            case 4:
                resultado = divisao(&a, &b);
                if( resultado ){
                    printf("%lf / %lf = %lf\n", a, b, resultado);
                }
                break;
            case 5:
                printf("%lf %% %lf ~= %d\n", a, b, resto(&a, &b));
                break;
            case 6:
                printf("%lf ^ %lf ~= %d\n", a, b, potencia(&a, &b));
                break;
            default:
                printf("Operacao invalida!\n");
                break;
        }

        

        while (strcmp(acao, "repetir") != 0 && strcmp(acao, "sair") != 0){
            printf("Digite 'repetir' para uma nova operacao e 'sair' para fechar a calculadora: ");
            scanf("%s", acao); 
        }

        if(strcmp(acao, "sair") == 0) {
            continuar = 0;
        }
    }
    

    return EXIT_SUCCESS;
}