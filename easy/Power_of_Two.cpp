#include <iostream>
#include <string>

using namespace std;

// O(logn) solution
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         int curr = 1;
//         do {
//             if (curr == n) return true;
//             curr *= 2;
//         } while (curr <= n);
        
//         return false;
//     }
// };

// O(1) solution
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }
};

int main() {
    Solution sol;
    if (sol.isPowerOfTwo(1023)) 
        cout << "true" << endl;
    else
        cout << "false" << endl;

    string s = "abc";
    s = "->" + s;
    cout << s << endl;
}