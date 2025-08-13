class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxCount = 0, left = 0;
        unordered_set<char> window;
        for(int right=0; right<s.size(); right++){
            char c = s[right];

            while(window.count(c)){
                window.erase(s[left]);
                left++;
            }
            window.insert(c);
            maxCount = max(maxCount, right-left+1);
        }
        return maxCount;
    }
};