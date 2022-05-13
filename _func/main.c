#include <stdio.h>

void *s21_memchr(const void *str, int c, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
size_t s21_strlen(const char *str);
int s21_strcmp (const char *str1, const char *str2);
char *s21_strcpy(char *dest, const char *src);
size_t s21_strcspn (const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
//char *s21_strtok(char *str, const char *delim);


int main() {
    // Исходный массив
    unsigned char src[15]="1234567890";
    // Переменная, в которую будет сохранен указатель
    // на искомый символ.
    char *sym;
    char src2[15] = "1234567890";
    char src3[20] = "06740634067089";
    char dop[5] = "q0e2";
    char dop2[5] = "qwe5";
    char dop3[5] = "4067";

    // Вывод исходного массива
    printf ("src old: %s\n",src);

    // Поиск требуемого символа
    sym = s21_memchr (src, '4', 4);

    // Если требуемый символ найден, то заменяем его
    // на символ '!'
    if (sym != NULL)
        sym[0]='!';

    // Вывод исправленого массива
    printf ("src new: %s\n",src);

    s21_memcpy(src, sym, 4);

    printf ("src new: %s\n",src);

    s21_memset(sym + 2, 70, 4);

    printf ("src new: %s\n",src);

    s21_strncat(src2, dop, 3);
    printf ("src2 new: %s\n",src2);

    int i = s21_strlen(src2);
    printf ("src new lenth: %i\n",i);

    printf ("sravnenie dop i dop2: %i\n", s21_strcmp(dop, dop2));

    s21_strcpy(src2, dop2);
    printf ("src2 new: %s\n", src2);
    
    printf ("SRC3 bez simvolov iz SRC2: %i\n", (int) s21_strcspn(src3, src2));

// Поиск требуемого символа
    sym = s21_strrchr (src3, '0');
    // Если требуемый символ найден, то заменяем его
    // на символ '!'
    if (sym != NULL)
        sym[0]='!';
    // Вывод исправленого массива
    printf ("src3 new: %s\n",src3);

    sym = s21_strstr(src3, dop3);
    if (sym != NULL)
        s21_memset(sym, 71, 4);
    printf ("src3 new: %s\n",src3);
/*
    q = s21_strtok(src3, '0');
    while(q!=NULL) {
        printf("%s\n", q);
        q = s21_strtok(NULL, '0');
    }*/
    
    return 0;
}

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

//Копирует n символов из src в dest.
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

//Копирует символ c (unsigned char) в первые n символов строки, на которую указывает аргумент str.
void *s21_memset(void *str, int c, size_t n) {
    unsigned char *str1 = (unsigned char *)str;
    while (n-- > 0) {
        *str1 = c;
        str1++;
    }
    return str;
}

//Добавляет строку, на которую указывает src, к концу строки, на которую указывает dest, длиной до n символов.
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

size_t s21_strlen(const char *str) {
    size_t ret = 0;
    while (*str != '\0') {
        str++;
        ret++;
    }
    return ret;
}

//Сравнивает строку, на которую указывает str1, со строкой, на которую указывает str2.
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

//Копирует строку, на которую указывает src, в dest.
char *s21_strcpy(char *dest, const char *src) {
    char *str = dest;
    while (*str != '\0') {
        *str = *src;
        str++;
        src++;
    }
    return dest;
}

//Вычисляет длину начального сегмента строки str1, полностью состоящего из символов, не входящих в строку str2.
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

//Ищет последнее вхождение символа c (беззнаковый char) в строке, на которую указывает аргумент str.
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

//Находит первое вхождение всей строки needle (не включая завершающий нулевой символ), которая появляется в строке haystack.
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
/*
//Разбивает строку str на серию токенов, разделенных разделителем.
char *s21_strtok(char *str, const char *delim) {
    static char *s=NULL; 
    if (str==NULL) {
        if (s==NULL) return NULL;
        str = s+1;
    }
    s = s21_memchr(str, delim);
    if (s!=NULL)
        *s = '\0';
    return str;
} */
