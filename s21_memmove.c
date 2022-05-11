#include <stdio.h>
#include <string.h>

void *s21_memmove(void *dest, const void *src, size_t n);

int main () {
    char src[10] = "123456789";
    char src_1[10] = "123456789";
    int n = 5;

    s21_memmove(&src[1],&src[0], n);
    memmove(&src_1[1],&src_1[0], n);
    printf("%s\n", src);
    printf("%s\n", src_1);
    return 0;
}

void *s21_memmove(void *dest, const void *src, size_t n) {
    int delta;
    delta = (char*)dest - (char*)src;
    if (delta >= 0) {
        for (int i = 0; (int)n > i; i++) {
            *((char*)dest + n - 1 - i) = *((char*)src + n - 1 - i);
        }    
    } else {
        for (int i = 0; (int)n > i; i++) {
            *((char*)dest + i) = *((char*)src + i);
        }
    }
    return 0;
}