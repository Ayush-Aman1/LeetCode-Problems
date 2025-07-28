class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int maxl = 1;
        unordered_set<int>s(nums.begin(), nums.end());
        for(auto num:s){
            if(s.find(num-1)==s.end()){
                int cur = num;
                int len = 1; 
                while(s.find(cur+1)!=s.end()){
                    cur++;
                    len++;
                }
                maxl = max(maxl, len);
            }
        }

        return maxl;
    }
};