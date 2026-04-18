class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        for (char &c : s) {
                c = tolower(c);
        }
        while(l<r){
            if(isalnum(s[l])){
                if(isalnum(s[r])){
                    if(s[l] == s[r]){
                        l++;
                        r--;
                    }
                    else break;
                }
                else r--;
            }
            else l++;
        }
        if(l>=r) return true;
        else return false;
    }
};