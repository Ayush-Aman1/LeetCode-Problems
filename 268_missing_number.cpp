class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0,s=0;
        for(int i=0;i<n;i++){
            sum += i;
            s += nums[i];
        }
        sum += n;
        int res = sum - s;
        return res;
    }
};