class Solution {

    private:
    #define vs vector<string>
    #define pb push_back
public:
    vector<string> generateParenthesis(int n) {
        if(!n){
            return {""};
        }
        vs parens;
        for(int i=0;i<n;i++){
            for(string l:generateParenthesis(i)){
                for(string r:generateParenthesis(n-i-1)){
                    parens.pb('('+l+')'+r);

                }
            }
        }


        return parens;


    }
};