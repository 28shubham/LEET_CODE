class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int high = nums.size()-1;
      int low = 0;
      int mid;
      while (low<=high){
       mid  = low+(high - low)/2;
       if(target == nums[mid]){
        return true;
       }
        // Edge case: all three are equal, we cannot determine which side is sorted
       else if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }
       else if(nums[low]<=nums[mid]){
        if(nums[low]<=target && target <nums[mid]){
            high = mid -1;
        }
        else {
            low = mid+1;
        }
       } else{
        if(nums[mid]<target && target <=nums[high]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
       }
       
      }
      return false;
    }
};