class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9], cols[9], boxes[9];
        for(int i = 0; i<9; i++){
            for(int j=0; j<9; j++){
                char val = board[i][j];
                if(val == '.'){
                    continue;
                }
                if(rows[i].count(val) || cols[j].count(val) || boxes[(i/3)*3 + (j/3)].count(val)){
                    return false;
                }
                else{
                    rows[i].insert(val);
                    cols[j].insert(val);
                    boxes[(i/3)*3+(j/3)].insert(val);
                }
            }
        }
        return true;
    }
};