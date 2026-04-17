class Solution {
  public:
    bool canFormPalindrome(string &s) {
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }

        int odd_count=0;
        for (auto const& [curr_char, count] : freq)
        {
            if (count % 2 != 0){
                odd_count++;
    }
        }

        return odd_count<=1;
    }
};