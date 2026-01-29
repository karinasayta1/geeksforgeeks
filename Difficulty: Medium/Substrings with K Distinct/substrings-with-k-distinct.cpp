class Solution {
  public:
  
  long long atMostK(string &s, int k) {
        if (k < 0) return 0;

        vector<int> freq(26, 0);   // frequency of characters
        int left = 0;
        int distinct = 0;
        long long count = 0;

        for (int right = 0; right < s.size(); right++) {
            // add right character
            if (freq[s[right] - 'a'] == 0)
                distinct++;
            freq[s[right] - 'a']++;

            // shrink window if distinct > k
            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }

            // all substrings ending at 'right' are valid
            count += (right - left + 1);
        }

        return count;
    }
    int countSubstr(string& s, int k) {
        // code here
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};