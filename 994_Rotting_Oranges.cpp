class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // no hash for pair, so x,y are converted to 100x+y
        unordered_set<int> good;
        unordered_set<int> bad;
        int x = grid.size();
        int y = grid[0].size();
        
        // iterate through grid
        for (int i = 0; i < x; i++){
            for (int j = 0; j < y; j++){
                if (grid[i][j] == 1)
                    good.insert(100*i+j);
                else if (grid[i][j] == 2)
                    bad.insert(100*i+j);
            }
        }
        
        // processing rotting
        int res = 0;
        bool change = false;
        while (!good.empty()){
            change = false;
            unordered_set<int> badd = bad;
            for (auto i : badd){
                if (i/100 != x-1 && good.find(i+100) != good.end()){
                    change = true;
                    good.erase(i+100);
                    bad.insert(i+100);
                }
                if (i%100 != y-1 && good.find(i+1) != good.end()){
                    change = true;
                    good.erase(i+1);
                    bad.insert(i+1);
                }
                if (i/100 != 0 && good.find(i-100) != good.end()){
                    change = true;
                    good.erase(i-100);
                    bad.insert(i-100);
                }
                if (i%100 != 0 && good.find(i-1) != good.end()){
                    change = true;
                    good.erase(i-1);
                    bad.insert(i-1);
                }
            }
            if (!change)
                return -1;
            res++;
        }
        return res;
    }
};
