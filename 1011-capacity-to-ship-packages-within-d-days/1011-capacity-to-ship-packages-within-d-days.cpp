class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int max = accumulate(weights.begin(), weights.end(),0);
        int min = *max_element(weights.begin(), weights.end());
        int count = 0;
        int ans = -1;
        int size = weights.size();
        int mid;
        

        while (min <= max) {
            mid = min + (max - min) / 2;
            count = 0;
            int l = 0;
            for (int i = 0; i < size; i++) {
                if ( (l + weights[i]) < mid) {
                   l = l + weights[i];
                   if(i == (size-1)){
                            count++;
                        }
                }
                else if(l + weights[i] == mid){
                    count++;
                    l=0;
                }
                else{
                        count++;
                        if(i == (size-1)){
                            count++;
                        }
                        else{
                        l = weights[i];
                        }
                }
            }
            cout<<" "<<count<<"x"<<mid<<" ";
            if (count <= days) {
                ans = mid;
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }
        return ans;
    }
};