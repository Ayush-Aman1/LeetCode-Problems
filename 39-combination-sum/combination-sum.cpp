class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void dfs(int i, int t, vector<int>& c) {
        if (t == 0) {
            ans.push_back(cur);
            return;
        }
        if (i == c.size() || t < 0) return;
        cur.push_back(c[i]);
        dfs(i, t - c[i], c);
        cur.pop_back();
        dfs(i + 1, t, c);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        dfs(0, target, c);
        return ans;
    }
};