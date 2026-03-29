class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
         int minPile = 1; //*min_element(piles.begin(), piles.end());
         int mid;
         int size = piles.size();
       
         long long count = 0;
         int ans=0;
        
         while(minPile <= maxPile){
            mid = minPile + (maxPile- minPile)/2;
            count = 0 ;
            for(int i=0 ; i <size;i++){
               count = ceil((double)piles[i]/mid)+count ; 
            }
           
            if (count <= h){
                
                ans = mid;
               
                maxPile = mid -1;
            }
            else {
                minPile = mid + 1;
            }
         }
         return ans;
    }
};