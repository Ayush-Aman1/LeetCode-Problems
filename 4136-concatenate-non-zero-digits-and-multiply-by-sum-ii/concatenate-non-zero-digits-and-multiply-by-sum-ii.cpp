class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long mod = 1e9 + 7;
        int n = s.size();
        vector<int> sum(n + 1), cnt(n + 1);
        vector<long long> val(n + 1), pow(n + 1, 1);
        for (int i = 0; i < n; i++) {
            pow[i + 1] = pow[i] * 10 % mod;
        }
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i];
            cnt[i + 1] = cnt[i];
            val[i + 1] = val[i];
            if (s[i] != '0') {
                int d = s[i] - '0';
                sum[i + 1] += d;
                cnt[i + 1]++;
                val[i + 1] = (val[i] * 10 + d) % mod;
            }
        }
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            int sm = sum[r + 1] - sum[l];
            int c = cnt[r + 1] - cnt[l];
            long long x = (val[r + 1] - val[l] * pow[c]) % mod;
            if (x < 0) x += mod;
            ans.push_back(x * sm % mod);
        }
        return ans;
    }
};