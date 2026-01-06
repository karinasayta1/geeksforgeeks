class Solution {
  public:
    string reverseEqn(string s) {
        // code here.
        
        stack<string> st;
        string num ="";
        
        for(char c : s){
            
            if(isdigit(c)){
                num += c;
            }
            else{
                st.push(num);
                num="";
                st.push(string(1,c));
            }
        }
        
        st.push(num);
        
        string result="";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        return result;
    }
};