#include <stdio.h>
#include <string.h>

int s21_memcmp(const void *str1, const void *str2, size_t n);

int main () {
    unsigned char src[10] = "Hello, man";
    unsigned char dst[10] = "Hello, man";

    if (s21_memcmp(src, dst, 10) == 0) {
        printf("mem_good_21\n");
    } else {
        printf("mem_bad_21\n");
    }

    if (memcmp(src, dst, 10) == 0) {
        printf("mem_good");
    } else {
        printf("mem_bad");
    }
    
    return 0;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
    int state = 0;
    while (n-- >0) {
        if (*(unsigned char*)str1 - *(unsigned char*)str2 != 0) {
            state = 1;
            break;
        } else {
            str1 = (unsigned char*)str1 + 1;
            str2 = (unsigned char*)str2 + 1;
        }
    }
    return state; 
}
