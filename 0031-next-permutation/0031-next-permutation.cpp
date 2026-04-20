class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int in = -1, n = nums.size()-1;
        for(int i = n-1; i>=0; i--){
            if(nums[i]<nums[i+1]){
                in = i;
                break;
            }
        }
        if(in == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = n; i>in; i--){
            if(nums[in]<nums[i]){
                swap(nums[i], nums[in]);
                break;
            }
        }
        reverse(nums.begin()+in+1, nums.end());
    }
};