#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char name[100], last_name[100], first_name[100];
    int size = 0, valid = 0;
    
    while( !valid ) {
        printf("Digite seu nome: ");
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
            printf("Nome invalido!\n");
        }

    }
    
    /*
     * Remove \n 
     */
    name[size - 1] = '\0';

    strcpy(last_name, strrchr(name, ' '));
    strcpy(first_name, strtok(name, " "));

    size = strlen(last_name);

    /*
     * Upper case last name and remove space
     */ 
    for (size_t i = 0; i < size; i++) {
        last_name[i] = toupper(last_name[i+1]);

        if( i == size - 1) {
            last_name[i] = '\0';
        }
    }

    first_name[0] = toupper(first_name[0]);
    
    printf("%s, %s", last_name, first_name);
    
    return EXIT_SUCCESS;
} 