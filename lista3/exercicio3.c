#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char phrase[100], vowels[100] = "", consonants[100] = "", option = '0';
    int valid = 0, size = 0;
        
    while( !valid ) {
        printf("Digite uma frase (limite 100 caracteres): ");
        fflush(stdin);
        fgets(phrase, 100, stdin);
        
        valid = 0;
        size  = strlen(phrase);

        if( size > 1 ){
            valid = 1;
        }

        if( !valid ){
            printf("Frase invalida.\n");
        }

    }

    while( option != 'V' && option != 'C' ) {
        printf("\nDigite 'V' para mostrar primeiro as vogais ou 'C' para consoantes: ");
        fflush(stdin);
        scanf("%c", &option);
        option = toupper(option);

        if( option != 'V' && option != 'C' ){
            printf("Opcao invalida.\n");
        }
    }

    /*
     * Remove \n 
     */
    phrase[size - 1] = '\0';

    for (size_t i = 0; i < size; i++) {
        switch (tolower(phrase[i])) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                strncat(vowels, &phrase[i], 1);
                break;
            default:
                if( isalpha(phrase[i]) ){
                    strncat(consonants, &phrase[i], 1);
                }
                break;
        }
    }

    printf("A frase digitada foi: %s\n", phrase);
    if( option == 'V' ){
        printf("%s %s", vowels, consonants);
    } else {
        printf("%s %s", consonants, vowels);
    }
    
    return EXIT_SUCCESS;
}