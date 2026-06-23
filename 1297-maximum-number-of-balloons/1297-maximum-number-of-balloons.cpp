class Solution {
public:
    int maxNumberOfBalloons(string s) {
        vector<int> f(26);
        for (char c : s) f[c - 'a']++;
        return min({
            f['b' - 'a'],
            f['a' - 'a'],
            f['l' - 'a'] / 2,
            f['o' - 'a'] / 2,
            f['n' - 'a']
        });
    }
};