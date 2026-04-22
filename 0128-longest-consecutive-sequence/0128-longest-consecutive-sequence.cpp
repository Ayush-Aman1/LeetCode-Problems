class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxl = 0, cur = 0, len = 0;
        unordered_set<int> m(nums.begin(), nums.end());
        for(int num:m){
            if(!m.count(num - 1)){
                cur = num;
                len = 1;
                while(m.count(cur+1)){
                    cur++;
                    len++;
                }
            }
            maxl = max(maxl, len);
        }
        return maxl; 
    }
};