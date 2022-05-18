#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "s21_string.h"


size_t s21_strlen(const char *str);
char *s21_str_upper(const char *string);
char *s21_str_lower(const char *string);
char *s21_str_insert(char *str_1, char *str_2);

int main() {
    char str_1[13] = "hello, world";
    char str_2[13] = "HELLO, wOrLd";
    char str_3[13] = "new";

    printf("%s\n", str_1);
    printf("%s\n", str_2);
    printf("up - %s\n", s21_str_upper(str_1));
    printf("low - %s\n", s21_str_lower(str_2));
    printf("insert - %s\n", s21_str_insert(str_1, str_3));
    return 0;
}

size_t s21_strlen(const char *str) {
    size_t ret = 0;
    while (*str != '\0') {
        str++;
        ret++;
    }
    return ret;
}


char *s21_str_upper(const char *string) {
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

char *s21_str_lower(const char *string) {
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
    char *tmp;
    size_t j = 0;
    
    for (size_t i = midle; str_1[i] != '\0'; i++) {
        tmp[j] = str_1[i];
        j++; 
    }
    
    tmp[j] = '\0';

    for (size_t i = 0; str_2[i] != '\0'; i++) {
        str_1[midle] = str_2[i];
        midle++;
    }

    for (j = 0; tmp[j] != '\0'; j++) {
        str_1[midle] = tmp[j];
        midle++;
    }
    str_1[midle] = '\0';
    
    return str_1;
}
