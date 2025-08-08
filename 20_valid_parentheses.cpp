class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; s[i]!='\0'; i++){
            switch(s[i]){
                case '(': st.push(s[i]); break;
                case '{': st.push(s[i]); break;
                case '[': st.push(s[i]); break;
                case ')': if(!st.empty() && st.top()=='(') st.pop(); else{ return false;
                } break;
                case '}': if(!st.empty() && st.top()=='{') st.pop(); else{ return false;
                }  break;
                case ']': if(!st.empty() && st.top()=='[') st.pop(); else{ return false;
                }  break;
                default: break;
            }
        }
        return st.empty();
    }
};