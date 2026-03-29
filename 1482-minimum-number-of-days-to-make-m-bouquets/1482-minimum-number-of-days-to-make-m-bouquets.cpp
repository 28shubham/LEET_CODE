class Solution {

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int max = *max_element(bloomDay.begin(), bloomDay.end());
        int min = *min_element(bloomDay.begin(),bloomDay.end());
        int count =0;
        int ans = -1;
        int size = bloomDay.size();
        int mid;
       
        while(min <= max){
             mid = min +(max - min)/2;
             count = 0 ;
              int l = k;
             for(int i = 0 ; i < size; i++){
                if(bloomDay[i]<=mid){
                    l--;
                   
                    if(l==0){
                        count++;
                        l=k;
                    }
                }
                else{
                    l = k;
                }
                
             }
              
              if(count >= m){
                  ans = mid;
                  max = mid-1;
              }
              else {
                min = mid+1;
              }
        }
        return ans;
    }
};
