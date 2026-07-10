class Solution {
public:
    bool isNumber(string s) {
        bool num = false, dot = false, e = false;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = true;
            }
            else if (c == '.') {
                if (dot || e) return false;
                dot = true;
            }
            else if (c == 'e' || c == 'E') {
                if (e || !num) return false;
                e = true;
                num = false;
            }
            else if (c == '+' || c == '-') {
                if (i && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else {
                return false;
            }
        }
        return num;
    }
};