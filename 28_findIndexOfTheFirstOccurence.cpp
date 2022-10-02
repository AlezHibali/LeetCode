class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenA = haystack.length();
        int lenB = needle.length();
        
        if (lenB == 0)
            return 0;
        
        int i = 0; // index for haystack
        int j = 0; // index for needle
        int result = -1;
        bool update = true;
        
        while (i < lenA && j < lenB){
            if (haystack[i] == needle[j]){
                i++;
                j++;
                if (update){
                    result = i - 1;
                    update = false;
                }
            }
            // if not match, then reset j and continue with i
            else{
                i -= (j-1);
                j = 0;
                update = true;
            }
        }
        if (j == lenB)
            return result;
        else
            return -1;
    }
};
