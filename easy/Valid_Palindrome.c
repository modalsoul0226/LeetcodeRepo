#include <stdio.h>
#include <string.h>

int isPalindrome(char* s) {
    if (strcmp("", s) == 0) return 1;
    
    int size = strlen(s);
    char p_string[size];
    int p_size = 0;
    
    for (int i = 0; i < size; i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            p_string[p_size] = 'a' + s[i] - 'A';
            p_size++;
        } else if ('a' <= s[i] && s[i] <= 'z') {
            p_string[p_size] = s[i];
            p_size++;
        }
    }
    
    if (!p_size || p_size == 1) return 1;
    int mid = p_size / 2;

    for (int i = 0; i < mid; i++) {
        if (p_string[i] != p_string[p_size - 1 - i]) return 0;
    }
    return 1;
}

int main()
{
    printf("%d", isPalindrome("A man, a plan, a canal: Panama"));
}