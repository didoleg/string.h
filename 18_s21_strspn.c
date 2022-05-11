#include <stdio.h>
#include <string.h>

size_t s21_strspn(const char *str1, const char *str2);

int main() {
    char str_1[15] = "0123456789";
    char str_2[15] = "203";
 
    printf("lenght segment: %ld\n", strspn(str_1, str_2));
    printf("s21_lenght segment: %ld\n", s21_strspn(str_1, str_2));
    
    return 0;
}

size_t s21_strspn(const char *str1, const char *str2) {
    int count = 0;
    int state = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        int count_2 = 0;
        for (int j = 0; ; j++) {
            if (str1[i] == str2[j]) {
                count ++;
                break;
            } else if (count_2 == 0 && str2[j] == '\0'){
                state = 1;
                break;
            }
        }
        if (state == 1) {
            break;
        }
    }
    return count;
}