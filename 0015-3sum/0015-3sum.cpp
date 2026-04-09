class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> p;
        sort(nums.begin(), nums.end());
        int l, r, a;
        for(int i=0; i<nums.size()-2; i++){
            a = nums[i];
            l = i+1;
            r = nums.size()-1;
            if( i>0 && nums[i]==nums[i-1]){
                continue;
            }
            while(l<r){
                int _3sum = nums[l] + nums[r];
                if(_3sum == -a){
                    p.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r && l-1 != i && nums[l]==nums[l-1]){
                        l++;
                    }
                    while(r+1 < nums.size() && r>l && nums[r]==nums[r+1]){
                        r--;
                    }
                }
                else if(_3sum < -a){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return p;
    }
};