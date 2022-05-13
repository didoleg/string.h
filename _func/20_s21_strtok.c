#include <stdio.h>
#include <string.h>

char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strchr(const char *str, int c);
char *s21_strtok(char *str, const char *delim);

int main() {
    char str_2[] = "test1/test2/test3/test4";
    char sep[] = "/";

    char *test_strtok = s21_strtok(str_2, sep);

    if (test_strtok == NULL) {
        printf("Can't separated");
    } else {
        while (test_strtok != NULL) {
            printf("%s\n", test_strtok);
            test_strtok = s21_strtok(NULL, sep);
        }
    }
    return 0;
}

static char *find_lexem_begin(char *str, const char *delim) {
    char *lexem = NULL;
    for (char *str_it = str; *str_it != 0; ++str_it) {
        if (!s21_strchr(delim, *str_it)) {
            lexem = str_it;
            break;
        }
    }
    return lexem;
}



char *s21_strtok(char *str, const char *delim) {
    static char *s21_str = NULL;
    if (str) {
        s21_str = str;
    }

    char *lexem_begin = NULL;
    if (s21_str) {
        lexem_begin = find_lexem_begin(s21_str, delim);
        if (lexem_begin) {
            char *lexem_end = s21_strpbrk(lexem_begin, delim);
            if (lexem_end) {
                *lexem_end = 0;
                s21_str = lexem_end + 1;
            }
            else {
                // The last lexem is found
                s21_str = NULL;
            }
        } else {
            // A new lexem not found
            s21_str = NULL;
        }
    }
    return lexem_begin;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char *find = NULL;
    for (int i = 0; str1[i] != '\0'; i++) {
        for (int j = 0; str2[j] != '\0'; j++) {
            if (str2[j] == str1[i]) {
                find = (char *)str1 + i;
                break;
            }
        }
        if (find) {
            break;
        }
    }
    return find;
}

char *s21_strchr(const char *str, int c) {
    const char *find = str;
    while (find) {
        if (*find == c) {
            break;
        } else if (*find == 0) {
            find = NULL;
        } else {
            ++find;
        }
    }
    return (char*)find;
}