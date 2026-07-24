class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        stack<int> st;
        int i=0, j=0;

        while (i<m && j<n) {
            if (nums1[i] <= nums2[j]) {
                st.push(nums1[i++]);
            }
            else {
                st.push(nums2[j++]);
            }
        }
        while (i<m) st.push(nums1[i++]);
        while (j<n) st.push(nums2[j++]);

        int idx = m+n-1;
        while (!st.empty()) {
            nums1[idx--] = st.top();
            st.pop();
        }
    }
};