class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();

       for(int layer=0; layer<min(row/2,col/2); layer++){
            int x1 = layer; int y1 = layer;
            int x2 = layer; int y2 = col-layer-1;
            int x3 = row-layer-1; int y3 = col-layer-1;
            int x4 = row-layer-1; int y4 = layer;

            int len = (y2-y1+1);
            int bred = (x4-x1+1);

            int mod = 2*(len+bred-2);
             int rot = k%mod;

            while(rot--){
                int temp = grid[x1][y1];

                for(int j=y1+1; j<=y2; j++){
                    grid[x1][j-1] = grid[x1][j];
                }
                grid[x2][y2] = grid[x2+1][y2];

                for(int i=x2+2; i<=x3; i++){
                    grid[i-1][y2] = grid[i][y2];
                }
                grid[x3][y3] = grid[x3][y3-1];

                for(int j=y3-2; j>=y4; j--){
                    grid[x3][j+1] = grid[x3][j];
                }
                grid[x4][y4] = grid[x4-1][y4];

                for(int i=x4-2; i>x1; i--){
                    grid[i+1][y4] = grid[i][y4];
                }
                grid[x1+1][y1] = temp;
            }
       }

        return grid;
    }
};