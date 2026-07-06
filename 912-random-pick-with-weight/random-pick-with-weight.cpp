class Solution {
public:
    vector<int> p;
    Solution(vector<int>& w) {
        p = w;
        for (int i = 1; i < p.size(); i++) {
            p[i] += p[i - 1];
        }
    }
    int pickIndex() {
        int x = rand() % p.back() + 1;
        int l = 0, r = p.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (p[m] >= x) r = m;
            else l = m + 1;
        }
        return l;
    }
};