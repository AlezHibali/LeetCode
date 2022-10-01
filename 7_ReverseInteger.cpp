#include <math.h>

class Solution {
public:
    int reverse(int x) {
        if (x == 0)
            return x;
        int res = 0;
        
        // store digits
        while (x != 0){
            int digit = x % 10;
            x = x / 10;
            
            // if over limit
            if ((res > 0 && res > (INT_MAX - digit)/10) 
                || (res < 0 && res < (INT_MIN - digit)/10))
                return 0;

            res = res * 10 + digit;
        }

        return res;
    }
};
