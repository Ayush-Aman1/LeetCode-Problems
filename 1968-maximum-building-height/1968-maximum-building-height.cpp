class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        r.push_back({1, 0});
        sort(r.begin(), r.end());
        int m = r.size();
        for (int i = 1; i < m; i++) {
            r[i][1] = min(r[i][1], r[i - 1][1] + r[i][0] - r[i - 1][0]);
        }
        for (int i = m - 2; i >= 0; i--) {
            r[i][1] = min(r[i][1], r[i + 1][1] + r[i + 1][0] - r[i][0]);
        }
        long long ans = 0;
        for (int i = 1; i < m; i++) {
            long long x1 = r[i - 1][0], h1 = r[i - 1][1];
            long long x2 = r[i][0], h2 = r[i][1];
            ans = max(ans, (h1 + h2 + x2 - x1) / 2);
        }
        ans = max(ans, (long long)r.back()[1] + n - r.back()[0]);
        return (int)ans;
    }
};