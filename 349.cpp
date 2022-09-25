# 349. Intersection of Two Arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hash;
        unordered_map<int,int> hash2;
        vector<int> result;
        
        for (int i = 0; i < nums1.size(); i++){
            // input all nums1 to hash uniquely
            if (hash.find(nums1[i]) == hash.end())
                hash[nums1[i]] = i;
        }
        
        // use nums2 to find result in hash
        for (int i = 0; i < nums2.size(); i++){
            // store result in hash2 to see if duplicate
            if (hash.find(nums2[i]) != hash.end() 
                && hash2.find(nums2[i]) == hash2.end()){
                hash2[nums2[i]] = i;
                result.push_back(nums2[i]);
            }
        }
        
        return result;
    }
};
