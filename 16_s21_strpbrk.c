#include <stdio.h>
#include <string.h>

char *s21_strpbrk(const char *str1, const char *str2);

int main() {
    char str_1[15] = "0123456789";
    char str_2[15] = "2";
    
    char *find;
    char *s21_find;

    find = strpbrk(str_1, str_2);
    s21_find = s21_strpbrk(str_1, str_2);

    if (find == NULL) {
        printf("Symbol not find\n");
    } else {
        printf("Find symbol: %ld\n", find - str_1);
    }

    if (s21_find == NULL) {
        printf("s21_Symbol not find\n");
    } else {
        printf("s21_Find symbol: %ld\n", s21_find - str_1);
    }
    return 0;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char *find = NULL;
    for (int i = 0; str1[i] != '\0'; i++) {
        for (int j = 0; str2[j] != '\0'; j++) {
            if (str2[j] == str1[i]) {
                find = (char *)str1 + i;
                break;
            }
        } if (find) {
            break;
        }
    }
    return find;
}