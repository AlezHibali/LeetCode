class Solution {
public:
    int ifValid(vector<vector<int>>& grid, int n, int row, int size, int sizer, bool left){
        if (row == size){
            return n;
        }
        if (grid[row][n] == 1 && n != sizer-1 && grid[row][n+1] == 1){
            return ifValid(grid, n+1, row+1, size, sizer, true);
        }
        else if (grid[row][n] == -1 && n != 0 && grid[row][n-1] == -1){
            return ifValid(grid, n-1, row+1, size, sizer, false);
        }
        else
            return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int size = grid.size();
        int sizer = grid[0].size();
        vector<int> res;
        
        for (int i = 0; i < sizer; i++){
            res.push_back(ifValid(grid,i,0,size,sizer,true));
        }
        
        return res;
    }
};
