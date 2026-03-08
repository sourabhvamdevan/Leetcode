// Last updated: 08/03/2026, 13:24:30
class Solution {
    public int countPrefixSuffixPairs(String[] words) {
        int count = 0;
        int n = words.length;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }

    private boolean isPrefixAndSuffix(String str1, String str2) {
        return str2.startsWith(str1) && str2.endsWith(str1);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        String[] words1 = {"a","aba","ababa","aa"};
        System.out.println(sol.countPrefixSuffixPairs(words1));  

        String[] words2 = {"pa","papa","ma","mama"};
        System.out.println(sol.countPrefixSuffixPairs(words2));  

        String[] words3 = {"abab","ab"};
        System.out.println(sol.countPrefixSuffixPairs(words3));  
    }
}
