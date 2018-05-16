#include <stdio.h>
#include <string.h>
#include <math.h>

/*
 * i must be less then strlen(s).
 */
int find_end(char* s, int i) {
    int depth = 1;
    while (s[i] != '\0') {
        if (s[i] == '(') depth++;
        else if (s[i] == ')') depth--;
        
        if (!depth) return i;
        i++;
    }
    
    return 0;
}

/*
 * end >= start
 */
int calc_sum(int start, int end, char *s) {
    int sign = 1, j = 0, sum = 0;
    int d_list[strlen(s)];
    
    for (int i = start; i <= end; i++) {
        if (s[i] == '(') {
            int end_idx = find_end(s, i + 1);
            if (end_idx == i + 1) { i++; continue; }
            
            int partial_sum = calc_sum(i + 1, end_idx - 1, s);
            printf("start: %d end: %d\n", i + 1, end_idx - 1);
            printf("partial sum: %d\n", partial_sum);
            printf("\n");
            sum += sign * partial_sum;
            i = end_idx;
        
        } else if (s[i] == ')' || s[i] == '+' || s[i] == '-') {
            int temp_sum = 0;
            for (int k = 0; k < j; k++) {
                temp_sum += d_list[k] * pow(10.0, (double)(j - k - 1));
            }
            
            sum += sign * temp_sum;
            if (s[i] == '+') sign = 1;
            else if (s[i] == '-') sign = -1;
            j = 0;
        
        } else if ('0' <= s[i] && s[i] <= '9') {
            d_list[j] = s[i] - '0';
            j++;
        } 
    }
    
    int temp_sum = 0;
    for (int k = 0; k < j; k++) {
        temp_sum += d_list[k] * pow(10.0, (double)(j - k - 1));
    }

    sum += sign * temp_sum;
    // printf("intermediate sum: %d\n", sum);
    return sum;
}

int calculate(char *s) {
    return calc_sum(0, strlen(s) - 1, s);
}


int main(int argc, char const *argv[])
{
    // printf("result: %d\n", calculate("(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))+(1+(1+(4+5+2)-3)+(6+8)-(6+2)-(2-6)+2+(2+2)-((8))-(-2))"));
    printf("result: %d\n", calculate("-(-1 + 1)+1"));
    return 0;
}
