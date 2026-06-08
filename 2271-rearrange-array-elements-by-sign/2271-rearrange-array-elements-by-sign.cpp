class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int x = nums.size();
        vector<int> arr(x);

        int a=0, b=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                arr[b]=nums[i];
                b+=2;
            }
            else{
                arr[a]=nums[i];
                a+=2;
            }
        }
        return arr;
    }
};