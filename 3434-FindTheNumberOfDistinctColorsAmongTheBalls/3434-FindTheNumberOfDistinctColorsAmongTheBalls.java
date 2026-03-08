// Last updated: 08/03/2026, 13:24:16


class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        Map<Integer, Integer> ballColor = new HashMap<>(); 
        Map<Integer, Integer> colorCount = new HashMap<>();
        List<Integer> result = new ArrayList<>();

        int distinctColors = 0; 

        for (int[] query : queries) {
            int ball = query[0];
            int color = query[1];

            
            if (ballColor.containsKey(ball)) {
                int oldColor = ballColor.get(ball);
                colorCount.put(oldColor, colorCount.get(oldColor) - 1);
                if (colorCount.get(oldColor) == 0) {
                    colorCount.remove(oldColor);
                    distinctColors--; 
                }
            }

            
            ballColor.put(ball, color);
            colorCount.put(color, colorCount.getOrDefault(color, 0) + 1);
            if (colorCount.get(color) == 1) {
                distinctColors++; 
            }

            result.add(distinctColors);
        }

        
        return result.stream().mapToInt(i -> i).toArray();
    }
}
