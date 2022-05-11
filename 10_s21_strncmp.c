#include <stdio.h>
#include <string.h>

int s21_strncmp(const char *str1, const char *str2, size_t n);

int main () {
    char str_1[10] = "Hello, man";
    char str_2[10] = "Hello, man";

    if (s21_strncmp(str_1, str_2, 9) == 0) {
        printf("find_good_21\n");
    } else {
        printf("find_bad_21\n");
    }

    if (strncmp(str_1, str_2, 5) == 0) {
        printf("find_good");
    } else {
        printf("find_bad");
    }
    
    return 0;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
    int state = 0;
    for (int i = 0; i <= n; i++) {
        if (str1[i] > str2[i]) {
            state = 1;
            break;
        } else if (str1[i] < str2[i]) {
             state = -1;
            break;
        }
    }
    return state; 
}