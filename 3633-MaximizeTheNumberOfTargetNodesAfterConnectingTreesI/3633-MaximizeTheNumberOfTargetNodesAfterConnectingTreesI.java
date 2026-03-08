// Last updated: 08/03/2026, 13:23:35


class Solution {
    public int[] maxTargetNodes(int[][] edges1, int[][] edges2, int k){

        //isme apan unique nodes track krenge using sets
        Set<Integer> nodes1=new HashSet<>();
        Set<Integer> nodes2=new HashSet<>();

        //yeh adjacency list bnega graph 1 ke liye(graph 1)
        HashMap<Integer,ArrayList<Integer>> g1=new HashMap<>();
        for(int[] edge:edges1){
            int u=edge[0],v=edge[1];




            //kyuki dono graph unidrected hai toh yeh both direcions ke liye hai 


            g1.computeIfAbsent(u,x->new ArrayList<>()).add(v);
            g1.computeIfAbsent(v,x->new ArrayList<>()).add(u);

            //nxt step hoga add nodes to the set
            nodes1.add(u);
            nodes1.add(v);


        }

        //isme apan adjacency list bnaenye for graph 2 
        HashMap<Integer,ArrayList<Integer>> g2=new HashMap<>();
        for(int[] edge:edges2){
            int u=edge[0],v=edge[1];




            g2.computeIfAbsent(u, x -> new ArrayList<>()).add(v);
            g2.computeIfAbsent(v, x -> new ArrayList<>()).add(u);



            nodes2.add(u);
            nodes2.add(v);
        }

        //yeh edge cases handle krne ke liye 

        //that means if(k==0) then sabhi nodes ki value 1 hogi
        if(k==0){
            int maxNodeId=nodes1.stream().max(Integer::compare).orElse(0);
            int[] result = new int[maxNodeId + 1];
            Arrays.fill(result, 1);  //Every node can reach only itself
            return result;


        }

        //isme apan maximum number of nodes find krenge jo ki reachable hai in graph 2 
        int maxFromG2=0;
        for(int node:nodes2){
            Set<Integer> visited=new HashSet<>();
            int reachable=dfs(g2,k-1,node,visited);
            maxFromG2=Math.max(maxFromG2, reachable);


        }



        maxFromG2++;  //Include the starting node itself

        //initialize arr of appropriate size 

        int maxNodeId=nodes1.stream().max(Integer::compare).orElse(0);
        int[] result=new int[maxNodeId+1];

        

//kisi bhi 1 node ke liye apan total number of reachable nodes find krenge of kth depth
        for(int node:nodes1){
            Set<Integer> visited=new HashSet<>();
            int reachableFromG1=dfs(g1, k, node, visited) + 1;  // +1 to include the root
            result[node]=reachableFromG1 +maxFromG2;
        }



        return result;
    }

   //yeh apna utility function hai 
    private int dfs(HashMap<Integer, ArrayList<Integer>> graph, int k, int u, Set<Integer> visited) {
        if(k==0||!graph.containsKey(u))return 0;

        visited.add(u);
        int cnt=0;

        for(int neighbor : graph.get(u)){
            if(!visited.contains(neighbor)){
                //add 1 for this neighbourr and then apan dfs continue rakhenge
                cnt += 1 + dfs(graph, k - 1, neighbor, visited);
            }
        }

        

        return cnt;
    }
}
