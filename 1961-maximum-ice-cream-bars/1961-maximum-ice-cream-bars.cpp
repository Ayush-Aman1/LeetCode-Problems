class Solution {
public:
    int maxIceCream(vector<int>& c, int coins) {
        sort(c.begin(), c.end());
        int ans = 0;
        for (int x : c) {
            if (coins < x) break;
            coins -= x;
            ans++;
        }
        return ans;
    }
};