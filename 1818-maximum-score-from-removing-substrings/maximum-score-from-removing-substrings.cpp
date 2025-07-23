class Solution {
int helper(stack<char>& st,string s,string t, int num){
    int ans=0;
    for(auto ch:s){
        if(!st.empty()&& st.top()==t[0] &&ch==t[1]){
            st.pop();
            ans+=num;

        }else{
            st.push(ch);

        }
    }

    return ans;

}
    private:
    #define sc stack<char> st
public:

    int maximumGain(string s, int x, int y){
 sc;
 string t=x>y ?"ab":"ba";
 int ans=helper(st,s,t,max(x,y));

 s="";
 while(!st.empty()){
    s+=st.top();
    st.pop();

 }

 reverse(s.begin(),s.end());
 swap(t[0],t[1]);
 ans+=helper(st,s,t,min(x,y));
 return ans;
        
    }
};