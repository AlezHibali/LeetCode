// 13. Roman to Integer

// Hash Solution
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int length = s.length();
        
        unordered_map<char, int> hash{{'I',1},
                                 {'V',5},
                                 {'X',10},
                                 {'L',50},
                                 {'C',100},
                                 {'D',500},
                                 {'M',1000}};
        
        for (int i = 0; i < length; i++){
            if (i == length - 1){
                result += hash[s[i]];
                break;
            }
            if (hash[s[i]] < hash[s[i+1]])
                result -= hash[s[i]];
            else
                result += hash[s[i]];
        }
        
        return result;
    }
};



// bad solution
class SolutionBad {
public:
    int romanToInt(string s) {
        int result = 0;
        int length = s.length();
        
        for (int i = 0; i < length; i++){
            if (s[i] == 'M')
                result += 1000;
            else if (s[i] == 'D')
                result += 500;
            else if (s[i] == 'C'){
                if (i != length-1){
                    if (s[i+1] == 'D' || s[i+1] == 'M'){
                        result -= 100;
                        continue;
                    }
                }
                result += 100;
            }
            else if (s[i] == 'L')
                result += 50;
            else if (s[i] == 'X'){
                if (i != length-1){
                    if (s[i+1] == 'L' || s[i+1] == 'C'){
                        result -= 10;
                        continue;
                    }
                }
                result += 10;
            }
            else if (s[i] == 'V')
                result += 5;
            else if (s[i] == 'I'){
                if (i != length-1){
                    if (s[i+1] == 'V' || s[i+1] == 'X'){
                        result -= 1;
                        continue;
                    }
                }
                result += 1;
            } 
        }
        return result;
    }
};
