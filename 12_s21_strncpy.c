#include <stdio.h>
#include <string.h>

char *s21_strncpy(char *dest, const char *src, size_t n);

int main () {
    char src[10] = "0123456789";
    char dest_1[15] = "Hello, man";
    char dest_2[15] = "Hello, man";

    strncpy(dest_1, src, 5);
    printf("%s\n", dest_1);
    
    s21_strncpy(dest_2, src, 5);
    printf("%s\n", dest_2);

   
    
    return 0;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
  
    for ( ; i < n; i++)
        dest[i] = '\0';
    
    return dest;
}