#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char phrase[100], normalized[100] = "", inverted[100] = "";
    int valid = 0, size = 0;
        
    while( !valid ) {
        printf("Digite seu nome (limite 100 caracteres): ");
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

    /*
     * Remove \n 
     */
    phrase[size - 1] = '\0';
    
    for (size_t i = 0; i < size; i++) {
        if( phrase[i] == ' ' || phrase[i] == '\n' || phrase[i] == '\t' 
         || phrase[i] == '\r' || phrase[i] == '.' || phrase[i] == ',' 
         || phrase[i] == ';' || phrase[i] == ':' || phrase[i] == '!' 
         || phrase[i] == '?' || phrase[i] == '-' || phrase[i] == '_' 
         || phrase[i] == '(' || phrase[i] == ')' || phrase[i] == '[' 
         || phrase[i] == ']' || phrase[i] == '{' || phrase[i] == '}' 
         || phrase[i] == '\'' || phrase[i] == '"' || phrase[i] == '\0' ){
            continue;
        } 
        
        char c = phrase[i];    
        
        if( c == (char)160 || c == (char)131 || c == (char)132 || c == (char)133 || c == (char)134 || c == (char)142 || c == (char)143 || c == (char)142 || c == (char)181 || c == (char)192 || c == (char)183 || c == (char)199 ){
            c = 'a';
        } else if( c == (char)130 || c == (char)136 || c == (char)137 || c == (char)138 || c == (char)144 || c == (char)210 || c == (char)211 || c == (char)212 ){
            c = 'e';
        } else if( c == (char)139 || c == (char)140 || c == (char)141 || c == (char)161 || c == (char)213 || c == (char)214 || c == (char)215 || c == (char)216 || c == (char)222 ){
            c = 'i';
        } else if( c == (char)147 || c == (char)148 || c == (char)149 || c == (char)153 || c == (char)162 || c == (char)224 || c == (char)226 || c == (char)227 || c == (char)228 || c == (char)229 ){
            c = 'o';
        } else if( c == (char)129 || c == (char)150 || c == (char)151 || c == (char)154 || c == (char)163 || c == (char)233 || c == (char)234 || c == (char)235 ){
            c = 'u';
        }

        c = tolower(c);
        strncat(normalized, &c, 1);
    }

    for (size_t i = 0; i < size; i++) {
        strncat(inverted, &normalized[size - i - 1], 1);
    }

    printf("A frase digitada foi: %s\n", phrase);

    if( strcmp(normalized, inverted) == 0 ){
        printf("E um palindromo.\n");
    } else {
        printf("Nao e um palindromo.\n");
    }

    return EXIT_SUCCESS;
}