#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

size_t s21_strlen(const char *str);
char *s21_to_upper(const char *string);
char *s21_to_lower(const char *string);
char *s21_str_insert(char *str_1, char *str_2);

int main() {
    char str_1[13] = "hello, world";
    char str_2[13] = "HELLO, wOrLd";
    char str_3[13] = "new";

    printf("str_1 - %s\n", str_1);
    printf("str_2 - %s\n", str_2);
    printf("up - %s\n", s21_to_upper(str_1));
    printf("low - %s\n", s21_to_lower(str_2));
    printf("insert - %s\n", s21_str_insert(str_1, str_3));
    return 0;
}

char *s21_to_upper(const char *string) {
    size_t size = s21_strlen(string) + 1;
    char* up_str = malloc(size * sizeof(char));
    if (up_str) {
        for (size_t i = 0; i < size; i++) {
            if (string[i] >= 'a' && string[i] <= 'z') {
                up_str[i] = string[i] - 32;
    	    } else {
                up_str[i] = string[i];
            }
        }
    }
    return up_str;
}

char *s21_to_lower(const char *string) {
    size_t size = s21_strlen(string) + 1;
    char* str_lower = malloc(size * sizeof(char));
    if (str_lower) {
        for (size_t i = 0; i < size; i++) {
            if (string[i] >= 'A' && string[i] <= 'Z') {
                str_lower[i] = string[i] + 32;
    	    } else {
                str_lower[i] = string[i];
            }
        }
    }
    return str_lower;
}

char *s21_str_insert(char *str_1, char *str_2) {
    size_t midle = s21_strlen(str_1) / 2;
    size_t size_new_str = s21_strlen(str_1) + s21_strlen(str_1) + 1;
    char *new_str = malloc(size_new_str * sizeof(char));
    
    for (size_t i = 0; i < size_new_str; i++) {
        if (i < midle) {
            new_str[i] = str_1[i];
        } else if (i == midle) {
            for (size_t j = 0; str_2[j] != '\0'; i++) {
                new_str[midle] = str_2[j];
                midle++;
            }
        } else {
            new_str[i] = str_1[i];
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
