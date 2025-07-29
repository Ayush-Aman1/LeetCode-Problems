class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, r = nums.size()-1;
        vector<int>pos={-1,-1};
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]==target){
                pos[0]= m;
                r=m-1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        l=0, r = nums.size()-1;
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]==target){
                pos[1]= m;
                l=m+1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return pos;
    }
};