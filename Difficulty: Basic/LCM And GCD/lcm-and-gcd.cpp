class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        
        int A = a;
        int B = b;

        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }

    int gcd = a;
    int lcm = (A * B) / gcd;

    return {lcm, gcd};
    }
};