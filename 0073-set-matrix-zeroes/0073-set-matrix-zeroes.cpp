class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows, cols;
        int r = matrix.size(), c = matrix[0].size();
        for(int i = 0; i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(rows.count(i) || cols.count(j)){
                    matrix[i][j]=0;
                }
            }
        }
    }
};