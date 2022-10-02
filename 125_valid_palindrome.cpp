class Solution {
public:
    // iterate from both side at the same time, if both side have valid number
    // contin is true and go compare, else remove or adjust the left/right element
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        bool contin = true;
        
        while (left <= right){
            contin = true;
            char l = s[left];
            char r = s[right];
            
            // left indent
            if ((l>='A' && l<='Z')) // if uppercase
                l += ('a'-'A');
            else if (!((l>='a' && l<='z')||(l>='0' && l<='9'))){
                left += 1;
                contin = false;
            }
            
            // right indent
            if ((r>='A' && r<='Z')) // if uppercase
                r += ('a'-'A');
            else if (!((r>='a' && r<='z')||(r>='0' && r<='9'))){
                right -= 1;
                contin = false;
            }
            
            if (!contin)
                continue;
            
            // compare return false if diff
            if (l != r)
                return false;
            left++;
            right--;
        }
        
        return true;
    }
};
