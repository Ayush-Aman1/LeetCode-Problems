class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();
        int l = 0, r = k-1;
        unordered_map<char, int> count1;
        for (char c : s1) {
            count1[c]++;
        }
        unordered_map<char, int> count2;
        while(r<n){
            unordered_map<char, int> count2;
            string subs;
            subs = s2.substr(l, k);
            for(char c:subs){
                count2[c]++;
            }
            if(count1 == count2){
                return true;
            }
            else{
                l++;
                r++;
            }
        }
        return false;
    }
};