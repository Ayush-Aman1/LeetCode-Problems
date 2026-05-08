class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, m = 0, pos0 = -1, pos1 = -1;
        while(l<=r){
            m = l + (r-l)/2;
            if(nums[m]==target){
                pos0 = m;
                r = m-1;
            }
            else if(nums[m]<target){
                l = m+1;
            }
            else r = m-1;
        }
        l = 0, r = nums.size()-1;
        while(l<=r){
            m = l + (r-l)/2;
            if(nums[m]==target){
                pos1 = m;
                l = m+1;
            }
            else if(nums[m]<target){
                l = m+1;
            }
            else r = m-1;
        }
        return {pos0, pos1};
    }
};