class Solution {
public:
    
    long long solve(int n) {
        
        if(n <= 1)
            return 1;
        
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans += solve(i) * solve(n - 1 - i);
        }
        
        return ans;
    }
    
    long long count(int N) {
        return solve(N / 2);
    }
};
