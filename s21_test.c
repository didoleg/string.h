#include <stdio.h>
#include <check.h>
#include "s21_string.h"
#include <string.h>
#include <stdlib.h>

START_TEST(s21_memset_test1) {
    char mas1[100] = "Hello!";
    ck_assert_str_eq(s21_memset(mas1, 'c', 2), memset(mas1, 'c', 2));
}


START_TEST(s21_memset_test2) {
    char mas2[100] = "Gracias!";
    ck_assert_str_eq(s21_memset(mas2, '3', 4), memset(mas2, '3', 4));
}

START_TEST(s21_memset_test3) {
    char mas3[100] = "";
    ck_assert_str_eq(s21_memset(mas3, '2', 1), memset(mas3, '2', 1));
}

START_TEST(s21_memset_test4) {
    char mas4[100] = "1234 yes  no\0";
    ck_assert_str_eq(s21_memset(mas4, '0', 4), memset(mas4, '0', 4));
}

START_TEST(s21_strcat_test1) {
    char mas1[100] = "Hello!";
    char mas2[10] = "Gracias!";
    ck_assert_str_eq(s21_strcat(mas1, mas2), strcat(mas1, mas2));
}

START_TEST(s21_strcat_test2) {
    char mas1[100] = "";
    char mas2[10] = "Gracias!";
    ck_assert_str_eq(s21_strcat(mas1, mas2), strcat(mas1, mas2));
}

START_TEST(s21_strcat_test3) {
    char mas1[100] = "123 ";
    char mas2[10] = "Gracias!";
    ck_assert_str_eq(s21_strcat(mas1, mas2), strcat(mas1, mas2));
}

START_TEST(s21_strcat_test4) {
    char mas1[100] = "123 ";
    char mas2[10] = "Gracias!";
    ck_assert_str_eq(s21_strcat(mas1, mas2), strcat(mas1, mas2));
}

START_TEST(s21_strncat_test1) {
    char mas1[100] = "Hello!";
    char mas2[10] = "Gracias!";
    ck_assert_str_eq(s21_strncat(mas1, mas2, 4), strncat(mas1, mas2, 4));
}
END_TEST

START_TEST(s21_strncat_test2) {
    char mas1[100] = "Hello!";
    char mas2[10] = "012345!";
    ck_assert_str_eq(s21_strncat(mas1, mas2, 4), strncat(mas1, mas2, 4));
}

START_TEST(s21_strncat_test3) {
    char mas1[100] = "";
    char mas2[10] = "012345!";
    ck_assert_str_eq(s21_strncat(mas1, mas2, 4), strncat(mas1, mas2, 4));
}

START_TEST(s21_strncat_test4) {
    char mas1[100] = "    ";
    char mas2[10] = "012345!";
    ck_assert_str_eq(s21_strncat(mas1, mas2, 4), strncat(mas1, mas2, 4));
}

START_TEST(s21_strchr_test1) {
    char mas1[100] = "Hello!";
    ck_assert_str_eq(s21_strchr(mas1, 'l'), strchr(mas1, 'l'));
}

START_TEST(s21_strchr_test2) {
    char mas1[100] = "22111!";
    ck_assert_str_eq(s21_strchr(mas1, '1'), strchr(mas1, '1'));
}

START_TEST(s21_strchr_test3) {
    char mas1[100] = "     ll";
    ck_assert_str_eq(s21_strchr(mas1, 'l'), strchr(mas1, 'l'));
}

START_TEST(s21_strchr_test4) {
    char mas1[100] = "";
    ck_assert_ptr_eq(s21_strchr(mas1, '1'), strchr(mas1, '1'));
}

START_TEST(s21_memchr_test1) {
    const char* str = "abcdefgh12!b56v";
    int c = 33;
    ck_assert_str_eq(s21_memchr(str, c, 15), memchr(str, c, 15));
}

START_TEST(s21_memchr_test2) {
    const char* str = "abcdefghccccccccccch";
    int c = 100;
    ck_assert_str_eq(s21_memchr(str, c, 10), memchr(str, c, 10));
}

START_TEST(s21_memchr_test3) {
    const char* str = "abcd7efghccccccccccch";
    int c = 55;
    ck_assert_ptr_eq(s21_memchr(str, c, 15), memchr(str, c, 15));
}

START_TEST(s21_memchr_test4) {
    const char* str = "ab0cdefghccccccccccch";
    int c = 48;
    ck_assert_str_eq(s21_memchr(str, c, 15), memchr(str, c, 15));
}

START_TEST(s21_memcmp_test1) {
    const char* str = "0123456789";
    const char* str1 = "210";
    int n = 3;
    ck_assert_int_lt(s21_memcmp(str, str1, n), 0);
}

START_TEST(s21_memcmp_test2) {
    const char* str = "0123456789";
    const char* str1 = "0123456789";
    int n = 10;
    ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
}

START_TEST(s21_memcmp_test3) {
    const char* str = "0123456789";
    const char* str1 = "01223456789";
    int n = 2;
    ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
}

START_TEST(s21_memcmp_test4) {
    const char* str = "";
    const char* str1 = "456789";
    int n = 1;
    ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
}

START_TEST(s21_memcmp_test5) {
    const char* str = "";
    const char* str1 = "";
    int n = 1;
    ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
}

START_TEST(s21_memcpy_test1) {
    char str[99] = "qwerty";
    const char *str1 = "345";
    int n = 3;
    ck_assert_str_eq(s21_memcpy(str, str1, n), memcpy(str, str1, n));
}

START_TEST(s21_memcpy_test2) {
    char str[99] = "";
    const char *str1 = "aaa";
    int n = 3;
    ck_assert_ptr_eq(s21_memcpy(str, str1, n), memcpy(str, str1, n));
}

START_TEST(s21_memcpy_test3) {
    char str[99] = "0123123456789";
    const char *str1 = "!!!!!!!";
    int n = 5;
    ck_assert_str_eq(s21_memcpy(str, str1, n), memcpy(str, str1, n));
}

START_TEST(s21_memcpy_test4) {
    char str[99] = "ahdfrtbcjdufh";
    const char *str1 = "1234";
    int n = 4;
    ck_assert_str_eq(s21_memcpy(str, str1, n), memcpy(str, str1, n));
}

START_TEST(s21_memmove_test1) {
    char str[99] = "qwerty";
    char *str1 = str + 2;
    int n = 2;
    ck_assert_str_eq(s21_memmove(str, str1, n), memmove(str, str1, n));
}

START_TEST(s21_memmove_test2) {
    char str[99] = "";
    const char *str1 = "aaa!@#";
    int n = 6;
    ck_assert_ptr_eq(s21_memmove(str, str1, n), memmove(str, str1, n));
}

START_TEST(s21_memmove_test3) {
    char str[99] = "0123123456789";
    const char *str1 = "!!!!!!!";
    int n = 5;
    ck_assert_str_eq(s21_memmove(str, str1, n), memmove(str, str1, n));
}

START_TEST(s21_memmove_test4) {
    char str[99] = "ahdfrtbcjdufh";
    const char *str1 = "1234";
    int n = 4;
    ck_assert_str_eq(s21_memmove(str, str1, n), memmove(str, str1, n));
}

START_TEST(s21_strcspn_test1) {
    const char* str = "0123456789";
    const char* str1 = "789";
    ck_assert_uint_eq(s21_strcspn(str, str1), strcspn(str, str1));
}

START_TEST(s21_strcspn_test2) {
    const char* str = "0123456789asd";
    const char* str1 = "asd";;
    ck_assert_uint_eq(s21_strcspn(str, str1), strcspn(str, str1));
}

START_TEST(s21_strcspn_test3) {
    const char* str = "!!!!1";
    const char* str1 = "1";
    ck_assert_uint_eq(s21_strcspn(str, str1), strcspn(str, str1));
}

START_TEST(s21_strcspn_test4) {
    const char* str = "21w1w1";
    const char* str1 = "2";
    ck_assert_uint_eq(s21_strcspn(str, str1), strcspn(str, str1));
}

START_TEST(s21_strcspn_test5) {
    const char* str = "rtrtruppp44556hhfg";
    const char* str1 = "6";
    ck_assert_uint_eq(s21_strcspn(str, str1), strcspn(str, str1));
}

START_TEST(s21_strpbrk_test1) {
    const char* str = "0123456789";
    const char* str1 = "987";
    ck_assert_ptr_eq(s21_strpbrk(str, str1), strpbrk(str, str1));
}

START_TEST(s21_strpbrk_test2) {
    const char* str = "0123456789asd";
    const char* str1 = "asd";;
    ck_assert_ptr_eq(s21_strpbrk(str, str1), strpbrk(str, str1));
}

START_TEST(s21_strpbrk_test3) {
    const char* str = "";
    const char* str1 = "1";
    ck_assert_ptr_eq(s21_strpbrk(str, str1), strpbrk(str, str1));
}

START_TEST(s21_strpbrk_test4) {
    const char* str = "21w1w1";
    const char* str1 = "2";
    ck_assert_ptr_eq(s21_strpbrk(str, str1), strpbrk(str, str1));
}

START_TEST(s21_strpbrk_test5) {
    const char* str = "rtrtruppp44556hhfg";
    const char* str1 = "7";
    ck_assert_ptr_eq(s21_strpbrk(str, str1), strpbrk(str, str1));
}

START_TEST(s21_strlen_test1) {
    const char* str = "0123456789";
    ck_assert_uint_eq(s21_strlen(str), strlen(str));
}

START_TEST(s21_strlen_test2) {
    const char* str = "";
    ck_assert_uint_eq(s21_strlen(str), strlen(str));
}

START_TEST(s21_strlen_test3) {
    const char* str = "!!!!1";  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}

START_TEST(s21_strlen_test4) {
    const char* str = "21w1w1";  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}

START_TEST(s21_strlen_test5) {
    const char* str = "rtrtruppp44556hhfg";  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}

START_TEST(s21_strrchr_test1) {
    const char* str = "abcdefgh";
    int c = 99;
    char* res = s21_strrchr(str, c);
    ck_assert_str_eq(res, strrchr(str, c));
}

START_TEST(s21_strrchr_test2) {
    const char* str = "abcdefghccccccccccch";
    int c = 99;
    char* res = s21_strrchr(str, c);
    ck_assert_str_eq(res, strrchr(str, c));
}

START_TEST(s21_strrchr_test3) {
    const char* str = "abcdefghccccccccccch";
    int c = 55;
    char* res = s21_strrchr(str, c);
    ck_assert_ptr_eq(res, strrchr(str, c));
}

START_TEST(s21_strrchr_test4) {
    const char* str = "abcdefghccccccccccch";
    int c = 0;
    char* res = s21_strrchr(str, c);
    ck_assert_str_eq(res, strrchr(str, c));
}

START_TEST(s21_strspn_test1) {
    const char* str = "0123456789";
    const char* str1 = "210";
    ck_assert_uint_eq(s21_strspn(str, str1), strspn(str, str1));
}

START_TEST(s21_strspn_test2) {
    const char* str = "0123456789";
    const char* str1 = "0123456789";
    ck_assert_uint_eq(s21_strspn(str, str1), strspn(str, str1));
}

START_TEST(s21_strspn_test3) {
    const char* str = "0123456789";
    const char* str1 = "456789";
    ck_assert_uint_eq(s21_strspn(str, str1), strspn(str, str1));
}

START_TEST(s21_strspn_test4) {
    const char* str = "";
    const char* str1 = "456789";
    ck_assert_uint_eq(s21_strspn(str, str1), strspn(str, str1));
}

START_TEST(s21_strspn_test5) {
    const char* str = "";
    const char* str1 = "";
    ck_assert_uint_eq(s21_strspn(str, str1), strspn(str, str1));
}

START_TEST(s21_strstr_test1) {
    const char *str = "0123456789";
    const char *str1 = "345";
    ck_assert_str_eq(s21_strstr(str, str1), strstr(str, str1));
}

START_TEST(s21_strstr_test2) {
    const char *str = "0123456789";
    const char *str1 = "aaa";
    ck_assert_ptr_eq(s21_strstr(str, str1), strstr(str, str1));
}

START_TEST(s21_strstr_test3) {
    const char *str = "0123123456789";
    const char *str1 = "1234";
    ck_assert_str_eq(s21_strstr(str, str1), strstr(str, str1));
}

START_TEST(s21_strstr_test4) {
    const char *str = "01234123456789";
    const char *str1 = "1234";
    ck_assert_str_eq(s21_strstr(str, str1), strstr(str, str1));
}

START_TEST(s21_strtok_test1) {
    char str[] = "The summer soldier, the sunshine patriot";
    char str1[] = "The summer soldier, the sunshine patriot";
    char* res = s21_strtok(str, " ");
    ck_assert_str_eq(res, strtok(str1, " "));
    char* res1 = s21_strtok(s21_NULL, " ");
    ck_assert_str_eq(res1, strtok(s21_NULL, " "));
    char* res2 = s21_strtok(s21_NULL, " ");
    ck_assert_str_eq(res2, strtok(s21_NULL, " "));
    char* res3 = s21_strtok(s21_NULL, " ");
    ck_assert_str_eq(res3, strtok(s21_NULL, " "));
    char* res4 = s21_strtok(s21_NULL, " ");
    ck_assert_str_eq(res4, strtok(s21_NULL, " "));
    char* res5 = s21_strtok(s21_NULL, " ");
    ck_assert_str_eq(res5, strtok(s21_NULL, " "));
    char* res6 = s21_strtok(s21_NULL, " ");
    ck_assert_ptr_eq(res6, strtok(s21_NULL, " "));
}

START_TEST(s21_strerror_test1) {
    for (int i = -100; i <= 206; i++) {
        ck_assert_str_eq(s21_strerror(i), strerror(i));
    }
}

START_TEST(s21_strcmp_test1) {
    const char* s1 = "qwerty12345";
    const char* s2 = "qwerty12345";
    ck_assert_int_eq(s21_strcmp(s1, s2), strcmp(s1, s2));
}

START_TEST(s21_strcmp_test2) {
    const char* s1 = "ab56efg";
    const char* s2 = "ycbhu43";
    ck_assert_int_eq(s21_strcmp(s1, s2), strcmp(s1, s2));
}

START_TEST(s21_strcmp_test3) {
    const char* s1 = "qwerty12345";
    const char* s2 = "";
    ck_assert_int_eq(s21_strcmp(s1, s2), strcmp(s1, s2));
}

START_TEST(s21_strcmp_test4) {
    const char* s1 = "";
    const char* s2 = "qwerty12345";
    ck_assert_int_eq(s21_strcmp(s1, s2), strcmp(s1, s2));
}

START_TEST(s21_strcmp_test5) {
    const char* s1 = "";
    const char* s2 = "";
    ck_assert_int_eq(s21_strcmp(s1, s2), strcmp(s1, s2));
}

START_TEST(s21_strncmp_test1) {
    const char* s1 = "qwerty12345";
    const char* s2 = "qwerty12345";
    s21_size_t n = 11;
    ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}

START_TEST(s21_strncmp_test2) {
    const char* s1 = "qwerty12345";
    const char* s2 = "qwerty12345";
    s21_size_t n = 15;
    ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}

START_TEST(s21_strncmp_test3) {
    const char* s1 = "ab56efg";
    const char* s2 = "acbhu43";
    s21_size_t n = 4;
    ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}

START_TEST(s21_strncmp_test4) {
    const char* s1 = "aaaaafg";
    const char* s2 = "aaaaa43";
    s21_size_t n = 6;
    ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}

START_TEST(s21_strncmp_test5) {
    const char* s1 = "qwerty12345";
    const char* s2 = "";
    s21_size_t n = 5;
    ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}

START_TEST(s21_strncmp_test6) {
    const char* s1 = "";
    const char* s2 = "qwerty12345";
    s21_size_t n = 0;
    ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}

START_TEST(s21_strncmp_test7) {
    const char* s1 = "";
    const char* s2 = "";
    s21_size_t n = 5;
    ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}

START_TEST(s21_strcpy_test1) {
    char s1[100] = "qwerty12345";
    const char* s2 = "12345\0qwerty";
    ck_assert_str_eq(s21_strcpy(s1, s2), strcpy(s1, s2));
}

START_TEST(s21_strcpy_test2) {
    char s1[100] = "ab56efg";
    const char* s2 = "ycbhu43";
    ck_assert_str_eq(s21_strcpy(s1, s2), strcpy(s1, s2));
}

START_TEST(s21_strcpy_test3) {
    char s1[100] = "qwerty12345";
    const char* s2 = "";
    ck_assert_str_eq(s21_strcpy(s1, s2), strcpy(s1, s2));
}

START_TEST(s21_strcpy_test4) {
    char s1[100] = "";
    const char* s2 = "qwerty12345";
    ck_assert_str_eq(s21_strcpy(s1, s2), strcpy(s1, s2));
}

START_TEST(s21_strncpy_test1) {
    char s1[100] = "qwerty12345";
    const char* s2 = "12345qwerty";
    s21_size_t n = 11;
    ck_assert_str_eq(s21_strncpy(s1, s2, n), strncpy(s1, s2, n));
}

START_TEST(s21_strncpy_test2) {
    char s1[100] = "ab56efg";
    const char* s2 = "ycbhu43";
    s21_size_t n = 11;
    ck_assert_str_eq(s21_strncpy(s1, s2, n), strncpy(s1, s2, n));
}

START_TEST(s21_strncpy_test3) {
    char s1[100] = "qwerty12345";
    const char* s2 = "";
    s21_size_t n = 5;
    ck_assert_str_eq(s21_strncpy(s1, s2, n), strncpy(s1, s2, n));
}

START_TEST(s21_strncpy_test4) {
    char s1[100] = "";
    const char* s2 = "qwerty12345";
    s21_size_t n = 5;
    ck_assert_str_eq(s21_strncpy(s1, s2, n), strncpy(s1, s2, n));
}

START_TEST(s21_strncpy_test5) {
    char s1[100] = "qwerty12345";
    const char* s2 = "qwerty12345";
    s21_size_t n = 0;
    ck_assert_str_eq(s21_strncpy(s1, s2, n), strncpy(s1, s2, n));
}

START_TEST(s21_sprintf_test1) {
    char str[500];
    char str1[500];
    int r1 = s21_sprintf(str, "%-2.3f % d! %+3.4i % 5.3d %4.4u", -6.2f, 666, 555, 444, 333);
    int r2 = sprintf(str1, "%-2.3f % d! %+3.4i % 5.3d %4.4u", -6.2f, 666, 555, 444, 333);
    ck_assert_str_eq(str, str1);
    ck_assert_int_eq(r1, r2);
}

START_TEST(s21_sprintf_test2) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%2.3f % d! %3.4i %5.3d %-4.4u", -5.5f, 213, 52315, 1, 745);
    sprintf(str1, "%2.3f % d! %3.4i %5.3d %-4.4u", -5.5f, 213, 52315, 1, 745);
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test3) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%s", "1234");
    sprintf(str1, "%s", "1234");
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test4) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%-5s %-8c", "1234", '5');
    sprintf(str1, "%-5s %-8c", "1234", '5');
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test5) {
    char str[500];
    char str1[500];
    short sh = 12;
    long lg = 1212121212;
    s21_sprintf(str, "%-5ld %-8hi", lg, sh);
    sprintf(str1, "%-5ld %-8hi", lg, sh);
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test6) {
    char str[500];
    char str1[500];
    short sh = 12;
    long lg = 1212121212;
    s21_sprintf(str, "% .5ld %+.8hi", lg, sh);
    sprintf(str1, "% .5ld %+.8hi", lg, sh);
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test7) {
    char str[500];
    char str1[500];
    short sh = 12;
    long lg = 1212121212;
    s21_sprintf(str, "% .5li %+.8hd", lg, sh);
    sprintf(str1, "% .5li %+.8hd", lg, sh);
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test8) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%f %d", 1.54162735145f, 666666);
    sprintf(str1, "%f %d", 1.54162735145f, 666666);
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test9) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "2144135 dewqfrq 9§4§d§2=f431v32v2");
    sprintf(str1, "2144135 dewqfrq 9§4§d§2=f431v32v2");
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test10) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%d", -666666);
    sprintf(str1, "%d", -666666);
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test11) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%-9.4d %-4.9d %d", -6, -3, -2);
    sprintf(str1, "%-9.4d %-4.9d %d", -6, -3, -2);
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test12) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%9.2d", -65);
    sprintf(str1, "%9.2d", -65);
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test13) {
    char str[500];
    char str1[500];
    unsigned long ul = 453459295;
    unsigned short uh = 777;
    s21_sprintf(str, "%lu %hu", ul, uh);
    sprintf(str1, "%lu %hu", ul, uh);
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test14) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%9c", '!');
    sprintf(str1, "%9c", '!');
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test15) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%-.3s %.5s", "1234567890", "1234567890");
    sprintf(str1, "%-.3s %.5s", "1234567890", "1234567890");
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test16) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%-6.3s %6.2s %6s", "1234", "1234", "abc");
    sprintf(str1, "%-6.3s %6.2s %6s", "1234", "1234", "abc");
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test17) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%+10f % 10f %+f % f", 1.111111f, 1.111111f, 1.111111f, 1.111111f);
    sprintf(str1, "%+10f % 10f %+f % f", 1.111111f, 1.111111f, 1.111111f, 1.111111f);
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test18) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%+d", 13);
    sprintf(str1, "%+d", 13);
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test19) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%-10f", 1.111111f);
    sprintf(str1, "%-10f", 1.111111f);
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test20) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%-10.2f", -1.111f);
    sprintf(str1, "%-10.2f", -1.111f);
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test21) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%-d %12.2d", 999, 6666);
    sprintf(str1, "%-d %12.2d", 999, 6666);
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_sprintf_test22) {
    char str[500];
    char str1[500];
    s21_sprintf(str, "%-d %+12.2d", 999, 6666);
    sprintf(str1, "%-d %+12.2d", 999, 6666);
    ck_assert_str_eq(str, str1);
}

START_TEST(s21_trim_test1) {
    const char src[] = "";
    const char trim[] = "";
    char* result = s21_trim(src, trim);
    ck_assert_str_eq(result, "");
    free(result);
}

START_TEST(s21_trim_test2) {
    const char src[] = "123";
    const char trim[] = "";
    char* result = s21_trim(src, trim);
    ck_assert_str_eq(result, "123");
    free(result);
}

START_TEST(s21_trim_test3) {
    const char src[] = "";
    const char trim[] = "123";
    char* result = s21_trim(src, trim);
    ck_assert_str_eq(result, "");
    free(result);
}

START_TEST(s21_trim_test4) {
    const char src[] = "2 aaa 1";
    const char trim[] = " 12";
    char* result = s21_trim(src, trim);
    ck_assert_str_eq(result, "aaa");
    free(result);
}

START_TEST(s21_trim_test5) {
    char* src = s21_NULL;
    char* trim = s21_NULL;
    char* result = s21_trim(src, trim);
    ck_assert_ptr_eq(result, s21_NULL);
    free(result);
}

START_TEST(s21_to_upper_test1) {
    char mas[] = "Hello!";
    char* mas1;
    mas1 = s21_to_upper(mas);
    ck_assert_str_eq(mas1, "HELLO!");
    free(mas1);
}

START_TEST(s21_to_upper_test2) {
    char mas[] = "123hah!";
    char* mas1;
    mas1 = s21_to_upper(mas);
    ck_assert_str_eq(mas1, "123HAH!");
    free(mas1);
}

START_TEST(s21_to_lower_test1) {
    char mas[] = "Hello!";
    char* mas1;
    mas1 = s21_to_lower(mas);
    ck_assert_str_eq(mas1, "hello!");
    free(mas1);
}

START_TEST(s21_to_lower_test2) {
    char mas[] = "123HAH!";
    char* mas1;
    mas1 = s21_to_lower(mas);
    ck_assert_str_eq(mas1, "123hah!");
    free(mas1);
}

Suite* s21_to_upper_suite() {
    Suite* s = suite_create("To_upper");
    TCase* s21_to_upperCase = tcase_create("BaseTest");
    tcase_add_test(s21_to_upperCase, s21_to_upper_test1);
    tcase_add_test(s21_to_upperCase, s21_to_upper_test2);
    suite_add_tcase(s, s21_to_upperCase);
    return s;
}

Suite* s21_to_lower_suite() {
    Suite* s = suite_create("To_lower");
    TCase* s21_to_lowerCase = tcase_create("BaseTest");
    tcase_add_test(s21_to_lowerCase, s21_to_lower_test1);
    tcase_add_test(s21_to_lowerCase, s21_to_lower_test2);
    suite_add_tcase(s, s21_to_lowerCase);
    return s;
}

START_TEST(s21_insert_test1) {
    char src[] = "aaaa";
    char str[] = "111";
    int start_index = 2;
    char* mas1;
    mas1 = s21_insert(src, str, start_index);
    ck_assert_str_eq(mas1, "aa111aa");
    free(mas1);
}

START_TEST(s21_insert_test2) {
    char src[] = "";
    char str[] = "111";
    int start_index = 2;
    char* mas1;
    mas1 = s21_insert(src, str, start_index);
    ck_assert_ptr_eq(mas1, s21_NULL);
    free(mas1);
}

Suite* insert_suite() {
    Suite *s = suite_create("insert");
    TCase *tc_simple = tcase_create("Simple");
    tcase_add_test(tc_simple, s21_insert_test1);
    tcase_add_test(tc_simple, s21_insert_test2);
    suite_add_tcase(s, tc_simple);
    return s;
}

Suite* sprintf_suite(void) {
    Suite* s = suite_create("Sprintf");
    TCase *tc_simple = tcase_create("Simple");

    tcase_add_test(tc_simple, s21_sprintf_test1);
    tcase_add_test(tc_simple, s21_sprintf_test2);
    tcase_add_test(tc_simple, s21_sprintf_test3);
    tcase_add_test(tc_simple, s21_sprintf_test4);
    tcase_add_test(tc_simple, s21_sprintf_test5);
    tcase_add_test(tc_simple, s21_sprintf_test6);
    tcase_add_test(tc_simple, s21_sprintf_test7);
    tcase_add_test(tc_simple, s21_sprintf_test8);
    tcase_add_test(tc_simple, s21_sprintf_test9);
    tcase_add_test(tc_simple, s21_sprintf_test10);
    tcase_add_test(tc_simple, s21_sprintf_test11);
    tcase_add_test(tc_simple, s21_sprintf_test12);
    tcase_add_test(tc_simple, s21_sprintf_test13);
    tcase_add_test(tc_simple, s21_sprintf_test14);
    tcase_add_test(tc_simple, s21_sprintf_test15);
    tcase_add_test(tc_simple, s21_sprintf_test16);
    tcase_add_test(tc_simple, s21_sprintf_test17);
    tcase_add_test(tc_simple, s21_sprintf_test18);
    tcase_add_test(tc_simple, s21_sprintf_test19);
    tcase_add_test(tc_simple, s21_sprintf_test20);
    tcase_add_test(tc_simple, s21_sprintf_test21);
    tcase_add_test(tc_simple, s21_sprintf_test22);

    suite_add_tcase(s, tc_simple);

    return s;
}

Suite* strchr_suite() {
    Suite* s = suite_create("Strchr");
    TCase* tc_simple = tcase_create("Simple");
    tcase_add_test(tc_simple, s21_strchr_test1);
    tcase_add_test(tc_simple, s21_strchr_test2);
    tcase_add_test(tc_simple, s21_strchr_test3);
    tcase_add_test(tc_simple, s21_strchr_test4);
    suite_add_tcase(s, tc_simple);
    return s;
}

Suite* strncat_suite() {
    Suite* s = suite_create("Strncat");
    TCase* tc_simple = tcase_create("Simple");
    tcase_add_test(tc_simple, s21_strncat_test1);
    tcase_add_test(tc_simple, s21_strncat_test2);
    tcase_add_test(tc_simple, s21_strncat_test3);
    tcase_add_test(tc_simple, s21_strncat_test4);
    suite_add_tcase(s, tc_simple);
    return s;
}

Suite* strcat_suite() {
    Suite* s = suite_create("Strcat");
    TCase* tc_simple = tcase_create("Simple");
    tcase_add_test(tc_simple, s21_strcat_test1);
    tcase_add_test(tc_simple, s21_strcat_test2);
    tcase_add_test(tc_simple, s21_strcat_test3);
    tcase_add_test(tc_simple, s21_strcat_test4);
    suite_add_tcase(s, tc_simple);
    return s;
}

Suite* memset_suite() {
    Suite* s = suite_create("Memset");
    TCase* memsetCase = tcase_create("BaseTest");
    tcase_add_test(memsetCase, s21_memset_test1);
    tcase_add_test(memsetCase, s21_memset_test2);
    tcase_add_test(memsetCase, s21_memset_test3);
    tcase_add_test(memsetCase, s21_memset_test4);
    suite_add_tcase(s, memsetCase);
    return s;
}

Suite* memmove_suite(void) {
    Suite *s = suite_create("memmove");
    TCase *tc_simple = tcase_create("Simple");
    TCase *tc_strange = tcase_create("Strange");

    tcase_add_test(tc_simple, s21_memmove_test1);
    tcase_add_test(tc_strange, s21_memmove_test2);
    tcase_add_test(tc_simple, s21_memmove_test3);
    tcase_add_test(tc_simple, s21_memmove_test4);

    suite_add_tcase(s, tc_simple);
    suite_add_tcase(s, tc_strange);

    return s;
}

Suite* memcpy_suite(void) {
    Suite *s = suite_create("memcpy");
    TCase *tc_simple = tcase_create("Simple");
    TCase *tc_strange = tcase_create("Strange");

    tcase_add_test(tc_simple, s21_memcpy_test1);
    tcase_add_test(tc_strange, s21_memcpy_test2);
    tcase_add_test(tc_simple, s21_memcpy_test3);
    tcase_add_test(tc_simple, s21_memcpy_test4);

    suite_add_tcase(s, tc_simple);
    suite_add_tcase(s, tc_strange);

    return s;
}

Suite* memcmp_suite(void) {
    Suite *s = suite_create("memcmp");
    TCase *tc_simple = tcase_create("Simple");
    TCase *tc_strange = tcase_create("Strange");

    tcase_add_test(tc_simple, s21_memcmp_test1);
    tcase_add_test(tc_simple, s21_memcmp_test2);
    tcase_add_test(tc_simple, s21_memcmp_test3);
    tcase_add_test(tc_strange, s21_memcmp_test4);
    tcase_add_test(tc_strange, s21_memcmp_test5);

    suite_add_tcase(s, tc_simple);
    suite_add_tcase(s, tc_strange);

    return s;
}

Suite* memchr_suite(void) {
    Suite* s = suite_create("memchr");
    TCase *tc_simple = tcase_create("Simple");
    TCase *tc_strange = tcase_create("Strange");

    tcase_add_test(tc_simple, s21_memchr_test1);
    tcase_add_test(tc_simple, s21_memchr_test2);
    tcase_add_test(tc_strange, s21_memchr_test3);
    tcase_add_test(tc_strange, s21_memchr_test4);

    suite_add_tcase(s, tc_simple);
    suite_add_tcase(s, tc_strange);

    return s;
}

Suite* strcspn_suite(void) {
    Suite *s = suite_create("strcspn");
    TCase *tc_simple = tcase_create("Simple");
    TCase *tc_strange = tcase_create("Strange");

    tcase_add_test(tc_simple, s21_strcspn_test1);
    tcase_add_test(tc_simple, s21_strcspn_test2);
    tcase_add_test(tc_simple, s21_strcspn_test3);
    tcase_add_test(tc_strange, s21_strcspn_test4);
    tcase_add_test(tc_strange, s21_strcspn_test5);

    suite_add_tcase(s, tc_simple);
    suite_add_tcase(s, tc_strange);

    return s;
}

Suite* strpbrk_suite(void) {
    Suite *s = suite_create("strpbrk");
    TCase *tc_simple = tcase_create("Simple");
    TCase *tc_strange = tcase_create("Strange");

    tcase_add_test(tc_simple, s21_strpbrk_test1);
    tcase_add_test(tc_simple, s21_strpbrk_test2);
    tcase_add_test(tc_simple, s21_strpbrk_test3);
    tcase_add_test(tc_strange, s21_strpbrk_test4);
    tcase_add_test(tc_strange, s21_strpbrk_test5);

    suite_add_tcase(s, tc_simple);
    suite_add_tcase(s, tc_strange);

    return s;
}


Suite* strlen_suite(void) {
    Suite *s = suite_create("strlen");
    TCase *tc_simple = tcase_create("Simple");
    TCase *tc_strange = tcase_create("Strange");

    tcase_add_test(tc_simple, s21_strlen_test1);
    tcase_add_test(tc_simple, s21_strlen_test2);
    tcase_add_test(tc_simple, s21_strlen_test3);
    tcase_add_test(tc_strange, s21_strlen_test4);
    tcase_add_test(tc_strange, s21_strlen_test5);

    suite_add_tcase(s, tc_simple);
    suite_add_tcase(s, tc_strange);

    return s;
}

Suite* strerror_suite(void) {
    Suite *s = suite_create("Strerror");
    TCase *tc_simple = tcase_create("Simple");

    tcase_add_test(tc_simple, s21_strerror_test1);

    suite_add_tcase(s, tc_simple);

    return s;
}

Suite* strtok_suite(void) {
    Suite *s = suite_create("Strtok");
    TCase *tc_simple = tcase_create("Simple");

    tcase_add_test(tc_simple, s21_strtok_test1);

    suite_add_tcase(s, tc_simple);

    return s;
}

Suite* strstr_suite(void) {
    Suite *s = suite_create("Strstr");
    TCase *tc_simple = tcase_create("Simple");
    TCase *tc_strange = tcase_create("Strange");

    tcase_add_test(tc_simple, s21_strstr_test1);
    tcase_add_test(tc_strange, s21_strstr_test2);
    tcase_add_test(tc_simple, s21_strstr_test3);
    tcase_add_test(tc_simple, s21_strstr_test4);

    suite_add_tcase(s, tc_simple);
    suite_add_tcase(s, tc_strange);

    return s;
}

Suite* strspn_suite(void) {
    Suite *s = suite_create("Strspn");
    TCase *tc_simple = tcase_create("Simple");
    TCase *tc_strange = tcase_create("Strange");

    tcase_add_test(tc_simple, s21_strspn_test1);
    tcase_add_test(tc_simple, s21_strspn_test2);
    tcase_add_test(tc_simple, s21_strspn_test3);
    tcase_add_test(tc_strange, s21_strspn_test4);
    tcase_add_test(tc_strange, s21_strspn_test5);

    suite_add_tcase(s, tc_simple);
    suite_add_tcase(s, tc_strange);

    return s;
}


Suite* strrchr_suite(void) {
    Suite* s = suite_create("Strrchr");
    TCase *tc_simple = tcase_create("Simple");
    TCase *tc_strange = tcase_create("Strange");

    tcase_add_test(tc_simple, s21_strrchr_test1);
    tcase_add_test(tc_simple, s21_strrchr_test2);
    tcase_add_test(tc_strange, s21_strrchr_test3);
    tcase_add_test(tc_strange, s21_strrchr_test4);

    suite_add_tcase(s, tc_simple);
    suite_add_tcase(s, tc_strange);

    return s;
}

Suite* strcmp_suite(void) {
    Suite* su = suite_create("strcmp");
    TCase* tc = tcase_create("test");
    tcase_add_test(tc, s21_strcmp_test1);
    tcase_add_test(tc, s21_strcmp_test2);
    tcase_add_test(tc, s21_strcmp_test3);
    tcase_add_test(tc, s21_strcmp_test4);
    tcase_add_test(tc, s21_strcmp_test5);
    suite_add_tcase(su, tc);
    return su;
}

Suite* strncmp_suite(void) {
    Suite* su = suite_create("strncmp");
    TCase* tc = tcase_create("test");
    tcase_add_test(tc, s21_strncmp_test1);
    tcase_add_test(tc, s21_strncmp_test2);
    tcase_add_test(tc, s21_strncmp_test3);
    tcase_add_test(tc, s21_strncmp_test4);
    tcase_add_test(tc, s21_strncmp_test5);
    tcase_add_test(tc, s21_strncmp_test6);
    tcase_add_test(tc, s21_strncmp_test7);
    suite_add_tcase(su, tc);
    return su;
}

Suite* strcpy_suite(void) {
    Suite* su = suite_create("strcpy");
    TCase* tc = tcase_create("test");
    tcase_add_test(tc, s21_strcpy_test1);
    tcase_add_test(tc, s21_strcpy_test2);
    tcase_add_test(tc, s21_strcpy_test3);
    tcase_add_test(tc, s21_strcpy_test4);
    suite_add_tcase(su, tc);
    return su;
}

Suite* strncpy_suite(void) {
    Suite* su = suite_create("strncpy");
    TCase* tc = tcase_create("test");
    tcase_add_test(tc, s21_strncpy_test1);
    tcase_add_test(tc, s21_strncpy_test2);
    tcase_add_test(tc, s21_strncpy_test3);
    tcase_add_test(tc, s21_strncpy_test4);
    tcase_add_test(tc, s21_strncpy_test5);
    suite_add_tcase(su, tc);
    return su;
}

Suite* trim_suite(void) {
    Suite* su = suite_create("trim");
    TCase* tc = tcase_create("test");
    tcase_add_test(tc, s21_trim_test1);
    tcase_add_test(tc, s21_trim_test2);
    tcase_add_test(tc, s21_trim_test3);
    tcase_add_test(tc, s21_trim_test4);
    tcase_add_test(tc, s21_trim_test5);
    suite_add_tcase(su, tc);
    return su;
}

int main() {
    int number_bad;
    SRunner* sr = srunner_create(memset_suite());
    srunner_add_suite(sr, strcat_suite());
    srunner_add_suite(sr, strncat_suite());
    srunner_add_suite(sr, strchr_suite());
    srunner_add_suite(sr, memcmp_suite());
    srunner_add_suite(sr, memchr_suite());
    srunner_add_suite(sr, memcpy_suite());
    srunner_add_suite(sr, memmove_suite());
    srunner_add_suite(sr, strcspn_suite());
    srunner_add_suite(sr, strpbrk_suite());
    srunner_add_suite(sr, strlen_suite());
    srunner_add_suite(sr, strrchr_suite());
    srunner_add_suite(sr, strspn_suite());
    srunner_add_suite(sr, strstr_suite());
    srunner_add_suite(sr, strtok_suite());
    srunner_add_suite(sr, strerror_suite());
    srunner_add_suite(sr, strcmp_suite());
    srunner_add_suite(sr, strncmp_suite());
    srunner_add_suite(sr, strcpy_suite());
    srunner_add_suite(sr, strncpy_suite());
    srunner_add_suite(sr, sprintf_suite());
    srunner_add_suite(sr, trim_suite());
    srunner_add_suite(sr, s21_to_upper_suite());
    srunner_add_suite(sr, s21_to_lower_suite());
    srunner_add_suite(sr, insert_suite());
    srunner_run_all(sr, CK_VERBOSE);
    number_bad = srunner_ntests_failed(sr);
    srunner_free(sr);
    return 0;
}
