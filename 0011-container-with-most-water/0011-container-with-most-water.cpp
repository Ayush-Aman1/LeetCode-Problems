class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1, max = 0, cur = 0;
        while(l<r){
            cur = min(height[l], height[r])*(r-l);
            if(cur>max) max = cur;
            if(height[l]<=height[r]) l++;
            else r--;
        }
        return max;
    }
};