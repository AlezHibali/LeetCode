// Optimized version of a-z
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        vector<int> st (26,0);
        
        for (int i = 0; i < s.size(); i++){
            st[s[i]-'a']++;
            st[t[i]-'a']--;
        }

        for (auto i : st)
            if (i != 0)
                return false;
        
        return true;
    }
};

// modified for not only a-z
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        unordered_map<char, int> st;
        for (auto i : s)
            st[i]++;
        for (auto i : t){
            if (st.find(i) == st.end() || st[i] == 0)
                return false;
            else
                st[i]--;
        }
        
        return true;
    }
};


// first attempt
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> st (26,0);
        
        for (auto i : s)
            st[i-'a']++;
        for (auto i : t)
            st[i-'a']--;
        
        for (auto i : st)
            if (i != 0)
                return false;
        
        return true;
    }
};
