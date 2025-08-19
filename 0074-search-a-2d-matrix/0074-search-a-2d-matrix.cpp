class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int top = 0, bottom = rows-1, row = 0, col = 0;
        while(top<=bottom){
            row = (top+bottom)/2;
            if(matrix[row][0]>target){
                bottom = row-1;
            }
            else if(matrix[row][cols-1]<target){
                top = row+1;
            }
            else{
                break;
            }
        }
        if(top>bottom) return false;

        int low = 0, high = cols-1;
        while(low<=high){
            col = (low+high)/2;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col]<target){
                low = col+1;
            }
            else{
                high = col-1;
            }
        }
        return false;
    }
};