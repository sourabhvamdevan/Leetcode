class Solution {
  public:
   int areAll9s(const vector<int>& num) {
    for (int i = 0; i < num.size(); ++i) {
        if(num[i]!=9)return 0;
    }
    return 1;
}

void nextPalindromeUtil(vector<int>& num) {
    int n = num.size();
    int mid = n / 2;
    bool leftSmaller = false;
    int i = mid - 1;
    int j = (n % 2) ? mid + 1 : mid;


    while(i>=0&&num[i]==num[j])i--,j++;
    


    if (i < 0 || num[i] < num[j]) leftSmaller = true;


    while (i >= 0)
    {
        num[j] = num[i];
        j++;
        i--;
    }


    if (leftSmaller)
    
    {
        int carry=1;
        i = mid - 1;
        if (n % 2 == 1) {
            num[mid] += carry;
            carry = num[mid] / 10;
            num[mid] %= 10;
            j = mid + 1;
        } else {
            j = mid;
        }

        while (i >= 0)
        {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] %= 10;
            num[j++] = num[i--];
        }
        
        
        
    }
}

vector<int> nextPalindrome(vector<int>& num)
{
    vector<int> ans;
    if (areAll9s(num)) {
        ans.push_back(1);
        for (int i = 1; i < num.size(); i++) ans.push_back(0);
        ans.push_back(1);
    } else {
        nextPalindromeUtil(num);
        for (int i = 0; i < num.size(); i++) {
            ans.push_back(num[i]);
        }
    }
    return ans;
}
};