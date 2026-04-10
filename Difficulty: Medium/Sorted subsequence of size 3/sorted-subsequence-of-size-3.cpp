class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
     int n = arr.size();
    if (n < 3)
        return {};

    int first = INT_MAX;
    int second = INT_MAX;
    int prevFirst = INT_MAX;

    // Iterating through the array
    for (int i = 0; i < n; i++) {
        int x = arr[i];

        // Updating first and second smallest numbers
        if (x <= first) {
            first = x;
        } else if (x <= second) {
            second = x;
            prevFirst = first;
        }
        // If a third number greater than first and second is found
        else {
            return {prevFirst, second, x};
        }
    }
    return {};
     
     
    }
};