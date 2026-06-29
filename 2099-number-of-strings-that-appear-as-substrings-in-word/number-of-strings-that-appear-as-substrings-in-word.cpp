class Solution {
public:
    int numOfStrings(vector<string>& p, string w) {
        int ans = 0;
        for (string &s : p) {
            if (w.find(s) != string::npos) ans++;
        }
        return ans;
    }
};