class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0, count = 0;
        int total = n + m;
        int medianPos1 = (total - 1) / 2; 
        int medianPos2 = total / 2;    

        int curr = -1, prev = -1;

        while (count <= medianPos2) {
            prev = curr;
            if (i < n && (j >= m || nums1[i] <= nums2[j])) {
                curr = nums1[i++];
            } else {
                curr = nums2[j++];
            }
            count++;
        }
        if (total % 2 == 0)
            return (prev + curr) / 2.0;
        else
            return curr;
    }
};
