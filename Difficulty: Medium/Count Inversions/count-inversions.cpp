class Solution {
  public:
    
    long long merge(vector<int>& arr, int start, int mid, int end) {
        vector<int> temp;
        int i = start, j = mid + 1;
        long long invCount = 0;

        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                // Count inversions
                invCount += (mid - i + 1);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= end) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            arr[start + k] = temp[k];
        }

        return invCount;
    }

    long long mergeSort(vector<int>& arr, int start, int end) {
        if (start >= end) return 0;

        int mid = start + (end - start) / 2;
        long long invCount = 0;

        invCount += mergeSort(arr, start, mid);
        invCount += mergeSort(arr, mid + 1, end);
        invCount += merge(arr, start, mid, end);

        return invCount;
    }

    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};