#include <stdio.h>

#define INT_MAX  2147483647
#define INT_MIN -2147483648

int check_overflow(int res, int adder, int sign) {
    if (sign == 1){
        if ((INT_MAX - adder) / 10.0 < res) return 1;
    } else {
        if ((INT_MIN + adder) / 10.0 > res) return -1;
    }
    
    return 0;
}

int myAtoi(char* str) {
    int i = 0, res = 0, sign = 1;
    
    while (str[i] != '\0') {
        if (str[i] != ' ') break;
        i += 1;
    }
    
    printf("str[i]: %d\n", str[i]);
    if (str[i] == '+') { sign = 1; i++; }
    else if (str[i] == '-') { sign = -1; i++; }
    else if (str[i] == '\0' || str[i] < 48 || str[i] > 57) return 0;
    
    while (48 <= str[i] && str[i] <= 57) {
        switch (check_overflow(res, str[i] - 48, sign)) {
            case -1:
                return INT_MIN;
            case 1:
                return INT_MAX;
        }
        
        res = res * 10 + sign * (str[i] - 48);
        printf("intermediate result: %d\n", res);
        i++;
    }
    
    return res;
}