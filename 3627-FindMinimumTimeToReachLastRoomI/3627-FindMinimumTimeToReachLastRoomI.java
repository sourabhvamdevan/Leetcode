// Last updated: 08/03/2026, 13:23:40
class Solution {

    class Node{
        int x;
        int y;
        int time;

        public Node(int x, int y, int time) {
            this.x=x;
            this.y=y;
            this.time=time;


        }
    }

    public int minTimeToReach(int[][] moveTime) {
        int n=moveTime.length;
        int m=moveTime[0].length;
        int[][]time=new int[n][m];
        boolean[][] visited=new boolean[n][m];
        int[][] dirs={{-1,0}, {1,0}, {0,-1}, {0,1}};
        for(int i=0;i<n;i++){
            Arrays.fill(time[i],Integer.MAX_VALUE);
        }
        PriorityQueue<Node> pq=new PriorityQueue<>((node1, node2) -> node1.time - node2.time);
        pq.add(new Node(0, 0, 0));
        time[0][0]=0;

        while(!pq.isEmpty()){
            Node node = pq.poll();
            int x=node.x;
            int y=node.y;
            visited[x][y] = true;

            for (int[] dir:dirs) {
                int nx=x + dir[0];
                int ny=y + dir[1];
                if (nx >=0 && ny>=0 && nx <n && ny < m) {
                    if (!visited[nx][ny]) {
                        int newSourabh=1 + Math.max(node.time, moveTime[nx][ny]);
                        if (newSourabh < time[nx][ny]) {
                            time[nx][ny] = newSourabh;
                            pq.add(new Node(nx, ny, newSourabh));
                        }
                    }
                }



            }
        }



        return time[n-1][m-1];
    }
}