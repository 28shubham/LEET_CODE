class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int size = nums.size();
        if(size<k){
            return -1;
        }
        int high = accumulate(nums.begin(),nums.end(),0);
        int low = *max_element(nums.begin(),nums.end());
        int ans=-1;
         int mid;
         while(low<=high){
            mid = low + (high - low)/2;
            int sum = 0;
            int count = 0;
            for(int i = 0 ; i<size ; i++){
             sum = sum + nums[i];
             if(sum > mid){
                sum = nums[i];
                count++;
             }
            }
            count = count+1;
            if(count <=k){
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
         }
         return ans;
        
    }
};