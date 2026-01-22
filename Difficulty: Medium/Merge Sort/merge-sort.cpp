class Solution {
  public:
    
    void merge(vector<int>& arr, int start, int mid, int end){
        vector<int> temp;
        int i = start, j = mid + 1; 
        
        while(i<=mid && j<=end){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
             
                temp.push_back(arr[i]);
                i++;
            
        }
        while(j<=end){
            temp.push_back(arr[j]);
                j++;
        }
        
        for(int idx = 0 ; idx < temp.size(); idx++){
            arr[idx+start] = temp[idx];
        }
    }
    
    
    
    
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        int start = l, end = r;
        if (start >= end) return;
        if(start<end){
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
        }
    
    }
};