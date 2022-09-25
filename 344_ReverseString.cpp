// 344. Reverse String

class Solution {
public:
    void reverseString(vector<char>& s) {
        // if empty
        if (s.empty())
            return;
        
        int start = 0;
        int end = s.size()-1;
        
        while (start <= end){
            // swap is faster
            //iter_swap(s.begin()+start, s.begin()+end);
            swap(s[begin],s[end]);
            start++;
            end--;
        }
    }
};
