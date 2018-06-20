#include <iostream>
#include <set>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n = 10, count = 0;

    vector<bool> prime(n, true);
    // int loop = n % 2 ? n / 2 : n / 2 - 1;
    
    for (int i = 2; i < n; i++) {
        int sum = i;
        
        if (!prime[i]) continue;

        count++;
        if (i > sqrt(n)) continue;
        
        for (sum = sum * sum; sum < n; sum += i) 
            prime[sum] = false;
        
    }
    
    // cout << n - 1 - non_prime.size() - 1 << endl;
    cout << count << endl;

    return 0;
}