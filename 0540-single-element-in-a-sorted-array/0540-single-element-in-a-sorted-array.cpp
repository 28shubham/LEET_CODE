// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int high = nums.size()-1;
//         int low = 0;
//         int mid;

//         while(low<=high){
//             mid = low + (high - low)/2;
//             if(mid == low && mid == high){
//                 return nums[mid];
//             }
//             else if(mid == low){
//               if(nums[mid]!=nums[mid+1])
//                return nums[mid]; 
//             }
//             else if(mid == high){
//                    if(nums[mid]!= nums[mid-1] )
//                    return nums[mid];
//             }
//             else if(mid%2 == 1){
//                 if(nums[mid]==nums[mid-1]){
//                     low= mid+1;
//                 }
//                 else if(nums[mid]==nums[mid+1]){
//                      high = mid-1;
//                 }
//                 else{
//                     return nums[mid];
//                 }
//             }
//             else{
//                 if(nums[mid]==nums[mid-1]){
                   
//                     high = mid;
//                 }
//                 else if(nums[mid]==nums[mid+1]){
//                       low= mid;
//                 }
//                 else{
//                     return nums[mid];
//                 }

//             }
//         }
//         return nums[mid];
//     }
// };
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Ensure mid is even
            if (mid % 2 == 1) mid--;

            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } else {
                high = mid;
            }
        }

        return nums[low];
    }
};