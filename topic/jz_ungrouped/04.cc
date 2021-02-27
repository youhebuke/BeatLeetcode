class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        if(matrix[0].empty()) return false;
        auto n = matrix.size();
        auto m = matrix[0].size();
        int row = 0;
        int col = m - 1;
        bool turning_left = false;
        while(true){
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] > target){
                col = col - 1;
                if(col < 0){
                    return false;
                }
            }
            if(matrix[row][col] < target){
                row = row + 1;
                if(row > n - 1){
                    return false;
                }
            }
        }
    }
};