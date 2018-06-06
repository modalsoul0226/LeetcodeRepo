int numDecodings(char* s) {
    int len = strlen(s);
    if (!len) return 0;
    
    int dp[len]; memset(dp, 0, sizeof(dp));
    dp[0] = s[0] == '0' ? 0 : 1;
    if (len == 1) return dp[0];
    
    int sum = (s[0] - '0') * 10 + s[1] - '0';
    if (s[0] == '0') dp[1] = 0;
    else if (s[1] == '0') {
        if (sum <= 26) dp[1] = 1;
        else dp[1] = 0;    
    } else {
        if (sum <= 26) dp[1] = 2;
        else dp[1] = 1;
    }
    
    for (int i = 2; i < len; i++) {
        if (s[i] == '0') {
            if (s[i - 1] == '1' || s[i - 1] == '2') dp[i] = dp[i - 2];
            else dp[i] = 0;
        } else if (s[i - 1] == '0') dp[i] = dp[i - 1];
        else {
            int sum = (s[i - 1] - '0') * 10 + s[i] - '0';
            dp[i] = sum <= 26 ? dp[i - 1] + dp[i - 2] : dp[i - 1];
        }
    }
    
    return dp[len - 1];
}