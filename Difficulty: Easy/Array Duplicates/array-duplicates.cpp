class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++) {

        int index = abs(arr[i]) - 1;

        if (arr[index] < 0) {
            ans.push_back(index + 1);
        } else {
            arr[index] = -arr[index];
        }
    }
    return ans;
        
    }
};