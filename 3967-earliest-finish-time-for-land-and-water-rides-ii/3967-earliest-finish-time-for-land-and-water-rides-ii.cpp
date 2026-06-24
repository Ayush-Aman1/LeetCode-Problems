class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld,
                           vector<int>& ws, vector<int>& wd) {
        return min(calc(ls, ld, ws, wd),
                   calc(ws, wd, ls, ld));
    }
    int calc(vector<int>& s1, vector<int>& d1,
             vector<int>& s2, vector<int>& d2) {
        int mn = INT_MAX;
        for (int i = 0; i < s1.size(); i++) {
            mn = min(mn, s1[i] + d1[i]);
        }
        int ans = INT_MAX;
        for (int i = 0; i < s2.size(); i++) {
            ans = min(ans, max(mn, s2[i]) + d2[i]);
        }
        return ans;
    }
};