#include <stdio.h>
#include <string.h>

char *s21_strerror(int errnum);

int main () {
    
    int errcode;
    errcode = 41;
    printf ("Error %d: %s\n", errcode, strerror (errcode) );
    printf ("Error %d: %s\n", errcode, s21_strerror (errcode) );
    return 0;
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