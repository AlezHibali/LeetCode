// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int findVer(int l, int r){
        if (l == r-1)
            return r;
        int inc = (l%2 == 1)&&(r%2 == 1)?1:0;
        int mid = l/2 + r/2 + inc;
        if (isBadVersion(mid))
            return findVer(l, mid);
        else
            return findVer(mid, r);
    }
    
    int firstBadVersion(int n) {
        return findVer(0, n);
    }
};
