// inspired by Discussion
class Solution85 {
public:
    int firstUniqChar(string s) {
        vector<int> st (26,0);
        for (auto i : s)
            st[i-'a']++;
        for (int i = 0; i < s.size(); i++)
            if (st[s[i]-'a'] == 1)
                return i;
        return -1;
    }
};

// more clear version of first attempt
class SolutionClear {
public:
    int firstUniqChar(string s) {
        map<char, int> st;
        
        for (int i = 0; i < s.size(); i++){
            st[s[i]]++;
        }
        
        for (int i = 0; i < s.size(); i++){
            if (st[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
};

// first attempt
class Solution {
public:
    int firstUniqChar(string s) {
        // int is index, bool is whether it is unique
        map<char, pair<int, bool>> st;
        map<char, pair<int, bool>>::iterator it;
        
        // if not found, init with index and true
        // if found, set bool to false
        for (int i = 0; i < s.size(); i++){
            it = st.find(s[i]);
            if (it == st.end()){
                st[s[i]].first = i;
                st[s[i]].second = true;
            }
            else
                st[s[i]].second = false;
        }
        
        // find the first one true
        for (int i = 0; i < s.size(); i++){
            if (st[s[i]].second)
                return st[s[i]].first;
        }
        
        return -1;
    }
};
