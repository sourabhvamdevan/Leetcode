class Solution {
  public:
    struct Item {
        int value;
        int weight;
        double ratio;
    };

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<Item> items(n);

        for(int i=0;i<n;i++){
            items[i]={val[i], wt[i], (double)val[i] / wt[i]};
        }

//yeh comparator function bnaya hai
        sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.ratio > b.ratio;
        });

        double totalValue=0.0;
        int currentCapacity=capacity;

        for(int i=0;i<n;i++){
            if (currentCapacity == 0) break;

            if (items[i].weight <= currentCapacity) {

                totalValue += items[i].value;
                currentCapacity -= items[i].weight;
            } else{

                totalValue += items[i].ratio * currentCapacity;
                currentCapacity = 0;
    }
        }

        return totalValue;
    }
};