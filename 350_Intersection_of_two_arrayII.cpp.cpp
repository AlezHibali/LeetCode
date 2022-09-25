// 350. Intersection of Two Arrays II

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hash;

        vector<int> result;
        
        // put all nums1 to has
        for (int i = 0; i < nums1.size(); i++){
            hash[nums1[i]] += 1;
        }
        
        // use nums2 to find result in hash
        for (int i = 0; i < nums2.size(); i++){
            if (hash.find(nums2[i]) != hash.end() && hash[nums2[i]] != 0){
                result.push_back(nums2[i]);
                hash[nums2[i]] -= 1;
            }
        }
        
        return result;
    }
};
