// Last updated: 08/03/2026, 13:24:15
class Solution {
    static public String clearStars(String s) {
         char[] arr=s.toCharArray();
         int n=arr.length;
         PriorityQueue<int[]> pq=new PriorityQueue<>((a, b) -> {
            if(a[0] == b[0]){
                return b[1]-a[1];
            }


            return a[0] - b[0];
         });



         boolean[] removed=new boolean[n];

         for (int i = 0; i < n; i++) {
            if (arr[i] == '*') {
                int[] top = pq.poll();
                removed[top[1]] = true;
            } else {
                pq.add(new int[] { arr[i] - 'a', i });
            }
         }
         StringBuilder sb = new StringBuilder();
         for (int i = 0; i < n; i++) {
            if (!removed[i] && arr[i] != '*') {
                sb.append(arr[i]);
            }
         }
         return sb.toString();
    }
}