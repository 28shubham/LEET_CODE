class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
         int minPile = 0; //*min_element(piles.begin(), piles.end());
         int mid;
         int size = piles.size();
       
         int count = 0 ;
         int ans=0;
         if(size==1){
            int l = piles[0]/h;
            if(piles[0]%h == 0){
                return l;
            }
            else{
                return l+1;
            }
         }
         while(minPile <= maxPile){
            mid = minPile + (maxPile- minPile)/2;
            count = 0 ;
            for(int i=0 ; i <size;i++){
                if( piles[i]>mid ){
                     if(mid < 1){
                    return ans;
                }
                    int k = piles[i]/mid;
                    count = count + k;
                    if(piles[i]%mid == 0){
                        count--;
                    }
                } 
            }
            count = count + size;
            cout<<count<<" ";
            cout<<" "<<mid<<" ";
            if (count <= h){
                
                ans = mid;
                if(mid < 1){
                    return ans;
                }
                maxPile = mid -1;
            }
            else {
                minPile = mid + 1;
            }
         }
         return ans;
    }
};