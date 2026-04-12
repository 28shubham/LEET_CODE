class Solution {
public:
    
    int countBits(int x) {
        return __builtin_popcount(x);
    }
    
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;
        
        while (i < n) {
            int j = i;
            
            // find group with same set bits
            while (j < n && countBits(nums[j]) == countBits(nums[i])) {
                j++;
            }
            
            // sort this group
            sort(nums.begin() + i, nums.begin() + j);
            
            i = j;
        }
        
        // check if whole array is sorted
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        
        return true;
    }
};