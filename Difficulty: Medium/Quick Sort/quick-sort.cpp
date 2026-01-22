class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low<high){
            int pividx = partition(arr, low, high); 
            quickSort(arr, low, pividx-1);
            quickSort(arr, pividx+1, high);
        }
       
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        
        int idx = low-1;
        int pivot = arr[high];
        for(int j = low; j<high; j++){
             if(arr[j]<=pivot){
                idx++;
                swap(arr[j],arr[idx]);
            }
        }
        idx++;
        swap(arr[high], arr[idx]);
        return idx;
    }
};