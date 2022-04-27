#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Person {
    char name[50];
    int age;
    int birth_year;
};

int get_current_year(void) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    return tm->tm_year + 1900;
}

int calculate_age(char already_birthday, int birth_year) {
    int current_year = get_current_year();
    return already_birthday == 's' ? current_year - birth_year : current_year - birth_year - 1;
}

int main(void){
    char already_birthday;
    struct Person p;

    printf("Digite o seu nome: ");
    fflush(stdin);
    gets(p.name);

    printf("Digite o ano de nascimento: ");
    fflush(stdin);
    scanf("%d", &p.birth_year);

    while (already_birthday != 'n' && already_birthday != 's') {
        printf("\nVoce ja fez aniversario? (s/n): ");
        fflush(stdin);
        scanf("%c", &already_birthday);
    }

    p.age = calculate_age(already_birthday, p.birth_year);

    printf("%s %d anos\n", p.name, p.age);
    
    return 0;
}