#include <bits/stdc++.h>
using namespace std;

static const auto io_speed_up = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    deque<long long> exps;
    
    void init(string s) {
        exps = deque<long long>();
        
        long long num = 0;
        for (auto& ch: s) {
            if ('0' <= ch && ch <= '9') {
                num = num * 10 + ch - '0';
                // printf("num: %lld\n", num);
            } else if (ch != ' ') {
                exps.push_back(num); exps.push_back(ch);
                num = 0;
            }
        }

        exps.push_back(num);
    }
    

    int calculate(string s) {
        init(s);

        // int i = 1;
        // for (auto& it: exps)
        //     if (i++ % 2)
        //         printf("%lld ", it);
        //     else
        //         printf("%c ", (char)it);
        // printf("\n");

        long long res = 0, symb = 1;
        while (!exps.empty()) {
            if (exps.size() == 1)
                return res += symb * exps.front();
            
            long long num = exps.front(); exps.pop_front();
            char exp = exps.front(); exps.pop_front();
            
            if (exp == '+') res += symb * num, symb = 1;
            else if (exp == '-') res += symb * num, symb = -1;
            else if (exp == '*') {
                long long num1 = exps.front(); exps.pop_front();
                exps.push_front(num1 * num);
            } else if (exp == '/') {
                long long num1 = exps.front(); exps.pop_front();
                exps.push_front(num / num1);
            }
        }

        return res;
    }
};

// int main() {
//     auto sol = Solution();
//     printf("res: %d\n", sol.calculate("100000000/1/2/3/4/5/6/7/8/9/10"));
// }