class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddCount = 0;
        for (int x : nums1) {
            if (x % 2 != 0) oddCount++;
        }
        
        bool evenTargetOk = (oddCount == 0) || (oddCount >= 2);
        
        bool oddTargetOk = (oddCount >= 1);
        
        return evenTargetOk || oddTargetOk;
    }
};