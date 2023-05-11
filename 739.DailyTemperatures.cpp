class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        vector<int> res;
        int n = T.size();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && T[st.top()] <= T[i]){
                st.pop();
            }
            if(st.size() == 0) res.push_back(0);
            else res.push_back(st.top() - i);
            st.push(i);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};