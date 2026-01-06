class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        
    vector<int> small, large;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            small.push_back(i);
            if (i != n / i)
                large.push_back(n / i);
        }
    }

    reverse(large.begin(), large.end());

    for (int x : small)
        cout << x << " ";

    for (int x : large)
        cout << x << " ";
    
    
    }
};