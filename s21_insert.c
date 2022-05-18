#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(const char *str);
char *s21_str_insert(char *str_1, char *str_2);

int main() {
    char str_1[14] = "hello, world!";
    char str_2[13] = "new";

    printf("str_1 - %s\n", str_1);
    printf("str_2 - %s\n", str_2);
    printf("insert - %s\n", s21_str_insert(str_1, str_2));
    return 0;
}

char *s21_str_insert(char *str_1, char *str_2) {
    size_t midle = s21_strlen(str_1) / 2;
    size_t size_new_str = s21_strlen(str_1) + s21_strlen(str_1) + 1;
    char *new_str = malloc(size_new_str * sizeof(char));
    size_t it_str = midle;
    for (size_t i = 0; i < size_new_str; i++) {
        if (i < midle) {
            new_str[i] = str_1[i];
        } else if (i == midle) {
            for (size_t j = 0; str_2[j] != '\0'; j++) {
                new_str[it_str] = str_2[j];
                it_str++;
            }
            new_str[it_str] = str_1[i];
        } else {
            it_str++;
            new_str[it_str] = str_1[i];
        }
    }
    new_str[size_new_str] = '\0';
    return new_str;
}

size_t s21_strlen(const char *str) {
    size_t ret = 0;
    while (*str != '\0') {
        str++;
        ret++;
    }
    return ret;
}
