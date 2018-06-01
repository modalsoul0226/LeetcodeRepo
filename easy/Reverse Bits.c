uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++)
    {
        int factor = pow(2.0, (double)i); 
        res += factor * ((n >> (32 - i - 1)) & 1);
    }
    
    return res;
}