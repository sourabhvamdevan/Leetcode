class Solution {
  public:
  
  int subarrayRanges(vector<int>& arr) {
        int n = arr.size();
    vector<int> leftMin(n), rightMin(n);
    vector<int> leftMax(n), rightMax(n);

    stack<int> st;

    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        leftMin[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

  
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        rightMin[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    while (!st.empty()) st.pop();


    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
        leftMax[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();


    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        rightMax[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

 
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        int maxContri = leftMax[i] * rightMax[i] * arr[i];
        int minContri = leftMin[i] * rightMin[i] * arr[i];
        totalSum += (maxContri - minContri);
    }
    
    
    

    return totalSum;
}




};