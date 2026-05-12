class Solution {
public:

    static bool compare(vector<int> &t1, vector<int> &t2){
        int diff1 = t1[1] - t1[0];
        int diff2 = t2[1] - t2[0];
        return diff1 > diff2;
    }

    bool isPossible(int t, auto &tasks){

        for(int i=0; i<tasks.size(); i++){
            int req = tasks[i][0];
            int mini = tasks[i][1];

            if(t<mini)
            return false;

            t -= req;
        }
        return true;
    }


    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), compare);

        int low = 0, high = 1e9;
        int ans;
        while(low<=high){

            int mid = low + (high-low)/2;

            if(isPossible(mid, tasks)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
};