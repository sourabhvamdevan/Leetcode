// Last updated: 08/03/2026, 13:22:48
class Solution {
    int[] parent;

    
    
    int find(int x){
        return parent[x]==x?x : (parent[x] = find(parent[x]));
    }
    
    void union(int x, int y){
        parent[find(x)] = find(y);
    }
    
    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        parent = new int[n];
        for(int i=0;i<n;i++)parent[i]=i;
        
        boolean[] ans=new boolean[queries.length];
        int i=0;
        for(int j=1;j<n;j++){
            while (i < j && nums[j] - nums[i] > maxDiff) i++;
            if (i < j)union(j, i);

            
        }
        
        for (int q = 0; q < queries.length; q++){
            ans[q]=find(queries[q][0]) == find(queries[q][1]);
        }

        
        
        return ans;
    }
}