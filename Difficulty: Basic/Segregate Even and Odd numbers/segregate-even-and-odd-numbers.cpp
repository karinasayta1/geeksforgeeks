class Solution {
  public:
    void segregateEvenOdd(vector<int>& arr) {
        // code here
        vector<int> even, odd;
        
        for(int i = 0; i<arr.size(); i++){
            if(arr[i]%2 == 0){
                even.push_back(arr[i]);
            }
            else{
                odd.push_back(arr[i]);
            }
        }
        
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        
        int i = 0;
        for(int x : even){
            arr[i] = x;
            i++;
        }
         for(int y : odd){
            arr[i] = y;
            i++;
        }
        
        
        }
};