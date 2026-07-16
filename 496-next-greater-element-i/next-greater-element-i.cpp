class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nextg;
        vector<int> ans;
        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && st.top() < nums2[i]) {
                nextg[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while (!st.empty()) {
            nextg[st.top()] = -1;
            st.pop();
        }
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(nextg[nums1[i]]);
        }
        return ans;
    }
};