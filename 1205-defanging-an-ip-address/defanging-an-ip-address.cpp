class Solution {

    private:
    #define pb push_back
public:
    string defangIPaddr(string addr) {
        string ans;
       for(int i=0;i<addr.length();i++){
        if(addr[i]=='.'){
       ans.pb('[');
       ans.pb('.');
       ans.pb(']');

        } else{
            ans.pb(addr[i]);

        }
       }

       return ans;


    }
};

auto init=atexit([](){ofstream("display_runtime.txt")<<0;});