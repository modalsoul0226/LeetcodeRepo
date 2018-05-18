#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
strStr(char* haystack, char* needle) 
{
    if (!haystack || !strlen(haystack)) return 0;
    
    for (int i = 0; i <= strlen(haystack) - strlen(needle); i++) {
        int same = 1;
        if (haystack[i] == needle[0]) {
            for (int j = 0; j < strlen(needle); j++) {
                if (haystack[i + j] != needle[j]) { same = 0; break;}
            }
            
            if (same) return i;
        }
    }
    
    return -1;
}

int 
main(int argc, char const *argv[])
{
    /* code */
    char *haystack = "hello";
    char *needle = "ll";
    printf("index: %d\n", strStr(haystack, needle));

    return 0;
}
