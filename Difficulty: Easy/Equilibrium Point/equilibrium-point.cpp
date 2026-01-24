class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        // code here
        int leftsum=0, totalsum=0;
        for(int i : arr){
            totalsum+=i;
        }
        
        for(int i = 0; i < arr.size(); i++){
            if(leftsum == totalsum - arr[i] - leftsum){
                return i;
            }
            leftsum += arr[i];
        }
        
        return -1;
        
    }
};