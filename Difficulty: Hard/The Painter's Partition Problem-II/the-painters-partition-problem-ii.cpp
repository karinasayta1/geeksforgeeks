class Solution {
public:
    
    bool isPossible(vector<int>& arr, int n, int k, int mid) {
        int painterCount = 1;
        int timeSum = 0;

        for(int i = 0; i < n; i++) {
            if(timeSum + arr[i] <= mid) {
                timeSum += arr[i];
            } else {
                painterCount++;
                if(painterCount > k || arr[i] > mid) {
                    return false;
                }
                timeSum = arr[i];
            }
        }
        return true;
    }

    long long minTime(vector<int>& arr, int k) {
        int n = arr.size();

        int s = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            
        }
        int e = sum;             
        int ans = -1;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(isPossible(arr, n, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
