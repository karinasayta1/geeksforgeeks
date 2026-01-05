// User function Template for C++
class Solution {
  public:
    vector<int> getTable(int n) {
        // Write Your Code here
        vector<int> table;
        
        for(int i =1 ; i<=10; i++){
            table.push_back(i*n);
        }
        return table;
    }
};