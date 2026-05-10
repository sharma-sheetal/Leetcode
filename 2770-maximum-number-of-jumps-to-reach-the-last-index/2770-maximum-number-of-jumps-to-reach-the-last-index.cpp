class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(n, 0);

        for(int i=0; i<n; i++){
            int curr = nums[i];
            
            if(i!=0 and ans[i] == 0)
            continue;

            for(int j=i+1; j<n; j++){
                int diff = nums[j] - nums[i];

                if(diff>=-target and diff<=target){
                    ans[j] = max(ans[j], ans[i]+1);
                }
            }
        }

        return ans[n-1]==0?-1:ans[n-1];
    }
};