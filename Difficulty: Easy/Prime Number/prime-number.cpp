class Solution {
  public:
    bool isPrime(int n) {
        // code here
        int count =0;
        if (n <= 1) return false;
        
        for(int i =1; i<=n; i++){
            if(n % i ==0){
                count++;
            }
        }
        if(count == 2){
            return true;
        }
        else
        return false;
    }
};
