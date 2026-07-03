class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int i, j;
        for (i=0; i<=n; i++){
            bool found = false;

            for (j=0; j<n; j++){
                if (nums[j] == i){
                found = true;
                break;
            }
        }

        if(!found){
            return i;
        }
    }
    return -1;
    }
};