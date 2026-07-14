class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& b) {
        int m = b.size(), n = b[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || b[i][j] != 'O')
            return;
        b[i][j] = '#';
        dfs(i + 1, j, b);
        dfs(i - 1, j, b);
        dfs(i, j + 1, b);
        dfs(i, j - 1, b);
    }
    void solve(vector<vector<char>>& b) {
        int m = b.size(), n = b[0].size();
        for (int i = 0; i < m; i++) {
            dfs(i, 0, b);
            dfs(i, n - 1, b);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, b);
            dfs(m - 1, j, b);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] == 'O') b[i][j] = 'X';
                else if (b[i][j] == '#') b[i][j] = 'O';
            }
        }
    }
};