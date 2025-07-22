class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcount = 0, count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                count++;
            }
            if(maxcount<count){
                maxcount = count;
            }
            if ((i + 1) < nums.size() && nums[i + 1] == 0){
                count = 0;
            }
        }
        return maxcount;
    }
};