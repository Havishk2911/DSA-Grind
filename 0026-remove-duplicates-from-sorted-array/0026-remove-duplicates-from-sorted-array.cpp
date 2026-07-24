class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        stack<int> st;

        for (int num : nums) {
            if (st.empty() || st.top() != num) {
                st.push(num);
            }
        }
        int k = st.size();

        for (int i = k-1; i >= 0; i--){
            nums[i]=st.top();
            st.pop();
        }
        return k;
    }
};