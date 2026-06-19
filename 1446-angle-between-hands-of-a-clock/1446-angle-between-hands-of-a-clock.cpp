class Solution {
public:
    double angleClock(int h, int m) {
        double hr = (h % 12) * 30.0 + m * 0.5;
        double mn = m * 6.0;
        double a = abs(hr - mn);
        return min(a, 360.0 - a);
    }
};