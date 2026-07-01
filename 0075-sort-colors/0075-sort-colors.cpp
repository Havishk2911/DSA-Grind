class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i, j;
        for (i = 0; i < n - 1; i++){
            for (j = 0; j < n - 1 - i; j++){
                if (nums[j] > nums[j + 1]){
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        } 
    }
};