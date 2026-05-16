class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) {
            swap(nums1, nums2);
            swap(n1, n2);
        }
        int half = (n1 + n2) / 2;
        int left = 0, right = n1;
        while (1) {
            int cut1 = (left + right) / 2;
            int cut2 = half - cut1;       

            double l1 = (cut1 == 0)  ? (double)INT_MIN : nums1[cut1 - 1];
            double r1 = (cut1 == n1) ? (double)INT_MAX : nums1[cut1];
            double l2 = (cut2 == 0)  ? (double)INT_MIN : nums2[cut2 - 1];
            double r2 = (cut2 == n2) ? (double)INT_MAX : nums2[cut2];

            if (l1 > r2) {
                right = cut1 - 1;
            } else if (l2 > r1) {
                left = cut1 + 1;
            } else {
                if ((n1 + n2) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return min(r1, r2);
                }
            }
        }
    }
};