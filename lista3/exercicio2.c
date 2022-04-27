#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char name[100];
    int valid = 0, words_count = 0, size = 0;
        
    while( !valid ) {
        printf("Digite seu nome (limite 100 caracteres): ");
        fflush(stdin);
        fgets(name, 100, stdin);
        
        valid = 0;
        size  = strlen(name);

        if( size > 1 ){
            valid = 1;
        }

        for (size_t i = 0; i < size; i++){
            if( name[i] == ' ' && isalpha(name[i+1]) ){
                valid = 1;
                break;
            } else {
                valid = 0;
            }
        }

        if( !valid ){
            printf("Nome invalido. Informe seu nome completo\n");
        }

    }

    /*
     * Remove \n 
     */
    name[size - 1] = '\0';

    char *p = strtok (name, " ");
    char *array[50];

    while (p != NULL) {
        array[words_count++] = p;
        p = strtok (NULL, " ");
    }

    for (size_t i = words_count; i > 0; i--){
        array[i-1][0] = toupper(array[i-1][0]);
        fputs(array[i-1], stdout);
        fputs(" ", stdout);
    }

    printf("\nO nome possui %d palavras.", words_count);
    
    return EXIT_SUCCESS;
}