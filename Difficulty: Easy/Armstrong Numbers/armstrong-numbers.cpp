// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int num = n, sum =0;
        while(n>0){
            
            int digit = n % 10;
            n = n/10;
            
            sum += digit * digit * digit;
        }
        
        if(sum == num) return true;
        else return false;
    }
};