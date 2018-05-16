int hammingWeight(uint32_t n) {
//     int count = 0;
//     while (n) {
//         if (n == 1) { count++; break; }
        
//         int temp = 1;
//         int pow_count = 0;
//         while (temp * 2 <= n) {
//             temp *= 2;
//             pow_count++;
//         }
        
//         n -= pow(2.0, (double)pow_count);
//         count++;
//     }
    
//     return count;
    int count = 0;
    while (n) {
        if (n & 1) count++;
        
        n >>= 1;
    }
    
    return count;
}