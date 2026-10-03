class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); i++){
            int j = target - nums[i];
            if(mp.find(j) != mp.end() && mp[j]!=i){
                return {i, mp[j]};
            }
        }
        return {-1, -1};
    }
};