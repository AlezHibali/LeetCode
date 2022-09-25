// 66. Plus One

class Solution {
public:
    void recursion(vector<int>& digits, int size, int index, int plusOne){
        // stop when no plus one is needed
        if (plusOne == 0){
            return;
        }
        // if that digit is 9, then increment next digit and set 0 for it
        if (digits[index] == 9){
            digits[index] = 0;
            // if it is 999999, then insert 1 at front
            if (index == 0){
                digits.insert(digits.begin(),1);
                return;
            }
            else
                recursion(digits, size, index-1, 1);
        }
        else {
            // increment corresponding digit
            digits[index]++;
            return;
        }
            
    }
    
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        
        recursion(digits, size, size-1, 1);
        
        return digits;
    }
};
