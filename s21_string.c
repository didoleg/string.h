#include <stdio.h>
#include "s21_string.h"

void *s21_memchr(const void *src, int c, size_t n) {
    const unsigned char *str = (const unsigned char *)src;
    void *ret;
    ret = NULL;
    while (n-- > 0) {
        if ( *str == c) {
            ret = (void *)str;
            break;
        }
        str++;
    }
    return ret;
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

void *s21_memcpy(void *dest, const void *src, size_t n) {

        const unsigned char *str = (const unsigned char *)src;
        unsigned char *str2 = (unsigned char *)dest;
    if (src < dest) {
        str2 = str2 + n - 1;
        str = str +n - 1;
        while (n-- > 0) {
            *str2 = *str;
            str2--;
            str--;
        }
    } else {
        while (n-- > 0) {
            *str2 = *str;
            str2++;
            str++;
        }
    }
    return dest;
}

void *s21_memmove(void *dest, const void *src, size_t n) {
    if ((char*)dest - (char*)src >= 0) {
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

void *s21_memset(void *str, int c, size_t n) {
    unsigned char *str1 = (unsigned char *)str;
    while (n-- > 0) {
        *str1 = c;
        str1++;
    }
    return str;
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

char *s21_strncat(char *dest, const char *src, size_t n) {
    while (*dest != '\0') {
        dest++;
    }
    while (n-- > 0) {
        *dest = *src;
        dest++;
        src++;
    }
    return 0;
}

char *s21_strchr(const char *str, int c) {
    char *find;
    find = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            find = str + i;
            break;
        }
    }
    return find;
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

size_t s21_strlen(const char *str) {
    size_t ret = 0;
    while (*str != '\0') {
        str++;
        ret++;
    }
    return ret;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
  
    for ( ; i < n; i++)
        dest[i] = '\0';
    
    return dest;
}

int s21_strcmp (const char *str1, const char *str2) {
    int ret = 0;
    while (*str1 != '\0') {
        if (*str1 > *str2 ) {
            ret = 1;
            break;
        }
        if (*str1 < *str2 ) {
            ret = -1;
            break;
        }
        if (*str2 == '\0') {
            ret = 1;
            break;
        }
        if ((*(str1 + 1) == '\0') && (*(str2 + 1) != '\0')) {
            ret = -1;
            break;
        }
        str1++;
        str2++;
    }
    return ret;
}

char *s21_strerror(int errnum) {
    char *error;
    switch (errnum) {
    case 0:
        error = "Error 0";
        break;
    case 1:
        error = "Operation not permitted";
        break;
    case 2:
        error = "No such file or directory";
        break;
    case 3:
        error = "No such process";
        break;
    case 4:
        error = "Interrupted system call";
        break;
    case 5:
        error = "Input/output error";
        break;
    case 6:
        error = "No such device or address";
        break;  
    case 7:
        error = "Argument list too long";
        break;
    case 8:
        error = "Exec format error";
        break;
    case 9:
        error = "Bad file descriptor";
        break;
    case 10:
        error = "No child processes";
        break;
    case 11:
        error = "Resource temporarily unavailable";
        break;
    case 12:
        error = "Cannot allocate memory";
        break;
    case 13:
        error = "Permission denied";
        break;
    case 14:
        error = "Bad address";
        break;
    case 15:
        error = "Block device required";
        break;
    case 16:
        error = "Device or resource busy";
        break;
    case 17:
        error = "File exists";
        break;
    case 18:
        error = "Invalid cross-device link";
        break;
    case 19:
        error = "No such device";
        break;
    case 20:
        error = "Not a directory";
        break;
    case 21:
        error = "Is a directory";
        break;
    case 22:
        error = "Invalid argument";
        break;
    case 23:
        error = "Too many open files in system";
        break;
    case 24:
        error = "Too many open files";
        break;
    case 25:
        error = "Inappropriate ioctl for device";
        break;
    case 26:
        error = "Text file busy";
        break;
    case 27:
        error = "File too large";
        break;
    case 28:
        error = "No space left on device";
        break;
    case 29:
        error = "Illegal seek";
        break;
    case 30:
        error = "Read-only file system";
        break;
    case 31:
        error = "Too many links";
        break;
    case 32:
        error = "Broken pipe";
        break;
    case 33:
        error = "Numerical argument out of domain";
        break;
    case 34:
        error = "Numerical result out of range";
        break;
    case 35:
        error = "Resource deadlock avoided";
        break;
    case 36:
        error = "File name too long";
        break;
    case 37:
        error = "No locks available";
        break;
    case 38:
        error = "Function not implemented";
        break;
    case 39:
        error = "Directory not empty";
        break;
    case 40:
        error = "Too many levels of symbolic links";
        break;
    case 42:
        error = "No message of desired type";
        break;
    case 43:
        error = "Identifier removed";
        break;
    case 44:
        error = "Channel number out of range";
        break;
    default:
        error = "Unknown error";
        break;
    }

    return error;
}

char *s21_strcpy(char *dest, const char *src) {
    char *str = dest;
    while (*str != '\0') {
        *str = *src;
        str++;
        src++;
    }
    return dest;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char *find = NULL;
    int state = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        for (int j = 0; str2[j] != '\0'; j++) {
            if (str2[j] == str1[i]) {
                find = (char*)str1 + i;
                state = 1;
                break;
            }
        }
        if (state == 1) {
            break;
        }
    }
    return find;
}

size_t s21_strcspn (const char *str1, const char *str2) {
    char *str3 = (char *)str2;
    int flag = 0;
    size_t ret = 0;
    while (*str1 !='\0') {
        while (*str3 != '\0') {
            if (*str1 == *str3) {
                flag = 1;
                break;
            } 
            str3++;
        }
        str3 = (char *)str2;
        if (flag == 1)
            break;
        ret++;
        str1++;
    }
    return ret;
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

char *s21_strrchr(const char *str, int c) {
    char* ret = NULL;
    while (*str != '\0') {
        if (*str == c) {
            ret = (char*) str;
        }
        str++;
    }
    return ret;
}

char *s21_strstr(const char *haystack, const char *needle) {
    char* str = (char*) needle;
    char* ret = NULL;
    int flag = 0;
    if (*needle == '\0') {
        ret = (char*) haystack;
    } else {
        while (*haystack != '\0') {
            if ((*str == '\0') && (flag == 1)) {
                ret = (char*) haystack - s21_strlen(needle);
            }
            if (*haystack == *str) {
                flag = 1;
                str++;
            } else {
                str = (char*) needle;
                flag = 0;
            }
            haystack++;
        }
    }
    return ret;
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
