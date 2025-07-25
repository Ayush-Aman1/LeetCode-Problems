class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0, a = 0, b = nums.size()-1;
        while(i<=b){
            if(nums[i]==0){
                swap(nums[i], nums[a]);
                i++; a++;
            }
            else if(nums[i]==1){
                i++;
            }
            else{
                swap(nums[i], nums[b]);
                b--;
            }

        }
        
    }
};