#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char *get_letter_type(char letter) {
    switch (letter) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return "vogal";
            break;
        default:
            return "consoante";
    }

    return "indefinido";
}

int main(void){
    char letter;

    printf("Digite uma letra: ");
    scanf("%c", &letter);

    letter = tolower(letter);

    printf("A letra e uma %s", get_letter_type(letter));

    return 0;
}