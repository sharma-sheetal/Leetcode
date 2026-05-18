class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> mp;

        for(int i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }

        vector<int> visited(n, 0);
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0] = 1;

        while(!q.empty()){

            auto [idx, step] = q.front();
            q.pop();

            if(idx==n-1)
            return step;

            if(idx+1<n and visited[idx+1]==0){
                q.push({idx+1, step+1});
                visited[idx+1] = 1;
            }

            if(idx-1>=0 and visited[idx-1]==0){
                q.push({idx-1, step+1});
                visited[idx-1] = 1;
            }

            for(auto nbr:mp[arr[idx]]){
                if(nbr == idx)
                continue;

                if(visited[nbr] == 0){
                    q.push({nbr, step+1});
                    visited[nbr] =1;
                }
            }
            // IMPORTANT
            mp[arr[idx]].clear();

        }

        return -1;
    }
};