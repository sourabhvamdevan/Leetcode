// Last updated: 08/03/2026, 13:24:10
class Solution {
public:
    bool doesAliceWin(string s) {
    for(int i=0;i<s.length();++i){
        char ch=s[i];
if(ch=='a'||ch=='e'|| ch=='i' || ch=='o'||ch=='u')return true;

    }  


    return false;
    }
};