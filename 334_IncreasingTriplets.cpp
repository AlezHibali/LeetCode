class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        int f = INT_MAX, s = INT_MAX;
        
        for (auto i : nums){
            if (i <= f)
                f = i;
            else if ( i <= s)
                s = i;
            else
                return true;
        }
        return false;

    }
};
