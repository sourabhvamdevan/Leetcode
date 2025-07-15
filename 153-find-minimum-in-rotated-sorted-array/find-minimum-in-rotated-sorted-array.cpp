class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        int lo=0,hi=n-1;
        while(lo<hi){

            int mid=lo+(hi-lo)/2;
            if(mid>0 && a[mid]<a[mid-1]) return a[mid]++;
            if(a[mid]<a[hi])
              hi=mid-1;
              else lo =mid+1;


        }



        return a[max(0,hi)];


    }
};