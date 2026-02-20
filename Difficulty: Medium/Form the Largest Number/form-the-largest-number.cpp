class Solution {
  public:
  
  static bool myCompare(string &s1, string &s2){
      
      return (s1+s2) > (s2 +s1);
  }
  
  
    string findLargest(vector<int> &arr) {
        
        
        
         vector<string> numbers;
    for(int ele: arr) {
        numbers.push_back(to_string(ele));
    }
        

    sort(numbers.begin(), numbers.end(), myCompare);

 
    if (numbers[0] == "0") {
        return "0";
    }

   
    string res = "";
    for (string& num : numbers) {
        res.append(num);
    }

    return res;
        
    }
};