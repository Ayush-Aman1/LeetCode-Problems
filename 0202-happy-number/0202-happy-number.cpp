class Solution {
public:
    int get_next_num(int n){
        int next_num = 0;
        while(n>0){
            int digit = n%10;
            n /= 10;
            next_num += digit * digit;
        }
        return next_num;
    }
    bool isHappy(int n) {
        int fast = n, slow = n;
        while(true){
            slow = get_next_num(slow);
            fast = get_next_num(get_next_num(fast));
            if(fast == 1){
                return true;
            }
            else if(slow == fast){
                return false;
            }
        }
    }
};