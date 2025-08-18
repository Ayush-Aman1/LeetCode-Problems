class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();
        
        if (k > n) return false; 
        unordered_map<char, int> count1;
        for (char c : s1) {
            count1[c]++;
        }

        unordered_map<char, int> count2;
        for (int i = 0; i < k; i++) {
            count2[s2[i]]++;
        }
        
        if (count1 == count2) return true;
        
        for (int i = k; i < n; i++) {
            count2[s2[i]]++;
            char oldChar = s2[i - k];
            count2[oldChar]--;
            if (count2[oldChar] == 0) {
                count2.erase(oldChar);
            }
            if (count1 == count2) return true;
        }
        
        return false;
    }
};