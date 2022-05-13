#include <stdio.h>
#include <string.h>

char *s21_strchr(const char *str, int c);

int main () {
    char str[100] = "Hello, World";
    int ch = 'e';
    char *s21_find;
    char *str_find;
    
    str_find = strchr(str, ch);
    s21_find = s21_strchr(str, ch);
    
    if (str_find == NULL) {
        printf("Symbol not find\n");
    } else {
        printf("Find symbol: %ld\n", str_find - str);
    }

    if (s21_find == NULL) {
        printf("Symbol not find\n");
    } else {
        printf("Find symbol: %ld\n", s21_find - str);
    }
    
    return 0;
}

char *s21_strchr(const char *str, int c) {
    const char *find = str;
    while (find) {
        if (*find == c) {
            break;
        } else if (*find == 0) {
            find = NULL;
        } else {
            ++find;
        }
    }
    return (char*)find;
}