// User function Template for C++

class Solution {
  public:
    bool isDigitSumPalindrome(int n) {
        // code here
        int sum=0;
        while(n>0){
             sum += n % 10;
            n = n / 10;
           
        }
        
        int orig = sum;
        int rev =0;
        while (sum > 0) {
        rev = rev * 10 + (sum % 10);
        sum /= 10;
    }

    if(rev == orig) return true;
    else return false;
    }
};