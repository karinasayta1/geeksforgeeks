class Solution {
  public:
  
  bool ispossiblesol(vector<int>& arr, int n, int k, int mid){
      int studcount = 1;
      int pagesum = 0;
      
      for(int i = 0; i < n; i++){
          if(pagesum + arr[i] <= mid){
              pagesum = pagesum + arr[i];
          }
          else{
              studcount++;
              if(studcount > k || arr[i] > mid){
                  return false;
              }
              pagesum = 0;
              pagesum = arr[i];
          }
      }
      return true;
  }
  
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k > n) return -1;

        int s = 0;
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        int e = sum;
        int ans = -1;
        
        while(s <= e){
            int mid = s + (e - s) / 2;
            
            if(ispossiblesol(arr, n, k, mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};
