class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int max = *max_element(nums.begin(), nums.end());
         int min = 1; //*min_element(piles.begin(), piles.end());
         int mid;
         int size = nums.size();
       
         double count = 0;
         int ans=0;
        
         while(min <= max){
            mid = min + (max- min)/2;
            count = 0 ;
            for(int i=0 ; i <size;i++){
               count = ceil((double)nums[i]/mid)+count ; 
            }
           
            if (count <= threshold){
                
                ans = mid;
               
                max = mid -1;
            }
            else {
                min = mid + 1;
            }
         }
         return ans;
    }
};