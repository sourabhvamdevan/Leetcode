// Last updated: 08/03/2026, 13:22:36

#define vi vector<int>
class Solution {
public:
   int maxFreqSum(string s){
vi arr(26,0);
int mxVowel=0;
int mxConst=0;
int n=s.length();
for(int i=0;i<n;i++){
    arr[s[i]-'a']++;
if(s[i]=='a'|| s[i]=='e'|| s[i]=='o'|| s[i]=='u' || s[i]=='i'){
mxVowel=max(mxVowel,arr[s[i]-'a']);

}else{
    mxConst=max(mxConst,arr[s[i]-'a']);

}
   }

   return mxConst+mxVowel;
}
    
};