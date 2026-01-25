class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Step 1: Count elements <= k
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] <= k)
                count++;
        }
        
        // Edge case: If no elements <= k or all elements <= k
        if(count == 0 || count == n)
            return 0;
        
        // Step 2: Count "bad" elements in first window of size count
        int bad = 0;
        for(int i = 0; i < count; i++) {
            if(arr[i] > k)
                bad++;
        }
        
        int min_swaps = bad;
        
        // Step 3: Slide the window
        for(int i = 1; i <= n - count; i++) {
            // Remove the element going out of the window
            if(arr[i - 1] > k)
                bad--;
            // Add the new element coming into the window
            if(arr[i + count - 1] > k)
                bad++;
            
            min_swaps = min(min_swaps, bad);
        }
        
        return min_swaps;
    }
};
