class Solution {
public:
    // KMP
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        vector<int>dp(size+1,0);
        int i = 1;
        int j = 0;
        while(i<size){
            if (s[i] == s[j]) dp[++i]=++j;
            else if (j==0) i++;
            else j = dp[j];
            cout << i << j<<endl;
        }
        return dp[size]&&dp[size]%(size-dp[size])==0;
    }
};
