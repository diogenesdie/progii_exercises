#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void vogais_consoantes( char *palavra, int *vogais, int *consoantes, int *letras, char *primeira_letra, char *ultima_letra ) {
    int i;
    *vogais = 0;
    *consoantes = 0;
    *letras = 0;

    for( i = 0; i < strlen( palavra ); i++ ){
        if( palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u' ){
            *vogais = *vogais + 1;
        } else{
            *consoantes = *consoantes + 1;
        }
        *letras = *letras + 1;

        if( i == 0 ){
            *primeira_letra = toupper( palavra[i] );
        }

        if( i == strlen( palavra ) - 1 ){
            *ultima_letra = toupper( palavra[i] );
        }
    }
}

int main(void) {
    char palavra[100], primeira_letra, ultima_letra;
    int vogais = 0, consoantes = 0, letras = 0;
    int valido = 0, size = 0;

    while (!valido) {
        printf( "Digite uma palavra: " );
        fflush(stdin);
        fgets(palavra, 100, stdin);

        size   = strlen(palavra);
        valido = 0;

        /*
        * Remove \n 
        */
        palavra[size - 1] = '\0';
        

        if( size > 1 ) {
            valido = 1;
        }

        if( !valido ){
            printf( "Palavra invalida!\n" );
        }  
    }

    vogais_consoantes( palavra, &vogais, &consoantes, &letras, &primeira_letra, &ultima_letra );

    printf( "Quantidade de letras: %d\n", letras );
    printf( "Quantidade de vogais: %d\n", vogais );
    printf( "Quantidade de consoantes: %d\n", consoantes );
    printf( "Primeiro e ultimo caracteres concatenados, e em maiusculo: %c%c\n", primeira_letra, ultima_letra );

    return EXIT_SUCCESS;
}