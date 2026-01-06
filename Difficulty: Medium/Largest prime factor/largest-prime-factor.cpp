class Solution {
  public:
    int largestPrimeFactor(int n) {
        // code here
        
    long long largest = -1;

    // Remove factor 2
    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }

    // Check odd factors
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
    }

    // If n is still > 1, it is prime
    if (n > 1)
        largest = n;

    return largest;
        
    }
};