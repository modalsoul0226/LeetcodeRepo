#include <bits/stdc++.h>
using namespace std;

static const auto io_speed_up  = [](){
    std::cout.sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() < 1 || matrix[0].size() < 1)
            return false;
        
        int row = 0, col = matrix[0].size() - 1;
        
        while (row <= matrix.size() - 1 && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                row++;
            else
                col--;
        }
        
        return false;
    }
};