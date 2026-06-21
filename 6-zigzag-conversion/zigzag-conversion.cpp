class Solution {
public:
    string convert(string s, int rows) {
        if (rows == 1 || rows >= s.size()) return s;

        vector<string> v(rows);
        int r = 0, d = 1;

        for (char c : s) {
            v[r] += c;

            if (r == 0) d = 1;
            else if (r == rows - 1) d = -1;

            r += d;
        }

        string ans;

        for (string &x : v) ans += x;

        return ans;
    }
};