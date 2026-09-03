class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasOdd = false;
        int minOdd = INT_MAX;
        for (int x : nums1) {
            if (x % 2 != 0) {
                hasOdd = true;
                minOdd = min(minOdd, x);
            }
        }
        
        if (!hasOdd) return true;
        
        for (int x : nums1) {
            if (x % 2 == 0) {
                if (!(minOdd < x)) return false;
            }
        }
        return true;
    }
};