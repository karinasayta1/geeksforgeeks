class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
       int totalSum = 0;   // sum of whole array

    // For normal max subarray
    int currMax = arr[0];
    int maxNormal = arr[0];

    // For minimum subarray
    int currMin = arr[0];
    int minSubarray = arr[0];

    for (int i = 0; i < arr.size(); i++) {

        totalSum += arr[i];

        // skip index 0 because we already used arr[0]
        if (i > 0) {

            // Best subarray ending at i (MAX)
            currMax = max(arr[i], currMax + arr[i]);
            maxNormal = max(maxNormal, currMax);

            // Best subarray ending at i (MIN)
            currMin = min(arr[i], currMin + arr[i]);
            minSubarray = min(minSubarray, currMin);
        }
    }

    // If all numbers are negative
    if (maxNormal < 0)
        return maxNormal;

    int maxWrapping = totalSum - minSubarray;

    return max(maxNormal, maxWrapping);
    
    }
};