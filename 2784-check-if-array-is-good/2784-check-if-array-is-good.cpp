class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        for(int i=1; i<n; i++){
            arr.push_back(i);
        }
        arr.push_back(n-1);
        sort(nums.begin(), nums.end());
        return arr==nums;
    }
};