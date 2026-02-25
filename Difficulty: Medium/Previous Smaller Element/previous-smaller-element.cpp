class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        
        // Remove elements >= current element
        while(!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // If stack empty → no smaller element
        if(st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }

        // Push current element
        st.push(arr[i]);
    }

    return ans;
    }
};