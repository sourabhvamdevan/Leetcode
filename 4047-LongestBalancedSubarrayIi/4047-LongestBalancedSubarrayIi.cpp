// Last updated: 08/03/2026, 13:22:19



struct SegTree {
    int n;
    vector<int> mn, mx, lazy;

    SegTree(int n): n(n), mn(4*n,0), mx(4*n,0), lazy(4*n,0) {}

    void push(int i){
        if(lazy[i]){
            for(int c: {2*i,2*i+1}){
                mn[c]+=lazy[i];
                mx[c]+=lazy[i];
                lazy[c]+=lazy[i];
            }
            lazy[i]=0;
        }
    }

    void add(int i,int L,int R,int l,int r,int v){
        if(r<L || R<l) return;
        if(l<=L && R<=r){
            mn[i]+=v; mx[i]+=v; lazy[i]+=v;
            return;
        }
        push(i);
        int M=(L+R)/2;
        add(2*i,L,M,l,r,v);
        add(2*i+1,M+1,R,l,r,v);
        mn[i]=min(mn[2*i],mn[2*i+1]);
        mx[i]=max(mx[2*i],mx[2*i+1]);
    }

    int first_zero(int i,int L,int R,int ql,int qr){
        if(qr<L || R<ql) return -1;
        if(mn[i]>0 || mx[i]<0) return -1;
        if(L==R) return L;
        push(i);
        int M=(L+R)/2;
        int x=first_zero(2*i,L,M,ql,qr);
        if(x!=-1) return x;
        return first_zero(2*i+1,M+1,R,ql,qr);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        SegTree st(n);
        unordered_map<int,int> last;
        int ans=0;

        for(int r=0;r<n;r++){
            int x=nums[r];
            int p= last.count(x)?last[x]:-1;
            int w=(x%2==0)?1:-1;

            st.add(1,0,n-1,p+1,r,w);

            int l=st.first_zero(1,0,n-1,0,r);
            if(l!=-1) ans=max(ans,r-l+1);

            last[x]=r;
        }
        return ans;
    }
};