class Solution {
public:
    bool isUgly(int num) {
//         priority_queue<int, vector<int>, greater<int> > ugly_pq;
//         ugly_pq.push(1);
        
//         int coeff[] = {2, 3, 5};
        
//         int ugly;
//         while ((ugly = ugly_pq.top()) < num) {
//             ugly_pq.pop();
            
//             for (auto i: coeff) ugly_pq.push(i * ugly);
//         }
        
//         if (ugly == num) return true;
//         else return false;
        if (num == 1) return true;
        else if (num == 0) return false;
        
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        
        return num == 1;
    }
};