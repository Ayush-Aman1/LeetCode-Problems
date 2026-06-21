class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), st = 0, len = 1;

        auto chk = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > len) {
                    len = r - l + 1;
                    st = l;
                }
                l--;
                r++;
            }
        };

        for (int i = 0; i < n; i++) {
            chk(i, i);
            chk(i, i + 1);
        }

        return s.substr(st, len);
    }
};