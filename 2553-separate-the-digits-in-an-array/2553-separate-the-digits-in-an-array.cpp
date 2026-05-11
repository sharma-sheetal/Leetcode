class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();

        vector<int> ans;

        for(auto num : nums){
            vector<int> temp;
            while(num){
                int digit = num%10;
                num /= 10;
                temp.push_back(digit);
            }
            reverse(temp.begin(), temp.end());
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};