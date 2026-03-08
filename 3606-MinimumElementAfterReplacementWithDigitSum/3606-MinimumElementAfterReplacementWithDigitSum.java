// Last updated: 08/03/2026, 13:23:48
class Solution {
    public int minElement(int[] nums) {
        int min = Integer.MAX_VALUE;
        for (int num : nums) {
            int sumOfDigits = sumOfDigits(num);
            if (sumOfDigits < min) {
                min = sumOfDigits;
            }
        }
        return min;
    }

    private int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}
