class Solution {
public:

    vector<int> visited;

    bool solve(int i, int n, vector<int> &arr, auto &dp){

        if(i>=n or i<0){
            cout<<"OUB"<<endl;
             return false;
        }       

        if(arr[i] == 0){
            cout<<"REACHED"<<endl;
            return true;
        }

        if(dp[i] == true)
        return dp[i];
        

       
        // Move arr[i] steps to right
        bool right = false;
        if(i+arr[i]<n and visited[i+arr[i]] == 0){
            cout<<"Step "<<i<<" -> ";
            visited[i+arr[i]] = 1;
            right = solve(i+arr[i], n, arr, dp);
            visited[i+arr[i]] = 0;
        }       


        // Move arr[i] steps to left
        bool left=false;
        if(i-arr[i]>=0 and visited[i-arr[i]] == 0){
            cout<<"Step "<<i<<" -> ";
            visited[i-arr[i]] = 1;
            left = solve(i-arr[i], n, arr, dp);
            visited[i-arr[i]] = 0;
        }       

        return dp[i] = right or left;
    }





    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        for(int i=0; i<n; i++)
        visited.push_back(0);

        vector<bool> dp(n, false);
        return solve(start, n, arr, dp);
    }
};