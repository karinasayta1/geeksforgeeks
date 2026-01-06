// User function Template for C++

class Solution {
  public:
  
  bool isprime(int x){
      
      if(x<2) return false;
      
      for(int i =2; i*i <=x; i++){
          if(x%i == 0) return false;
      }
      
      return true;
      
      
  }
    int prime_Sum(int n) {
        // Code here
        int sum =0;
        for(int i =2; i<=n; i++){
            if(isprime(i))
            sum += i;
        }
        return sum; 
    }
};