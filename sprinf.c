#include <stdio.h>
#include <stdarg.h>
#include "s21_string.h"
#include <wchar.h>

char* P(void* a,char flag, int width, char* buf);
char* DtoH (size_t d, char* buf);
int s21_sprintf(char *str, const char* format, ...);
lx(unsigned long int d, char flag, int width, int precision, char *buf);
x(unsigned int d, char flag, int width, int precision, char *buf);
lX(unsigned long int d, char flag, int width, int precision, char *buf);
X(unsigned int d, char flag, int width, int precision, char *buf);
lo(unsigned long int d, char flag, int width, int precision, char *buf);
o(unsigned int d, char flag, int width, int precision, char *buf);

int s21_sprintf(char *str, const char* format, ...) {
    int ret, kol_arg = 0, width = 0, precision = 0;
    char* strtmp = (char*)format;
    char* buf = str;
    char flag = 0, length = 0;
    
    // вычисляем количество аргументов
    while (*strtmp != '\0') {
        if (((*strtmp == '%') && (*(strtmp - 1) != '%') && (*(strtmp - 1) != '%')) ||
            ((*strtmp == '*') && ((*(strtmp - 1) == '%') || (*(strtmp -2) == '%')))){
            kol_arg++;
        }
        strtmp++;
    }
    //

    // определяем список аргументов
    va_list argptr;
    va_start (argptr, format);

    strtmp = (char*)format;
    while (*strtmp != '\0') {
        if (*strtmp == '%') {  // если встретился знак % то:
            strtmp++;

            // определяем флаг
            if ((*strtmp == '-') || (*strtmp == '+') || (*strtmp == ' ') || (*strtmp == '0') ||
                        (*strtmp == '#')) {
                flag = *strtmp;
                strtmp++;
            }

            // определяем минимальную ширину поля
            if (((*strtmp >= 48) && (*strtmp <= 57)) || (*strtmp == '*')) {
                if (*strtmp == '*') {
                    precision = va_arg(argptr, int);
                    strtmp++;
                } else {
                    while ((*strtmp >= 48) && (*strtmp <= 57)) {
                        width = (width * 10) + ((int)*strtmp - 48);
                        strtmp++;
                    }
                }
            }

            // опредляем точность
            if (*strtmp == '.') {
                strtmp++;
                if (*strtmp == '*') {
                    precision = va_arg(argptr, int);
                    strtmp++;
                } else {
                    while ((*strtmp >= 48) && (*strtmp <= 57)) {
                        precision = (precision * 10) + ((int)*strtmp - 48);
                        strtmp++;
                    }
                }
            }
            
            // определяем Модификатор размера
            if ((*strtmp == 'l') || (*strtmp == 'h') || (*strtmp == 'j') || (*strtmp == 'z') || (*strtmp == 't') || (*strtmp == 'L')) {
                length = *strtmp;
                strtmp++;
            }

            // определяем Спецификатор типа
            switch (*strtmp) {
            // целое десятичное знаковое число
            case 'd' || 'i':
                switch (length) {
                case 'l':
                    ld(va_arg(argptr, long int),flag, width, precision, buf);
                    break;
                case 0:
                    d(va_arg(argptr, int),flag, width, precision, buf);
                    break;
                }
                break;

            // символ
            case 'c':
                switch (length) {
                case 'l':
                    lc(va_arg(argptr, wint_t),flag, width, precision, buf);
                    break;
                case 0:
                    c(va_arg(argptr, int),flag, width, precision, buf);
                    break;
                }
                break;

            // строка
            case 's':
                switch (length) {
                case 'l':
                    ls(va_arg(argptr, wchar_t*),flag, width, precision, buf);
                    break;
                case 0:
                    s(va_arg(argptr, char*),flag, width, precision, buf);
                    break;
                }
                break;

            // дробное число
            case 'f':
                switch (length) {
                case 'L':
                    Lf(va_arg(argptr, long double),flag, width, precision, buf);
                    break;
                case 0:
                    f(va_arg(argptr, double),flag, width, precision, buf);
                    break;
                }
                break;

            // десятичное беззнаковое число
            case 'u':
                switch (length) {
                case 'l':
                    lu(va_arg(argptr, unsigned long int),flag, width, precision, buf);
                    break;
                case 0:
                    u(va_arg(argptr, unsigned int),flag, width, precision, buf);
                    break;
                }
                break;

            // числа с плавающей запятой в экспоненциальной форме записи (вида 1.1e+44)
            case 'e':
                switch (length) {
                case 0:
                    e(va_arg(argptr, double),flag, width, precision, buf);
                    break;
                case 'L':
                    Le(va_arg(argptr, long double),flag, width, precision, buf);
                    break;
                }
                break;

            // числа с плавающей запятой в экспоненциальной форме записи  (3.14E+0)
            case 'E':
                switch (length) {
                case 0:
                    E(va_arg(argptr, double),flag, width, precision, buf);
                    break;
                case 'L':
                    LE(va_arg(argptr, long double),flag, width, precision, buf);
                    break;
                }
                break;
            
            // число с плавающей запятой
            case 'g':
                switch (length) {
                case 0:
                    g(va_arg(argptr, double),flag, width, precision, buf);
                    break;
                case 'L':
                    Lg(va_arg(argptr, long double),flag, width, precision, buf);
                    break;
                }
                break;

            // число с плавающей запятой
            case 'G':
                switch (length) {
                case 0:
                    g(va_arg(argptr, double),flag, width, precision, buf);
                    break;
                case 'L':
                    Lg(va_arg(argptr, long double),flag, width, precision, buf);
                    break;
                }
                break;

            // Беззнаковое шестнадцатеричное целое
            case 'x':
                switch (length) {
                case 'l':
                    lx(va_arg(argptr, unsigned long int),flag, width, precision, buf);
                    break;
                case 0:
                    x(va_arg(argptr, unsigned int),flag, width, precision, buf);
                    break;
                }
                break;

            // Беззнаковое шестнадцатеричное целое (заглавными буквами)
            case 'X':
                switch (length) {
                case 'l':
                    lX(va_arg(argptr, unsigned long int),flag, width, precision, buf);
                    break;
                case 0:
                    X(va_arg(argptr, unsigned int),flag, width, precision, buf);
                    break;
                }
                break;

            // восьмеричное беззнаковое число
            case 'o':
                switch (length) {
                case 'l':
                    lo(va_arg(argptr, unsigned long int),flag, width, precision, buf);
                    break;
                case 0:
                    o(va_arg(argptr, unsigned int),flag, width, precision, buf);
                    break;
                }
                break;

            // Адрес указателя
            case 'p':
                if (length == 0) {
                    P(va_arg(argptr, void* ),flag, width, buf);
                }
                break;

            // количество напечатаных символов
            case 'n':
                *buf = '\0';
                    *(va_arg(argptr, int* )) = (int) s21_strlen(str);
                break;
            }
            
            // смещаем на конец строки
            while (*buf != '\0') {
                buf++;
            }

            //вывод занака %
            if ((*strtmp == '%') && (*(strtmp-1) == '%')) {
                *buf = *strtmp;
                buf++;
                strtmp++;
            }
            
        }

        *buf = *strtmp;
        buf++;
        strtmp++;
      //  va_arg(argptr,double);

        
        va_end(argptr);
    }
    ret = (int) s21_strlen(str);
    return ret;
}

char* P(void* a,char flag, int width, char* buf) {
    char s[128];
    char* str = buf, *tmps = s;
    size_t tmp;
    tmp = (size_t) a;
    DtoH (tmp, tmps);
    int i = width - (int)s21_strlen(tmps);
    switch (flag) {
    case 0:
        if (width != 0) {
            while (i>0) {
                *str = ' ';
                str++;
                i--;
            }
        } else if (width == 0) {
            i = 16 - (int)s21_strlen(tmps);
            while (i>0) {
                *str = '0';
                str++;
                i--;
            }
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    case '-':
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        if (width != 0) {
            while (i>0) {
                *str = ' ';
                str++;
                i--;
            }
        }
        *str = *tmps;
        break;
    }

    return buf;
}

char* DtoH (size_t d, char* buf) {
    char s[128];
    char* tmps = buf, *str = s + 128;
    int tmph;
    *str = '\0';
    while (d > 0) {
        str--;
        tmph = d % 16;
        *str = tmph + 48;
        if (*str > 57)
            *str = *str + 39;
        d = d / 16;
    }
    while (*str != '\0') {
        *tmps = *str;
        tmps++;
        str++;
    }
    *tmps = *str;
    return buf;
}

lx(unsigned long int d, char flag, int width, int precision, char *buf) {
    char s[128];
    char *str = buf, *tmps = s;
    DtoH ((size_t)d, tmps);
    int i = width - (int)s21_strlen(tmps);
    int j = precision - (int)s21_strlen(tmps);
    switch (flag) {
    case 0:
        while (i-j > 0) {
            *str = ' ';
            str++;
            i--;
        }
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    case '-':
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        while (i-j > 0) {
            *str = ' ';
            str++;
            i--;
        }
        *str = *tmps;
        break;
    case '#':
        while (i-j-2 > 0) {
            *str = ' ';
            str++;
            i--;
        }
        *str = '0';
        str++;
        *str = 'x';
        str++;
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    case '0':
        while (i> 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    }
}

x(unsigned int d, char flag, int width, int precision, char *buf) {
    char s[128];
    char *str = buf, *tmps = s;
    DtoH ((size_t)d, tmps);
    int i = width - (int)s21_strlen(tmps);
    int j = precision - (int)s21_strlen(tmps);
    switch (flag) {
    case 0:
        while (i-j > 0) {
            *str = ' ';
            str++;
            i--;
        }
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    case '-':
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        while (i-j > 0) {
            *str = ' ';
            str++;
            i--;
        }
        *str = *tmps;
        break;
    case '#':
        while (i-j-2 > 0) {
            *str = ' ';
            str++;
            i--;
        }
        *str = '0';
        str++;
        *str = 'x';
        str++;
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    case '0':
        while (i> 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    }
}

lX(unsigned long int d, char flag, int width, int precision, char *buf) {
    char s[128];
    char *str = buf, *tmps = s;
    DtoH ((size_t)d, tmps);
    int i = width - (int)s21_strlen(tmps);
    int j = precision - (int)s21_strlen(tmps);
    switch (flag) {
    case 0:
        while (i-j > 0) {
            *str = ' ';
            str++;
            i--;
        }
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            if (*str > 57)
                *str = *str - 31;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    case '-':
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            if (*str > 57)
                *str = *str - 31;
            str++;
            tmps++;
        }
        while (i-j > 0) {
            *str = ' ';
            str++;
            i--;
        }
        *str = *tmps;
        break;
    case '#':
        while (i-j-2 > 0) {
            *str = ' ';
            str++;
            i--;
        }
        *str = '0';
        str++;
        *str = 'x';
        str++;
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            if (*str > 57)
                *str = *str - 31;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    case '0':
        while (i> 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            if (*str > 57)
                *str = *str - 31;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    }
}

X(unsigned int d, char flag, int width, int precision, char *buf) {
    char s[128];
    char *str = buf, *tmps = s;
    DtoH ((size_t)d, tmps);
    int i = width - (int)s21_strlen(tmps);
    int j = precision - (int)s21_strlen(tmps);
    switch (flag) {
    case 0:
        while (i-j > 0) {
            *str = ' ';
            str++;
            i--;
        }
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            if (*str > 57)
                *str = *str - 31;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    case '-':
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            if (*str > 57)
                *str = *str - 31;
            str++;
            tmps++;
        }
        while (i-j > 0) {
            *str = ' ';
            str++;
            i--;
        }
        *str = *tmps;
        break;
    case '#':
        while (i-j-2 > 0) {
            *str = ' ';
            str++;
            i--;
        }
        *str = '0';
        str++;
        *str = 'x';
        str++;
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            if (*str > 57)
                *str = *str - 31;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    case '0':
        while (i> 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            if (*str > 57)
                *str = *str - 31;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    }
}
char* DtoO (size_t d, char* buf) {
    char s[128];
    char* tmps = buf, *str = s + 128;
    int tmph;
    *str = '\0';
    while (d > 0) {
        str--;
        tmph = d % 8;
        *str = tmph + 48;
        d = d / 8;
    }
    while (*str != '\0') {
        *tmps = *str;
        tmps++;
        str++;
    }
    *tmps = *str;
    return buf;
}

lo(unsigned long int d, char flag, int width, int precision, char *buf) {
    char s[128];
    char *str = buf, *tmps = s;
    DtoO ((size_t)d, tmps);
    int i = width - (int)s21_strlen(tmps);
    int j = precision - (int)s21_strlen(tmps);
    switch (flag) {
    case 0:
        while (i-j > 0) {
            *str = ' ';
            str++;
            i--;
        }
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    case '-':
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        while (i-j > 0) {
            *str = ' ';
            str++;
            i--;
        }
        *str = *tmps;
        break;
    case '#':
        while (i-j-1 > 0) {
            *str = ' ';
            str++;
            i--;
        }
        *str = '0';
        str++;
        while (j-0 > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    case '0':
        while (i> 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    }
}

o(unsigned int d, char flag, int width, int precision, char *buf) {
    char s[128];
    char *str = buf, *tmps = s;
    DtoO ((size_t)d, tmps);
    int i = width - (int)s21_strlen(tmps);
    int j = precision - (int)s21_strlen(tmps);
    switch (flag) {
    case 0:
        while (i-j > 0) {
            *str = ' ';
            str++;
            i--;
        }
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    case '-':
        while (j > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        while (i-j > 0) {
            *str = ' ';
            str++;
            i--;
        }
        *str = *tmps;
        break;
    case '#':
        while (i-j-1 > 0) {
            *str = ' ';
            str++;
            i--;
        }
        *str = '0';
        str++;
        while (j-0 > 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    case '0':
        while (i> 0) {
            *str = '0';
            str++;
            i--;
        }
        while (*tmps != '\0') {
            *str = *tmps;
            str++;
            tmps++;
        }
        *str = *tmps;
        break;
    }
}
