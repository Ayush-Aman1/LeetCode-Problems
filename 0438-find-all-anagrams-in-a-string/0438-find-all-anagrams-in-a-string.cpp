class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int n = s.size(), m = p.size();
        if (n < m) return result;
        vector<int> pCount(26, 0), sCount(26, 0);
        for (char c : p) pCount[c - 'a']++;
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (pCount[i] == sCount[i]) matches++;
        }
        for (int i = 0; i < n; i++) {
            int in = s[i] - 'a';
            sCount[in]++;
            if (sCount[in] == pCount[in]) matches++;
            else if (sCount[in] == pCount[in] + 1) matches--;
            if (i >= m) {
                int out = s[i - m] - 'a';
                sCount[out]--;
                if (sCount[out] == pCount[out]) matches++;
                else if (sCount[out] == pCount[out] - 1) matches--;
            }
            if (i >= m - 1 && matches == 26) {
                result.push_back(i - m + 1);
            }
        }
        
        return result;
    }
};