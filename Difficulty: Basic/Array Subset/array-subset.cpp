class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
    unordered_map<int,int> freq;

    // Count frequency of elements in a
    for(int x : a){
        freq[x]++;
    }

    // Check elements of b
    for(int x : b){
        if(freq[x] == 0){
            return false;
        }
        freq[x]--;
    }

    return true;
    }
};