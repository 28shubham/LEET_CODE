class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> arr;
        while(!nums.empty()){
        int x = *min_element(nums.begin(),nums.end());
        auto it = min_element(nums.begin(), nums.end());
        nums.erase(it);
        int y = *min_element(nums.begin(),nums.end());
        auto gg = min_element(nums.begin(), nums.end());
        nums.erase(gg);
        arr.push_back(y);
        arr.push_back(x);
        }
        return arr;
    }
};