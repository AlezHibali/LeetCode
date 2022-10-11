class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int sz = temperatures.size();
        vector<int> res(sz,0);
        
        // pop all that are smaller
        // push big values
        // do nothing if stack has nothing bigger than curr
        for (int i = sz-1; i >= 0; i--){
            while (!st.empty() && temperatures[i] >= temperatures[st.top()])
                st.pop();
            if (!st.empty()){
                res[i] = st.top()-i;
            }
            st.push(i);
        }
        return res;
    }
};
