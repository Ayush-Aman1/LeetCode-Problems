class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int highestf = 0;
        int maxl = 0;
        int l = 0, r = 0;
        while(r<s.length()){
            freq[s[r]]++;
            highestf = max(highestf, freq[s[r]]);
            int chars = (r-l+1) - highestf;
            if(chars>k){
                freq[s[l]]--;
                l++;
            }
            maxl = r-l+1;
            r++;
        }
        return maxl;
    }
};