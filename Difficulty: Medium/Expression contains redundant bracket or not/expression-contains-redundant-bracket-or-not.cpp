class Solution {
  public:
   bool checkRedundancy(string& s){
    stack<char> st;

    
    for (int i=0; i<s.size(); i++) {


        if (s[i] == ')') {
            char top = st.top();
            st.pop();

        
            bool flag = true;
            
            while (!st.empty() and top != '(') {

           
                if (top == '+' or top == '-' or
                    top == '*' or top == '/')
                    flag = false;

         
                top = st.top();
                st.pop();
            }

     
            if (flag == true)
                return true;
        }
        
        
        else
            st.push(s[i]); 
    }
    return false;
}
};
