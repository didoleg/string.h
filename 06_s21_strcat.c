#include <stdio.h>
#include <string.h>

char *s21_strcat(char *dest, const char *src);

int main () {
    char dest_1[100] = "Hello, ";
    char dest_2[100] = "Hello, ";
    char src[10] = "World";

    strcat(dest_1, src);
    s21_strcat(dest_2, src);

    printf("%s\n", dest_1);
    printf("%s", dest_2);
    return 0;
}

char *s21_strcat(char *dest, const char *src) {
    for (int i = 0; ; i++) {
        if (dest[i] == '\0') {
            for (int j = 0; src[j] != '\0'; j++) {
                dest[i] = src[j];
                i++;
            }
            dest[i + 1] = '\0';
            break;
        }
    }
}