// Last updated: 08/03/2026, 13:23:41
#define vi vector<int>


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
int n=nums.size(),mx=ranges::max(nums);

vi freq(mx+1,0);
for(int e:nums){
    freq[e]++;

}

for(int i=1;i<freq.size();i++){
    freq[i]+=freq[i-1];

}

int ans=0, mn=ranges::min(nums);
for(int e=ranges::min(nums); e<=mx;e++){




    int left=max(mn,e-k),right=min(mx,e+k);


    int f=freq[e]-freq[e-1];

    int num_ele=min(numOperations,freq[right]-freq[left-1]-f);
    ans=max(ans,num_ele+f);

}


return ans;






    }
};