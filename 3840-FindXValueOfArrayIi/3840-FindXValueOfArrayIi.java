// Last updated: 08/03/2026, 13:22:46

class Solution {
    private int n, k;
    private int[] nums;
    private Node[] seg;  //yeh seg tree arr ke liye


    

    private class Node {
        int totalProd;
        int[] freq;
        Node() {
            freq = new int[k];
            totalProd = 1;



            
        }
    }

    public int[] resultArray(int[] nums, int k, int[][] queries) {
        this.n=nums.length; //yeh length ke liye
        this.k=k;
        this.nums=nums.clone();  //yeh modification of origial arr ke liye
        this.seg=new Node[4 * n];
        build(1,0,n-1);

        int[] result=new int[queries.length];
        for (int i=0;i<queries.length;i++){
            int idx = queries[i][0];
            int val = queries[i][1];
            int start = queries[i][2];
            int x = queries[i][3];



          //update the val at index to null;

            update(1, 0, n - 1, idx, val);
            Node answerNode = query(1, 0, n - 1, start, n - 1);
            result[i] = answerNode.freq[x];
        }
        return result;
    }


//yeh segment tree recursively bnayega 
    private void build(int node, int l, int r) {
        seg[node]=new Node();
        if (l ==r){

            int p = nums[l] % k;
            if (p < 0)p+=k;  //yeh -ve values handle krne ke liye 
            seg[node].totalProd = p;
            seg[node].freq[p] = 1;


            
        } else {
            int mid = (l + r)>>>1;
            build(node << 1, l, mid);
            build(node << 1 | 1, mid + 1, r);
            seg[node] = merge(seg[node << 1], seg[node << 1 | 1]);
        }
    }



    
    private void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            int p = val % k;
            if (p < 0) p += k;
            seg[node] = new Node();
            seg[node].totalProd = p;
            seg[node].freq[p] = 1;
        } else {
            int mid = (l + r) >>> 1;
            if (pos <= mid) update(node << 1, l, mid, pos, val);
            else update(node << 1 | 1, mid + 1, r, pos, val);
            seg[node] = merge(seg[node << 1], seg[node << 1 | 1]);
        }
    }

    private Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return seg[node];
        }
        if (r < ql || l > qr) {
            return new Node();
        }
        int mid=(l + r)>>>1;
        Node left = query(node << 1, l, mid, ql, qr);
        Node right = query(node << 1 | 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }
 //yeh merge krega do nodes ko (A and B) 
 public Node merge(Node A, Node B){

 
        Node C = new Node();

         //yeh calculate krega combined segement mod k ke liye 
        C.totalProd = (int)((A.totalProd * 1L * B.totalProd) % k);
        for (int m = 0; m < k; m++) {
            C.freq[m] = A.freq[m];
        }


        
        for (int p = 0; p < k; p++) {
            int cnt = B.freq[p];
            if (cnt != 0) {
                int m = (int)((A.totalProd * 1L * p) % k);
                C.freq[m] += cnt;


                
            }
        }

        
        return C;
    }
}


