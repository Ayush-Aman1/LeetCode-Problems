class Solution {
public:
    void solveSudoku(vector<vector<char>>& b) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[3][3][9] = {false};
        bool ok = false;
        vector<pair<int, int>> emp;
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (b[r][c] == '.') {
                    emp.push_back({r, c});
                } else {
                    int d = b[r][c] - '1';
                    row[r][d] = true;
                    col[c][d] = true;
                    box[r / 3][c / 3][d] = true;
                }
            }
        }
        function<void(int)> dfs = [&](int i) {
            if (i == emp.size()) {
                ok = true;
                return;
            }
            int r = emp[i].first;
            int c = emp[i].second;
            int br = r / 3;
            int bc = c / 3;
            for (int d = 0; d < 9; d++) {
                if (!row[r][d] && !col[c][d] && !box[br][bc][d]) {
                    row[r][d] = true;
                    col[c][d] = true;
                    box[br][bc][d] = true;
                    b[r][c] = d + '1';
                    dfs(i + 1);
                    if (ok) return;
                    row[r][d] = false;
                    col[c][d] = false;
                    box[br][bc][d] = false;
                }
            }
        };
        dfs(0);
    }
};