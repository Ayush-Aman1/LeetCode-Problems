class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int cur_sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            cur_sum = max(nums[i], cur_sum+nums[i]);
            max_so_far = max(max_so_far, cur_sum);
        }
        return max_so_far;
    }
};