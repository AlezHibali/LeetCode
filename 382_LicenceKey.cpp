class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        int temp = 0;
        for (int i = s.size()-1; i >= 0; i--){
            if (s[i] == '-') continue;
            if (s[i] > 'Z') res.push_back(s[i]-'a'+'A');
            else res.push_back(s[i]);
            if(++temp == k) {
                res.push_back('-');
                temp = 0;
            }
        }

        if (res.size() == 0)
            return "";
        if (res[res.size()-1] == '-')
            res.pop_back();
        
        reverse(res.begin(),res.end());
        return res;
    }
};
