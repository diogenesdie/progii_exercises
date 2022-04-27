#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
    int birth_year, age;
    char already_birthday;

    printf("Digite o ano de nascimento: ");
    scanf("%d", &birth_year);

    while (already_birthday != 'n' && already_birthday != 's') {
        printf("\nVoce ja fez aniversario? (s/n): ");
        fflush(stdin);
        scanf("%c", &already_birthday);
    }

    age = calculate_age(already_birthday, birth_year);

    printf("\nVoce tem %d anos!", age);
    
    return 0;
}