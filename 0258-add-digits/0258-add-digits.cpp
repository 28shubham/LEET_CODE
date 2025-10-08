class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
        int sum = 0; 
        sum = num;
        while(sum>=10){
          ans = sum ;
          sum = 0;
          while(ans!=0){
            int x = ans%10;
            sum = x+sum;
            ans = ans/10;
          }
        }
        return sum;
    }
};