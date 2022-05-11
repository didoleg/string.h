#include <stdio.h>
#include <string.h>

char *s21_strtok(char *str, const char *delim);

int main() {
    char str_1[24] = "test1/test2/test3/test4";
    char str_2[24] = "test1/test2/test3/test4";
    char sep[15] = "/";
    
    char *test_strtok = strtok(str_1, sep);
    char *test_s21_strtok = s21_strtok(str_2, sep);

    /* if (test_strtok == NULL) {
        printf("Can't separated");
    } else {
        while (test_strtok != NULL) {
            printf("%s\n", test_strtok);
            test_strtok = strtok (NULL,sep);
        }
    } */

    printf("\ns21_strtok\n");

    if (test_s21_strtok == NULL) {
        printf("Can't separated");
    } else {
        while (test_s21_strtok != NULL) {
            printf("%s\n", test_s21_strtok);
            test_s21_strtok = s21_strtok (NULL,sep);
        }
    }
    
    return 0;
}

char *s21_strtok(char *str, const char *delim) {
    char *find = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((int)str[i] == *delim) {
            find = str + i;
        }
    }
    return find;
}
