class Solution {
    private:
    #define pb push_back
public:
    vector<string> fizzBuzz(int n) {
       vector<string> v;
       for(int i=1;i<n+1;i++){
        if(i%3==0 && i%5==0){
v.pb("FizzBuzz");
        }

        else if(i%3==0){
            v.pb("Fizz");

        }

        else if(i%5==0){
            v.pb("Buzz");

        }

   else {
    v.pb(to_string(i));


   }



       } 



       return v;
    }
};