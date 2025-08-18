class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();
        string subs;
        string perm = s1;
        sort(perm.begin(), perm.end());
        int l = 0, r = k-1;
        while(r<n){
            subs = s2.substr(l, k);
            sort(subs.begin(), subs.end());
            if(perm != subs){
                l++;
                r++;
            }
            else{
                break;
            }
        }
        return (subs == perm);
    }
};