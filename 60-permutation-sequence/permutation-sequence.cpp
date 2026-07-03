class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> f(n + 1, 1), v;
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] * i;
            v.push_back(i);
        }
        k--;
        string ans;
        for (int i = n; i >= 1; i--) {
            int x = k / f[i - 1];
            ans += char(v[x] + '0');
            v.erase(v.begin() + x);
            k %= f[i - 1];
        }
        return ans;
    }
};