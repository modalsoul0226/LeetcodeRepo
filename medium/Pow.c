#include <stdio.h>

double myPow(double x, int n) 
{
    double sum = 1;
    
    printf("aaaaaaaaa\n");
    if (x == 1) return (double)1;
    printf("aaaaaaaaa\n");
    if (n < 0) {
        n = 0 - n;
        x = 1.0 / x;
    }
    printf("n:%.5f\n", n);
    for (int i = 0; i < n; i++) {
        sum *= x;
        
        printf("Sum: %.5f\n", sum);
        if ((0 < sum && sum < 0.00001) ||
             -0.00001 < sum && sum < 0) return (double)0;
    }
    
    return sum;
}

int main()
{
    printf("res: %.5f\n", myPow(2.00000, -2147483648));
}