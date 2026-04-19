class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int x = nums[i];
            if(mp.count(target - x)){
                return {i, mp[target - x]};
            }
            mp[x] = i;
        }
        return {-1, -1};
    }
};