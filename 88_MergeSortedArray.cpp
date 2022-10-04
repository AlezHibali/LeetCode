// recursion
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        
        if (m > 0 && nums1[m-1] > nums2[n-1]){
            nums1[m+n-1] = nums1[m-1];
            merge(nums1, m-1, nums2, n);
        }
        else{
            nums1[m+n-1] = nums2[n-1];
            merge(nums1, m, nums2, n-1);
        }
    }
};
