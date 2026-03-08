// Last updated: 08/03/2026, 13:23:02
class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        Map<Integer,TreeSet<Integer>> colToRows=new HashMap<>();
        Map<Integer,TreeSet<Integer>> rowToCols=new HashMap<>();
        
        for(int[] b:buildings){
            colToRows.computeIfAbsent(b[1], k -> new TreeSet<>()).add(b[0]);
            rowToCols.computeIfAbsent(b[0], k -> new TreeSet<>()).add(b[1]);
        }
        
        int cnt=0;
        
        for(int[] b:buildings){
            
            TreeSet<Integer> xCoords=colToRows.get(b[1]), yCoords = rowToCols.get(b[0]);
            if(xCoords.lower(b[0])!=null && xCoords.higher(b[0]) != null && 
                yCoords.lower(b[1])!=null && yCoords.higher(b[1]) != null) {
                cnt++;
            }
        }
        
        return cnt;
    }
}