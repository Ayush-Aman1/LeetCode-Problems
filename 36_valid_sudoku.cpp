class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                char cur = board[row][col];
                if(cur == '.') continue;
                string rowKey = "row" + to_string(row) + cur;
                string colKey = "col" + to_string(col) + cur;
                string boxKey = "box" + to_string(row/3) + to_string(col/3) + cur;
                if(seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)){
                    return false;
                }
                seen.insert(rowKey);
                seen.insert(colKey);
                seen.insert(boxKey);
            }
        }
        return true;
    }
};